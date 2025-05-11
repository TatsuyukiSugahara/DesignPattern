#include "AdvancedMediaPlayer.h"
#include <iostream>
class Mp4Player : public AdvancedMediaPlayer {
public:
    void playVlc(std::string fileName) override { }
    void playMp4(std::string fileName) override {
        std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
    }
};
