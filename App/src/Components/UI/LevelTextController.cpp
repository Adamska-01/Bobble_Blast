#include "Components/GameFlow/GameManager.h"
#include "Components/Transform.h"
#include "Components/UI/LevelTextController.h"
#include "Components/UI/TextMesh.h"
#include "GameObject.h"
#include "Tools/Helpers/Coroutines/CoroutineHelpers.h"
#include <Constants/AssetPaths.h>
#include <Management/SceneManager.h>
#include <Prefabs/AudioClipObject.h>
#include <SubSystems/Renderer.h>
#include <Tools/Helpers/Guards.h>


LevelTextController::LevelTextController()
	: textMesh(nullptr),
	gameManager(nullptr)
{
}

void LevelTextController::Init()
{
	textMesh = OwningObject.lock()->GetComponent<TextMesh>();
	gameManager = SceneManager::FindObjectOfType<GameManager>();

	Tools::Helpers::GuardAgainstNull(textMesh, "StartLevelText component needs a TextMesh component to function.");
	Tools::Helpers::GuardAgainstNull(gameManager, "StartLevelText component needs a GameManager component to function.");
}

void LevelTextController::Start()
{

}

void LevelTextController::Update(float deltaTime)
{

}

void LevelTextController::Draw()
{

}

Task LevelTextController::DisplayLevelText(std::string text)
{
	OwningObject.lock()->SetActive(true);
	textMesh->SetIsCentered(true);

	auto PlayCountdownStep = [&](std::string suffix, float delay) -> WaitForSeconds&
		{
			textMesh->SetText(text + "\n" + suffix);

			auto soundSourceObj = GameObject::Instantiate<AudioClipObject>(
				AssetPaths::Files::COUNTDOWN,
				Vector2F::Zero,
				0.4f,
				true);

			CoroutineScheduler::StartCoroutine(soundSourceObj.lock()->Destroy(1.0f));

			return Tools::Helpers::Coroutines::WaitSeconds(delay);
		};

	co_await PlayCountdownStep("3", 0.75f);
	co_await PlayCountdownStep("2", 0.75f);
	co_await PlayCountdownStep("1", 0.75f);
	co_await PlayCountdownStep("GO!", 0.5f);

	OwningObject.lock()->SetActive(false);
}

Task LevelTextController::DisplayEndLevelText(std::string text)
{
	auto currentPos = OwningObject.lock()->GetTransform()->GetWorldPosition();
	auto renderTargetSize = Renderer::GetResolutionTarget();

	OwningObject.lock()->GetTransform()->SetWorldPosition(Vector2F(renderTargetSize.x * 0.5f, renderTargetSize.y * 0.5f));

	co_await Tools::Helpers::Coroutines::WaitSeconds(1.0f);

	OwningObject.lock()->SetActive(true);

	textMesh->SetIsCentered(true);

	textMesh->SetText(text);

	co_await Tools::Helpers::Coroutines::WaitSeconds(2.0f);

	OwningObject.lock()->SetActive(false);

	OwningObject.lock()->GetTransform()->SetWorldPosition(currentPos);
}