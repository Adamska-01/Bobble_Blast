#pragma once
#include "Components/TileMap/TileMapRenderer.h"
#include "TileEditors/Tiled/Models/TiledMap.h"


class TiledMapCompatibleRenderer : public TileMapRenderer<std::shared_ptr<TiledMap>>
{
private:
	std::unordered_map<int, int> tileIDToTileSet;


public:
	TiledMapCompatibleRenderer(std::shared_ptr<TiledMap> tileMap, bool extendMapToRenderTarget = false);


	virtual void Init() override;

	virtual void Start() override;

	virtual void Update(float dt) override;

	virtual void Draw() override;
};