#include "Components/Sprite.h"
#include "Components/SpriteAnimator.h"
#include "Components/Transform.h"
#include "GameObject.h"
#include "Math/Vector2.h"
#include "SubSystems/TextureManager.h"


SpriteAnimator::SpriteAnimator()
{
	started = false;
	started = 0;
	animationProperties = SpriteAnimationProperties();
	spriteTexture = nullptr;
	transform = nullptr;
	sprite = nullptr;
}

void SpriteAnimator::Init()
{
	transform = OwningObject->GetComponent<Transform>();
	sprite = OwningObject->GetComponent<Sprite>();

	if (sprite == nullptr)
		return;

	sprite->SetActive(false);
}

void SpriteAnimator::Update(float dt)
{
	spriteTexture = sprite->GetTexture();

	if (!spriteTexture) 
		return;

	// Increment sprite frame
	spriteFrame += animationProperties.animSpeed * dt;

	if (spriteFrame >= animationProperties.columnCount)
	{
		spriteFrame = 0;

		// Reset started for non-repeating animations
		if (!animationProperties.loop)
		{
			started = false;
		}
	}
	else if (!animationProperties.loop && !started)
	{
		started = true;
	}
}

void SpriteAnimator::Draw()
{
	auto dstRect = GetFrameRect();

	dstRect.x = round(transform->position.x - ((float)dstRect.w * transform->scale.x) / 2);
	dstRect.y = round(transform->position.y - ((float)dstRect.h * transform->scale.y) / 2);

	auto srcRect = SDL_Rect
	{
		dstRect.w * (int)spriteFrame,
		dstRect.h * animationProperties.sourceRowNumber,
		dstRect.w,
		dstRect.h
	};

	dstRect.w *= transform->scale.x;
	dstRect.h *= transform->scale.y;

	TextureManager::DrawTexture(spriteTexture, &srcRect, &dstRect, 0.0f, NULL, animationProperties.flip);
}

void SpriteAnimator::SetProp(bool repeat, int row, int frameCount, int rowCount, int speed, SDL_RendererFlip flip)
{
	animationProperties.loop = repeat;
	animationProperties.sourceRowNumber = row;
	animationProperties.columnCount = frameCount;
	animationProperties.rowCount = rowCount;
	animationProperties.animSpeed = speed;
	animationProperties.flip = flip;

	spriteFrame = 0;
	started = false;
}

SDL_Rect SpriteAnimator::GetFrameRect()
{
	SDL_Rect srcRect;
	SDL_QueryTexture(sprite->GetTexture().get(), NULL, NULL, &srcRect.w, &srcRect.h);

	//Get the size of a single frame in a sprite sheet
	srcRect.w = static_cast<int>(round((float)srcRect.w / animationProperties.columnCount));
	srcRect.h = static_cast<int>(round((float)srcRect.h / animationProperties.rowCount));

	return srcRect;
}

const SpriteAnimationProperties& SpriteAnimator::GetProp()
{
	return animationProperties;
}