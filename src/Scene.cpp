#include "Scene.hpp"

Scene::Scene(Game &game)
{
    this->game = &game;
}
Scene::~Scene() = default;