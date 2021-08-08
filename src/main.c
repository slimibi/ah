#include <stdio.h>
#include "my.h"


void init_struct_p(Entity *player, Win *app, Entity *kamikaze)
{
    player->pos_x = 100;
    player->pos_y = 100;
    player->width = 50;
    player->height = 50;
    player->texture = loadTexture(app, "ressource/alien.png");
    kamikaze->pos_x = 480;
    kamikaze->pos_y = 100;
    kamikaze->width = 50;
    kamikaze->height = 50;
    kamikaze->texture = loadTexture(app, "ressource/ah.png");
}

void handle_kamikaze(Entity *kamikaze)
{
    kamikaze->pos_x -= 4;
    if (kamikaze->pos_x <= -50)
        kamikaze->pos_x = 460;
}

int initSDL (Win *app)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        return -1;
    }
    app->window = SDL_CreateWindow(WINDOW_NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 
        WINDOW_WIDTH,
        WINDOW_HEIGHT, 0);
    if  (!app->window) {
        printf("Failed to open window %d x %d windows : %s\n",
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_GetError());
        return -1;
    }
    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (!app->renderer)
        printf("Failed to create renderer: %s\n",SDL_GetError());
    return 0;
}

int main ()
{
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *kamikaze = malloc(sizeof(Entity));

    if (initSDL(app) < 0)
        return -1;
    init_struct_p(player, app, kamikaze);
    while (input_handler(player) == 0) {
        prepareCanvas(app);
        handle_kamikaze(kamikaze);
        drawEntity(app, player, kamikaze);
        presentCanvas(app);
        SDL_Delay(16);
    }
    return 0;
}
