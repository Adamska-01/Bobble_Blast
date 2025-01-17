#pragma once
#include "Math/Vector2.h"


struct BoxCollider2D;
struct CircleCollider2D;


class CollisionHandler
{
private:
	CollisionHandler() = default;

	~CollisionHandler() = default;

	CollisionHandler(const CollisionHandler&) = delete;

	CollisionHandler(CollisionHandler&&) = delete;


	CollisionHandler& operator=(const CollisionHandler&) = delete;

	CollisionHandler& operator=(CollisionHandler&&) = delete;


public:
	static bool BoxToBoxCollision(const BoxCollider2D& colliderA, const BoxCollider2D& colliderB);
	
	static bool CircleToBoxCollision(const CircleCollider2D& colliderA, const BoxCollider2D& colliderB, Vector2F& collisionPoint);
	
	static bool CircleToCircleCollision(const CircleCollider2D& colliderA, const CircleCollider2D& colliderB);

	static bool PointInCircle(const Vector2F& point, const CircleCollider2D& circle);
};