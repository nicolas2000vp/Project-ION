#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* screen):screen(screen){
    map = NULL;
    BITMAP* img_jack = load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/jack_1.bmp", NULL);
    if(img_jack == NULL)
        cout << "erro carregando" << endl;
    std::vector<BITMAP*> *jacks = new std::vector<BITMAP*>;
    jacks->push_back(img_jack);
    jack = new Human("Jack", 0, 0, 0.2, 0.2, jacks);
    characters.push_back(static_cast<Character*>(jack));
}

void Level::setMap(Map* map){
    this->map = map;
}

Map* Level::getMap(){
    return map;
}

/*This function print the background of the level. Returns 0 case success and 1 case fails*/
int Level::printMap(){
    if(map == NULL){ //tests if map exists
        cout << "Mapa não existe" << endl;
        return 1;
    }

    BITMAP *stone_1 = load_bitmap("/home/otavio/Documentos/Project_ION/Material/Scenario/stone_1.bmp", NULL);
    int* matrix = map->getMatrix();
    int j = 0;
    int h = 0;
    for(int i = 0; i < 36*24; i++){
        if(j == 36){
            j = 0;
            h++;
        }
        if(matrix[i] == 0)
            blit(stone_1, screen, 0, 0, 30*j, 30*h, 30, 30);
        j++;
    }
}

//Update all the positions of the characters placed in the level.
void Level::updatePosition(){
    vector<Character*>::iterator itr = characters.begin();
    for(itr; itr != characters.end(); itr++){
        (*itr)->printCharacter(screen);
    }
}

int Level::getValueMap(int i, int j){
    return map->getValueMap(i, j);
}

Human* Level::getJack(){
    return jack;
}

Level::~Level()
{
    std::vector<Character*>::iterator itr = characters.begin();
    for(itr; itr != characters.end(); itr++)
        delete *itr;
    characters.clear();
}
