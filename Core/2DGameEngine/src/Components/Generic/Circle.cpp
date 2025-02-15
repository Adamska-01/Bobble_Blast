#include "Components/Generic/Circle.h"
#include "Math/MathConstants.h"
#include "Math/Vector2.h"


Circle::Circle()
	: position(Vector2F::Zero), radius(1.0f)
{
}

Circle::Circle(const Vector2F& pos, float r) 
	: position(pos), radius(r) 
{
}

float Circle::Area() const 
{
	return MathConstants::PI * radius * radius;
}

float Circle::Circumference() const 
{
	return 2.0f * MathConstants::PI * radius;
}