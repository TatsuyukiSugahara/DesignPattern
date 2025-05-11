#pragma once
#include <string>
class AdvancedMediaPlayer {
public:
    virtual void playVlc(std::string fileName) = 0;
    virtual void playMp4(std::string fileName) = 0;
    virtual ~AdvancedMediaPlayer() {}
};
