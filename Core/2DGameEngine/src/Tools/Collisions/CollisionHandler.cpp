#include "Components/Collisions/BoxCollider2D.h"
#include "Components/Collisions/CircleCollider2D.h"
#include "Components/Collisions/Tile/Tiled/TiledMapCompatibleCollider2D.h"
#include "Tools/Collisions/CollisionHandler.h"



bool CollisionHandler::PointInCircle(const Vector2F& point, const CircleCollider2D& collider)
{
	auto circle = collider.GetCircle();

	auto dx = point.x - circle.position.x;
	auto dy = point.y - circle.position.y;

	return (dx * dx + dy * dy) <= (circle.radius * circle.radius);
}

bool CollisionHandler::Visit(const BoxCollider2D* box, const BoxCollider2D* other)
{
	auto A = box->GetCollisionBox();
	auto B = other->GetCollisionBox();

	// Sides of the rectangle 
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	// Sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	// Sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	// Check collisions
	if (bottomA <= topB)
		return false;
	if (topA >= bottomB)
		return false;
	if (rightA <= leftB)
		return false;
	if (leftA >= rightB)
		return false;

	// Collision happened
	return true;
}

bool CollisionHandler::Visit(const BoxCollider2D* box, const CircleCollider2D* other)
{
	auto A = other->GetCircle();
	auto B = box->GetCollisionBox();

	// Closest points on collision box
	Vector2F closestPoint;

	// Find closest x offset
	if (A.position.x < B.x)
		closestPoint.x = B.x;
	else if (A.position.x > B.x + B.w)
		closestPoint.x = B.x + B.w;
	else
		closestPoint.x = A.position.x;

	// Find closest y offset
	if (A.position.y < B.y)
		closestPoint.y = B.y;
	else if (A.position.y > B.y + B.h)
		closestPoint.y = B.y + B.h;
	else
		closestPoint.y = A.position.y;

	//collisionPoint = closestPoint;

	// Check if the point is inside the circle
	if (A.position.Distance(closestPoint) < A.radius)
		return true;

	// No collision
	return false;
}

bool CollisionHandler::Visit(const BoxCollider2D* box, const TiledMapCompatibleCollider2D* other)
{
	auto colliderRect = box->GetCollisionBox();
	const auto& collisionLayers = other->GetCollisionLayers();
	const auto& tilesize = other->GetTileSize();
	const auto& tileMapDimension = other->GetTileMapDimensions();

	auto left_tile = colliderRect.x / tilesize;
	auto right_tile = (colliderRect.x + colliderRect.w) / tilesize;

	auto top_tile = colliderRect.y / tilesize;
	auto bottom_tile = (colliderRect.y + colliderRect.h) / tilesize;

	if (top_tile < 0)
		top_tile = 0;

	if (right_tile > tileMapDimension.x)
		right_tile = tileMapDimension.x;

	if (top_tile < 0)
		top_tile = 0;

	if (bottom_tile > tileMapDimension.y)
		bottom_tile = tileMapDimension.y;

	for (auto i = left_tile; i <= right_tile; i++)
	{
		for (auto j = top_tile; j <= bottom_tile; j++)
		{
			auto withinBounds = i >= 0 && i < tileMapDimension.x && j >= 0 && j < tileMapDimension.y;
			
			if (!withinBounds)
				continue;

			auto isSolidTile = false;
		
			for (const auto& layer : collisionLayers)
			{
				isSolidTile = layer.Data[j][i] > 0;

				if (isSolidTile)
					break;
			}

			if (isSolidTile)
				return true;
		}
	}

	return false;
}

bool CollisionHandler::Visit(const CircleCollider2D* circle, const BoxCollider2D* other)
{
	return Visit(other, circle);
}

bool CollisionHandler::Visit(const CircleCollider2D* circle, const CircleCollider2D* other)
{
	auto A = circle->GetCircle();
	auto B = other->GetCircle();

	// Check if the point is touching the circle
	if (A.position.Distance(B.position) <= A.radius + B.radius)
		return true;

	// No collision
	return false;
}

bool CollisionHandler::Visit(const CircleCollider2D* circle, const TiledMapCompatibleCollider2D* other)
{
	auto collisionLayers = other->GetCollisionLayers();
	auto colliderCircle = circle->GetCircle();
	auto circleCenter = colliderCircle.position;
	auto circleRadius = colliderCircle.radius;

	// Replace these with the real values
	auto tilesize = 32;
	auto rowCount = 20;
	auto colCount = 60;

	// We need to iterate over the tiles within the circle's radius
	// Find the bounding box of the circle in terms of tiles (like how we did for the BoxCollider2D)
	int left_tile = (circleCenter.x - circleRadius) / tilesize;
	int right_tile = (circleCenter.x + circleRadius) / tilesize;
	int top_tile = (circleCenter.y - circleRadius) / tilesize;
	int bottom_tile = (circleCenter.y + circleRadius) / tilesize;

	// Clamping to bounds
	if (left_tile < 0) left_tile = 0;
	if (right_tile > colCount) right_tile = colCount;
	if (top_tile < 0) top_tile = 0;
	if (bottom_tile > rowCount) bottom_tile = rowCount;

	// Check all tiles within the circle's bounding box
	for (auto i = left_tile; i <= right_tile; i++)
	{
		for (auto j = top_tile; j <= bottom_tile; j++)
		{
			// Check if the tile is within the circle's area
			auto withinBounds = i >= 0 && i < colCount && j >= 0 && j < rowCount;

			if (withinBounds)
			{
				// Get the tile center position
				Vector2F tileCenter(i * tilesize + tilesize / 2, j * tilesize + tilesize / 2);

				// Check if the tile's center is within the circle's radius
				auto dx = tileCenter.x - circleCenter.x;
				auto dy = tileCenter.y - circleCenter.y;
				auto distanceSquared = dx * dx + dy * dy;

				std::cout << "Distance Squared: " << distanceSquared << std::endl;

				if (distanceSquared <= circleRadius * circleRadius)
				{
					// If the tile is within the circle's radius, check if it's a solid tile
					auto isSolidTile = false;
					for (const auto& layer : collisionLayers)
					{
						isSolidTile = layer.Data[j][i] > 0;
						
						if (isSolidTile) 
							break;
					}

					if (isSolidTile)
						return true;
				}
			}
		}
	}

	return false;
}

bool CollisionHandler::Visit(const TiledMapCompatibleCollider2D* tile, const BoxCollider2D* other)
{
	return Visit(other, tile);
}

bool CollisionHandler::Visit(const TiledMapCompatibleCollider2D* tile, const CircleCollider2D* other)
{
	return Visit(other, tile);
}