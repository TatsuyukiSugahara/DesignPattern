#pragma once
#include <string>
class MediaPlayer {
public:
    virtual void play(std::string audioType, std::string fileName) = 0;
    virtual ~MediaPlayer() {}
};
