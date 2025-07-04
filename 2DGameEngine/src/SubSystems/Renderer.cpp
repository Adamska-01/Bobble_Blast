#include "Debugging/Debug.h"
#include "EventSystem/EventDispatcher.h"
#include "EventSystem/Events/SubSystems/Renderer/RenderTargetSizeChangedEvent.h"
#include "SubSystems/Renderer.h"
#include "SubSystems/Window.h"
#include <SDL.h>


SDL_Renderer* Renderer::renderer = nullptr;


Renderer::Renderer(SDL_Window* window, RendererConfig config)
{
#if _DEBUG
	DBG_ASSERT_MSG(window, "Window initialisation failed: %s\n", SDL_GetError());
#endif

	//startup
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Failed to Initialize SDL_VIDEO: " << SDL_GetError() << std::endl;
	}

	//create the renderer
	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED);

#if _DEBUG
	DBG_ASSERT_MSG(renderer, "Renderer initialisation failed: %s\n", SDL_GetError());
#endif

	SetResolutionTarget({ config.width, config.height });

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	std::cout << "[Info] SDL_VIDEO successfully initialized." << std::endl;
}

Renderer::~Renderer()
{
	if (renderer == nullptr) 
	{
		std::cout << "[Info] Renderer is already null, no need to destroy." << std::endl;
	
		return;
	}

	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	std::cout << "[Info] Renderer successfully destroyed and SDL_VIDEO successfully quit." << std::endl;
}

void Renderer::Update(float deltaTime)
{

}

void Renderer::BeginFrame()
{

}

void Renderer::EndUpdate()
{

}

void Renderer::EndDraw()
{

}

void Renderer::ClearBuffer()
{
	SDL_RenderClear(renderer);
}

void Renderer::PresentBuffer()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::GetRenderer()
{
	return renderer;
}

SDL_Color Renderer::GetDisplayColor()
{
	Uint8 r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

	return SDL_Color(r, g, b, a);
}

Vector2I Renderer::GetResolutionTarget()
{
	int width = 0;
	int height = 0;

	if (renderer != nullptr)
	{
		SDL_RenderGetLogicalSize(renderer, &width, &height);
	}

	return Vector2I(width, height);
}

void Renderer::SetDisplayColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if (renderer == nullptr)
		return;

	//set background color
	auto result = SDL_SetRenderDrawColor(
		renderer,
		r,
		g,
		b,
		a);

#if _DEBUG
	DBG_ASSERT_MSG(!result, "Background color initialisation failed: %s\n", SDL_GetError());
#endif
}

void Renderer::SetResolutionTarget(Vector2I targetResolution)
{
	auto width = targetResolution.x;
	auto height = targetResolution.y;

	if (width <= 0 || height <= 0)
		return;

	SDL_RenderSetLogicalSize(renderer, width, height);

	EventDispatcher::SendEvent(std::make_shared<RenderTargetSizeChangedEvent>(Vector2I(width, height)));
}