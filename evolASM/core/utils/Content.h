#pragma once

#include <unordered_map>
#include <string>
#include <sfml.h>

/// <summary>
/// Load game content (textures, fonts, sounds and etc.)
/// </summary>
class Content final
{
	Content();
	Content(const Content&) = delete;
	void operator=(const Content&) = delete;

	bool _isLoaded;
public:
	~Content();

	void load();

	static Content& getInstance()
	{
		static Content instance;
		return instance;
	}

	std::unordered_map<std::string, sf::Texture*> Textures;
	std::unordered_map<std::string, sf::SoundBuffer*> Sounds;
	std::unordered_map<std::string, sf::Music*> Musics;
	std::unordered_map<std::string, sf::Font*> Fonts;
};