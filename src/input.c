#include "my.h"

int input_handler(Entity *entity) {
    SDL_Event event;

    SDL_PollEvent (&event);
    switch (event.type) {
        case SDL_QUIT :
            return -1;
        case SDL_KEYDOWN :
            switch (event.key.keysym.sym) {
            case SDLK_UP :
                if (entity->pos_y > 0)
                    entity->pos_y -= 6;
                break;
            case SDLK_DOWN :
                if (entity->pos_y < 310)
                    entity->pos_y += 6;
                break;
            default :
                break;
            }
        default:
            break;
    }
    return 0;
}
