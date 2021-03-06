#include "Player.h"
#include "GameEngine.h"

Player::Player(int x, int y, int w, int h, const char *path = engine.gameParams.playerSpritePath) : Sprite(x, y, w, h,
                                                                                                           path) {}

void Player::key_pressed(SDL_Event eve) {
    switch (eve.key.keysym.sym) {
        case SDLK_LEFT:
            if (this->get_rekt().x > 0) {
                this->get_rekt().x -= engine.gameParams.playerSpeed;
            }
            break;
        case SDLK_RIGHT:
            if (this->get_rekt().x < engine.gameParams.windowWidth - engine.gameParams.playerWidth) {
                this->get_rekt().x += engine.gameParams.playerSpeed;
            }
            break;
        case SDLK_SPACE:
            if (bulletDelay == 0) {
                engine.addSprite(shoot());
                bulletDelay = engine.gameParams.bulletDelay;
            }
            break;
    }
}

Player *Player::getInstance(int x, int y, int w, int h) {
    return new Player(x, y, w, h);
}

void Player::tick() {
    if (bulletDelay != 0) {
        bulletDelay--;
    }
}

Bullet *Player::shoot() {
    Bullet *b = Bullet::getInstance(this->get_rekt().x + engine.gameParams.bulletOffsetX,
                                    this->get_rekt().y + engine.gameParams.bulletOffsetY);
    return b;
}




