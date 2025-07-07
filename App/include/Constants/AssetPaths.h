#pragma once
#include "Tools/FileSystem/ResolvedPath.h"
#include "Tools/FileSystem/ResourceMount.h"
#include <string_view>


namespace AssetPaths
{
	namespace Folders
	{
		inline static const ResourceMount MAPS{ "maps", "App/Assets/Maps/" };

		inline static const ResourceMount LEVELS{ "levels", "App/Assets/Levels/" };

		inline static const ResourceMount BACKGROUNDS{ "backgrounds", "App/Assets/Backgrounds/" };

		inline static const ResourceMount SPRITES{ "sprites", "App/Assets/Sprites/" };

		inline static const ResourceMount BUTTON_SPRITES{ "button_sprites", "App/Assets/Sprites/Buttons" };

		inline static const ResourceMount APP_FONTS{ "app_fonts", "App/Assets/Fonts/" };

		inline static const ResourceMount APP_AUDIO{ "app_audio", "App/Assets/Audio/" };
	}


	namespace Files
	{
		// Maps
		inline const ResolvedPath SINGLEPLAYER_MAP_PATH = { Folders::MAPS.alias, "SingleplayerMap.tmx" };

		inline const ResolvedPath MULTIPLAYER_MAP_PATH = { Folders::MAPS.alias, "MultiplayerMap.tmx" };


		// Backgrounds
		inline const ResolvedPath BACKGROUND_IMAGE_PATH = { Folders::BACKGROUNDS.alias, "Stars.png" };


		// Sprites
		inline const ResolvedPath MAP_TILES_PATH = { Folders::SPRITES.alias, "MapTiles.png" };

		inline const ResolvedPath TITLE_IMAGE_PATH = { Folders::SPRITES.alias, "Title.png" };

		inline const ResolvedPath ARROW_IMAGE_PATH = { Folders::SPRITES.alias, "Arrow.png" };

		inline const ResolvedPath IDLE_BOBBLE_PATH = { Folders::SPRITES.alias, "IdleBobbles.png" };

		inline const ResolvedPath POP_BOBBLE_PATH = { Folders::SPRITES.alias, "BlowBobbles.png" };

		inline const ResolvedPath BUTTON_IDLE_IMAGE_PATH = { Folders::BUTTON_SPRITES.alias, "Button_Idle.png" };

		inline const ResolvedPath BUTTON_HOVERED_IMAGE_PATH = { Folders::BUTTON_SPRITES.alias, "Button_Hovered.png" };

		inline const ResolvedPath BUTTON_PRESSED_IMAGE_PATH = { Folders::BUTTON_SPRITES.alias, "Button_Pressed.png" };


		// Fonts
		inline const ResolvedPath THE_BLAST_FONT_PATH = { Folders::APP_FONTS.alias, "The Blast.otf" };


		// Audio
		inline const ResolvedPath MENU_MUSIC = { Folders::APP_AUDIO.alias, "AIr Room.wav" };

		inline const ResolvedPath GAME_MUSIC = { Folders::APP_AUDIO.alias, "Blazer Rail 2.wav" };

		inline const ResolvedPath GAMEOVER_MUSIC = { Folders::APP_AUDIO.alias, "GameOver.mp3" };

		inline const ResolvedPath VICTORY_MUSIC = { Folders::APP_AUDIO.alias, "orchestral-win.mp3" };

		inline const ResolvedPath BOBBLE_SHOT = { Folders::APP_AUDIO.alias, "bubble-shot.wav" };

		inline const ResolvedPath BOBBLE_POP = { Folders::APP_AUDIO.alias, "Bubble Blow.wav" };

		inline const ResolvedPath COUNTDOWN = { Folders::APP_AUDIO.alias, "CountDown.ogg" };
	}
}