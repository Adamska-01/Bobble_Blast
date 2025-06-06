#pragma once
#include "Math/Vector2.h"
#include "GameComponent.h"


class Transform : public GameComponent
{
private:
	Vector2F startFramePosition;


public:
	Transform(Vector2F position = Vector2F::Zero, Vector2F scale = Vector2F::One, float angle = 0.0f);

	Transform(Transform&& other) = default;

	~Transform() override;


	Vector2F position;

	Vector2F scale;
	
	float angle;


	void TranslateX(float x);
	
	void TranslateY(float y);
	
	void Translate(Vector2F v);

	void ScaleX(float x);
	
	void ScaleY(float y);
	
	void Scale(Vector2F v);

	void RotateByRadians(float radian);

	void RotateByDegrees(float degreeAngle);


	void Init() override;

	void Update(float dt) override;

	void Draw() override;


	Vector2F GetStartFramePosition() const;

	
	inline void Log(std::string msg = "") const
	{
		std::cout << msg << "(X Y) = (" << position.x << " " << position.y << ")" << std::endl;
	}
};