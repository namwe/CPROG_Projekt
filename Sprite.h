
#include <SDL2/SDL.h>
#include "System.h"

#ifndef CPROG_PROJEKT_SPRITE_H
#define CPROG_PROJEKT_SPRITE_H


class Sprite {
private:
    SDL_Rect rekt;
    Sprite(const Sprite &) = delete;
    const Sprite &operator=(const Sprite &) = delete;

protected:
    SDL_Texture *sdlTexture;
    Sprite(int x, int y, int w, int h, const char *path);

public:
    virtual ~Sprite();
    SDL_Rect &get_rekt();
    virtual void draw();
    bool collision(const Sprite *);
};


#endif //CPROG_PROJEKT_SPRITE_H
