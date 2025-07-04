#pragma once
#include "Components/GameComponent.h"
#include "Data/UI/LayoutPadding.h"
#include <memory>


class DispatchableEvent;
class UIComponent;


class LayoutGroup : public GameComponent
{
private:
	void GameObjectCreatedHandler(std::shared_ptr<DispatchableEvent> dispatchableEvent);

	void GameObjectDestroyedHandler(std::shared_ptr<DispatchableEvent> dispatchableEvent);


protected:
	float layoutSpacing;

	LayoutPadding layoutPadding;

	
	virtual void OnGameObjectActiveStateChangedHandler(GameObject* child, bool activeState) override;


public:
	LayoutGroup(float layoutSpacing, LayoutPadding layoutPadding);

	virtual ~LayoutGroup() override;


	virtual void Init() override;

	virtual void Start() override;

	virtual void Update(float deltaTime) override;

	virtual void Draw() override;


	virtual void UpdateLayout();
};