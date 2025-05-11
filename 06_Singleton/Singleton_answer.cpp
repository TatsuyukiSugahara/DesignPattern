
#include <iostream>
#include <string>
using namespace std;

// GameSettings Singleton
class GameSettings {
private:
    static GameSettings* instance;
    int volume;
    GameSettings() : volume(100) {}
public:
    static GameSettings* getInstance() {
        if (!instance) instance = new GameSettings();
        return instance;
    }
    void setVolume(int v) { volume = v; }
    int getVolume() const { return volume; }
};
GameSettings* GameSettings::instance = nullptr;

// Logger Singleton
class Logger {
private:
    static Logger* instance;
    Logger() {}
public:
    static Logger* getInstance() {
        if (!instance) instance = new Logger();
        return instance;
    }
    void log(const string& message) {
        cout << "[LOG]: " << message << endl;
    }
};
Logger* Logger::instance = nullptr;

// SoundManager Singleton
class SoundManager {
private:
    static SoundManager* instance;
    SoundManager() {}
public:
    static SoundManager* getInstance() {
        if (!instance) instance = new SoundManager();
        return instance;
    }
    void playBGM() {
        int vol = GameSettings::getInstance()->getVolume();
        cout << "音量" << vol << "でBGMを再生中..." << endl;
    }
    void stopBGM() {
        cout << "BGMを停止しました。" << endl;
    }
};
SoundManager* SoundManager::instance = nullptr;

int main() {
    GameSettings::getInstance()->setVolume(80);
    SoundManager::getInstance()->playBGM();
    Logger::getInstance()->log("BGM再生を開始しました。");

    SoundManager::getInstance()->stopBGM();
    Logger::getInstance()->log("BGMを停止しました。");

    return 0;
}
