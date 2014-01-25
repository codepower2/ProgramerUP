#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

#include "functions.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *upMessage = NULL;
SDL_Surface *downMessage = NULL;
SDL_Surface *leftMessage = NULL;
SDL_Surface *rightMessage = NULL;
SDL_Surface *screen = NULL;

SDL_Event event;

TTF_Font *font = NULL;

SDL_Color textColor = {255, 255, 255};

bool init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return false;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
        return false;

    if (TTF_Init() == -1)
        return false;

    SDL_WM_SetCaption("Coding SDL", NULL);

    return true;
}

bool load_files()
{
    background = load_image("background.png");
    font = TTF_OpenFont("lazy.ttf", 28);

    if (background == NULL || font == NULL)
        return false;

    return true;
}

void clean_up()
{
    SDL_FreeSurface(background);
    SDL_FreeSurface(upMessage);
    SDL_FreeSurface(downMessage);
    SDL_FreeSurface(leftMessage);
    SDL_FreeSurface(rightMessage);
    SDL_FreeSurface(message);

    TTF_CloseFont(font);

    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char *args[])
{
    bool quit = false;

    if (!init())
        return 1;
    if (!load_files())
        return 1;

    upMessage = TTF_RenderText_Solid(font, "Up was pressed.", textColor);
    downMessage = TTF_RenderText_Solid(font, "Down was pressed.", textColor);
    leftMessage = TTF_RenderText_Solid(font, "Left was pressed", textColor);
    rightMessage = TTF_RenderText_Solid(font, "Right was pressed", textColor);

    if (upMessage == NULL || downMessage == NULL || leftMessage == NULL || rightMessage == NULL)
        return 1;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    message = upMessage;
                    break;
                case SDLK_DOWN:
                    message = downMessage;
                    break;
                case SDLK_LEFT:
                    message = leftMessage;
                    break;
                case SDLK_RIGHT:
                    message = rightMessage;
                    break;
                default:
                    break;
                }
            }
            if (event.type == SDL_QUIT)
                quit = true;
        }

        if(message != NULL)
        {
            apply_surface(0, 0, background, screen);
            apply_surface((SCREEN_WIDTH - message->w) / 2, (SCREEN_HEIGHT - message->h) / 2, message, screen);
            if(SDL_Flip(screen) == -1)
                return 1;
            message = NULL;
        }
    }

    clean_up();

    return 0;
}
