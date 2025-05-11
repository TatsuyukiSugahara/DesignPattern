#include "AdvancedMediaPlayer.h"
#include <iostream>
class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(std::string fileName) override {
        std::cout << "Playing vlc file. Name: " << fileName << std::endl;
    }
    void playMp4(std::string fileName) override { }
};
