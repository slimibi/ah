#include "my.h"


void prepareCanvas(Win *app)
{
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
}

void presentCanvas(Win *app)
{
    SDL_RenderPresent(app->renderer);
}

SDL_Texture *loadTexture(Win *app, char *path)
{
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading: %s", path);
    texture = IMG_LoadTexture(app->renderer, path);
    if(texture == NULL)
        printf("load texture fail %s\n", IMG_GetError());
    return texture;
}

void drawEntity(Win *win, Entity *entity, Entity *enemy)
{
    SDL_Rect dest = {entity->pos_x, entity->pos_y, entity->width, entity->height};
    SDL_Rect dest_e = {enemy->pos_x, enemy->pos_y, enemy->width, enemy->height};

    if(SDL_HasIntersection(&dest, &dest_e))
        exit (0);
    SDL_RenderCopy(win->renderer, entity->texture, NULL, &dest);
    SDL_RenderCopy(win->renderer, enemy->texture, NULL, &dest_e);
}
