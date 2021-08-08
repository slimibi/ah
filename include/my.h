#ifndef _MY_H_
# define _MY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 360
#define WINDOW_NAME "DVC"


typedef struct 
{
    SDL_Renderer    *renderer;
    SDL_Window      *window;
} Win;

typedef struct
{
    int pos_x;
    int pos_y;
    int width;
    int height;
    SDL_Texture *texture;
} Entity;

int input_handler(Entity *);
void drawEntity(Win *win, Entity *entity, Entity *);
SDL_Texture *loadTexture(Win *app, char *path);
void presentCanvas(Win *app);
void prepareCanvas(Win *app);

#endif /* _MY_H_ */
