#include "Scene.hpp"
#include "engine/engine.hpp"


class GameOver : public Scene
{
    
public:
    GameOver(Game &game);
    void handle_event(Event &event);
    void update();
    void draw();
};