#include "Content.h"
#include <filesystem>
#include <core/utils/Logger.h>

static std::string getFilename(const std::string& filepath)
{
    std::string temp(filepath);
    temp = filepath.substr(filepath.find_last_of("/\\") + 1);
    std::string fileWithoutExt = temp.substr(0, temp.find_last_of('.'));

    return fileWithoutExt;
}

Content::Content()
    : _isLoaded(false)
{
}

Content::~Content()
{
    Logger::info("Delete all assets.");
    for (const auto& item : Textures) {
        delete item.second;
    }
    for (const auto& item : Sounds) {
        delete item.second;
    }
    for (const auto& item : Musics) {
        delete item.second;
    }
    for (const auto& item : Fonts) {
        delete item.second;
    }
}

void Content::load()
{// TODO: use template for loading

    if (_isLoaded)
        Logger::warn("Tried load game content more than once.");

    using namespace std;

    std::string texturesPath = "content/textures/";
    for (const auto& entry : filesystem::directory_iterator(texturesPath)) {
        string filepath = entry.path().string();

        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(filepath)) {
            throw std::exception();
        }

        const std::string filename = getFilename(filepath);
        Textures[filename] = texture;
        Logger::info("Load texture: " + filename);
    }

    std::string musicsPath = "content/musics/";
    for (const auto& entry : filesystem::directory_iterator(musicsPath)) {
        string filepath = entry.path().string();

        sf::Music* music = new sf::Music();
        if (!music->openFromFile(filepath)) {
            throw std::exception();
        }

        const std::string filename = getFilename(filepath);
        Musics[filename] = music;
        Logger::info("Load music: " + filename);
    }

    std::string fontsPath = "content/fonts/";
    for (const auto& entry : filesystem::directory_iterator(fontsPath)) {
        string filepath = entry.path().string();

        sf::Font* font = new sf::Font();
        if (!font->loadFromFile(filepath)) {
            throw std::exception();
        }

        const std::string filename = getFilename(filepath);
        Fonts[filename] = font;
        Logger::info("Load font: " + filename);
    }

    std::string soundsPath = "content/sounds/";
    for (const auto& entry : filesystem::directory_iterator(soundsPath)) {
        string filepath = entry.path().string();

        sf::SoundBuffer* sound = new sf::SoundBuffer();
        if (!sound->loadFromFile(filepath)) {
            throw std::exception();
        }

        const std::string filename = getFilename(filepath);
        Sounds[filename] = sound;
        Logger::info("Load sound: " + filename);
    }
}
