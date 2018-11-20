#include "Game.h"

Game::Game()
{
    images = new Images_Library;
    levels = new List_Levels;
    menu1 = new Menu(buffer);
}

Game::~Game()
{
    delete images;
    images = NULL;
    buffer = NULL;
    current = NULL;
}
