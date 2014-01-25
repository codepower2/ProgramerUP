#ifndef FUNCTIONS_H
#define FUNCTIONS_h

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

using namespace std;

SDL_Surface *load_image(string filename);
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL);

#endif
