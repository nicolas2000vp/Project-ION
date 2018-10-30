#ifndef LEVEL_H
#define LEVEL_H
#include <allegro.h>
#include <cstddef> //library for NULL
#include <iostream>
#include <vector>
#include "Map.h"
#include "Character.h"
#include "Human.h"
#include "List_Images.h"
#include "Entity.h"
#include "List_Entities.h"
#include "Images.h"
using std::cout;
using std::endl;

class Level
{
public:
    Level();
    Level(BITMAP* buffer, Images *images);
    ~Level();
    Map* getMap();
    void printMap();
    void updatePosition();
    int getValueMap(int i, int j);
    int isCollide(Entity* a, Entity* b);
    void loopEntities();
    virtual void gameLoop() = 0;
protected:
    Map* map; //Pointer to the level map.
    BITMAP* buffer; //Pointer to the display where all components will be shown.
    Human* jack;
    List_Entities* entities;
    Images* images;
};

#endif // LEVEL_H
