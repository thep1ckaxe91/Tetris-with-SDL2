#include "Animation.hpp"
using namespace std;
Animation::Animation(Game &game,int frame_rate, bool loop)
{
    this->frame_rate = frame_rate;
    this->loop = loop;
    this->playing = 0;
    this->frame_id=0;
    this->game = &game;
}
Animation::Animation()
{
    this->game = nullptr;
    this->frame_rate = 60;
    this->loop = 0;
    this->playing = 0;
    this->frame_id=0;
}
/**
 * @brief load the animation's images in folder 'path'
 * 
 * @param path the path to the folder the contain only images of the animation
 */
void Animation::load(string path)
{
    this->frames.clear();
    for(const auto& entry : filesystem::directory_iterator(path))
    {
        frames.push_back(sdlgame::image::load(entry.path().string()));
    }
    if(this->default_img.texture == 0)
    {
        this->image = this->default_img = frames[0];
    }
}
void Animation::update()
{
    if(this->playing)
    {
        this->time_cnt += this->game->clock.delta_time();
        if(this->time_cnt >= 1/this->frame_rate)
        {
            this->time_cnt-= 1/this->frame_rate;
            if(frame_id>=frames.size())
            {
                frame_id=0;
                if(!(this->playing = this->loop))
                {
                    this->image = this->default_img;
                    playing = 0;
                    return;
                }
            }
            this->image = this->frames[frame_id];
            this->frame_id++;
        }
    }
}
void Animation::play()
{
    playing=1;
}
void Animation::pause()
{
    playing=0;
}
void Animation::reset()
{
    frame_id=0;
}
void Animation::set_default(const Surface oth)
{
    this->image = this->default_img = oth;
}