#ifndef CPROG_PROJEKT_GAMEENGINE_H
#define CPROG_PROJEKT_GAMEENGINE_H
#define FPS 60

#include <vector>
#include <algorithm>
#include "Player.h"
#include "Sprite.h"
#include "TargetSprite.h"


class GameEngine {
private:
    Player* player;
    std::vector<Sprite*> spriteList;
    std::vector<Sprite*> toRemoveList;
    std::vector<TargetSprite*> meteoriteList;
    bool bulletOnScreen = false;
    const int tickInterval = 1000 / FPS;
    Uint32 nextTick;
    int delay;
    bool existShip = true;

    void bulletCheck(Sprite *sprite);
    Sprite* collisionCheck(Sprite *sprite);
    void meteoriteSpawning();
    void meteoriteDeletion();
    void remove();
    void addSprite(Sprite*);

public:
    ~GameEngine();
    void run();

};

extern GameEngine engine;

#endif //CPROG_PROJEKT_GAMEENGINE_H
