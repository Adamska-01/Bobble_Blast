#pragma once
#include "Generic/SpriteAnimationProperties.h"
#include <Components/GameComponent.h>
#include <memory>


class Transform;
class Sprite;


class SpriteAnimator : public GameComponent
{
protected:
	bool started;

	float spriteFrame;

	SpriteAnimationProperties animationProperties;

	std::shared_ptr<SDL_Texture> spriteTexture;

	Transform* transform;

	Sprite* sprite;


public:
	SpriteAnimator();

	
	virtual void Init() override;
	
	virtual void Update(float dt) override;
	
	virtual void Draw() override;


	void SetProp(bool p_repeat, int Row, int p_FrameCount, int Row_Count, int p_speed, SDL_RendererFlip p_flip = SDL_FLIP_NONE);
	
	SDL_Rect GetFrameRect();
	
	const SpriteAnimationProperties& GetProp();
};