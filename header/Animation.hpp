#include "engine/engine.hpp"
// #include "bits/stdc++.h"
class Animation : public sdlgame::sprite::Sprite
{
protected:
    int frame_rate;
    std::vector<Surface> frames;
public:
    /**
     * @brief init an animation object
     * @param path path to the folder that only have file for the 
     * 
     */
    Animation(int frame_rate=60, bool loop=0);
    Animation();
    /**
     * @brief load the animation's images in folder 'path'
     * 
     * @param path the path to the folder the contain only images of the animation
     */
    void load(std::string path);
    void play();
    virtual void update() = 0;
    void pause();
    void reset();
};