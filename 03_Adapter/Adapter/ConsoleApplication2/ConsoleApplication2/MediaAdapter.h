#include "MediaPlayer.h"
#include "AdvancedMediaPlayer.h"
#include "VlcPlayer.h"
#include "Mp4Player.h"
#include <memory>
#include <string>
class MediaAdapter : public MediaPlayer {
private:
    std::unique_ptr<AdvancedMediaPlayer> advancedMusicPlayer;
public:
    MediaAdapter(std::string audioType) {
        if (audioType == "vlc") {
            advancedMusicPlayer = std::make_unique<VlcPlayer>();
        }
        else if (audioType == "mp4") {
            advancedMusicPlayer = std::make_unique<Mp4Player>();
        }
    }
    void play(std::string audioType, std::string fileName) override {
        if (audioType == "vlc") {
            advancedMusicPlayer->playVlc(fileName);
        }
        else if (audioType == "mp4") {
            advancedMusicPlayer->playMp4(fileName);
        }
    }
};
