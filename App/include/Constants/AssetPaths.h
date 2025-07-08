#pragma once
#include "Tools/FileSystem/ResolvedPath.h"
#include "Tools/FileSystem/ResourceMount.h"
#include <string_view>


namespace AssetPaths
{
	namespace Folders
	{
		// Keys
		inline constexpr std::string_view MAPS_ALIAS = "maps";

		inline constexpr std::string_view LEVELS_ALIAS = "levels";

		inline constexpr std::string_view BACKGROUNDS_ALIAS = "backgrounds";

		inline constexpr std::string_view SPRITES_ALIAS = "sprites";

		inline constexpr std::string_view BUTTON_SPRITES_ALIAS = "button_sprites";

		inline constexpr std::string_view APP_FONTS_ALIAS = "app_fonts";

		inline constexpr std::string_view APP_AUDIO_ALIAS = "app_audio";


		inline static const ResourceMount MAPS = { std::string(MAPS_ALIAS), "App/Assets/Maps/" };

		inline static const ResourceMount LEVELS = { std::string(LEVELS_ALIAS), "App/Assets/Levels/" };

		inline static const ResourceMount BACKGROUNDS = { std::string(BACKGROUNDS_ALIAS), "App/Assets/Backgrounds/" };

		inline static const ResourceMount SPRITES = { std::string(SPRITES_ALIAS), "App/Assets/Sprites/" };

		inline static const ResourceMount BUTTON_SPRITES = { std::string(BUTTON_SPRITES_ALIAS), "App/Assets/Sprites/Buttons" };

		inline static const ResourceMount APP_FONTS = { std::string(APP_FONTS_ALIAS), "App/Assets/Fonts/" };

		inline static const ResourceMount APP_AUDIO = { std::string(APP_AUDIO_ALIAS), "App/Assets/Audio/" };
	}


	namespace Files
	{
		// Maps
		inline const ResolvedPath SINGLEPLAYER_MAP_PATH = { std::string(Folders::MAPS_ALIAS), "SingleplayerMap.tmx" };
		
		inline const ResolvedPath MULTIPLAYER_MAP_PATH = { std::string(Folders::MAPS_ALIAS), "MultiplayerMap.tmx" };


		// Backgrounds
		inline const ResolvedPath BACKGROUND_IMAGE_PATH = { std::string(Folders::BACKGROUNDS_ALIAS), "Stars.png" };


		// Sprites
		inline const ResolvedPath MAP_TILES_PATH = { std::string(Folders::SPRITES_ALIAS), "MapTiles.png" };

		inline const ResolvedPath TITLE_IMAGE_PATH = { std::string(Folders::SPRITES_ALIAS), "Title.png" };

		inline const ResolvedPath ARROW_IMAGE_PATH = { std::string(Folders::SPRITES_ALIAS), "Arrow.png" };

		inline const ResolvedPath IDLE_BOBBLE_PATH = { std::string(Folders::SPRITES_ALIAS), "IdleBobbles.png" };

		inline const ResolvedPath POP_BOBBLE_PATH = { std::string(Folders::SPRITES_ALIAS), "BlowBobbles.png" };


		inline const ResolvedPath BUTTON_IDLE_IMAGE_PATH = { std::string(Folders::BUTTON_SPRITES_ALIAS), "Button_Idle.png" };

		inline const ResolvedPath BUTTON_HOVERED_IMAGE_PATH = { std::string(Folders::BUTTON_SPRITES_ALIAS), "Button_Hovered.png" };

		inline const ResolvedPath BUTTON_PRESSED_IMAGE_PATH = { std::string(Folders::BUTTON_SPRITES_ALIAS), "Button_Pressed.png" };


		// Fonts
		inline const ResolvedPath THE_BLAST_FONT_PATH = { std::string(Folders::APP_FONTS_ALIAS), "The Blast.otf" };


		// Audio
		inline const ResolvedPath MENU_MUSIC = { std::string(Folders::APP_AUDIO_ALIAS), "AIr Room.wav" };
		
		inline const ResolvedPath GAME_MUSIC = { std::string(Folders::APP_AUDIO_ALIAS), "Blazer Rail 2.wav" };
		
		inline const ResolvedPath GAMEOVER_MUSIC = { std::string(Folders::APP_AUDIO_ALIAS), "GameOver.mp3" };
		
		inline const ResolvedPath VICTORY_MUSIC = { std::string(Folders::APP_AUDIO_ALIAS), "orchestral-win.mp3" };
		
		inline const ResolvedPath BOBBLE_SHOT = { std::string(Folders::APP_AUDIO_ALIAS), "bubble-shot.wav" };
		
		inline const ResolvedPath BOBBLE_POP = { std::string(Folders::APP_AUDIO_ALIAS), "Bubble Blow.wav" };
		
		inline const ResolvedPath COUNTDOWN = { std::string(Folders::APP_AUDIO_ALIAS), "CountDown.ogg" };
	}
}