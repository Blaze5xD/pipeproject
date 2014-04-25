#include "std_lib_facilities.h"
#include <SDL.h>
#include <ctime>
#include <SDL_image.h>
extern int SCREEN_WIDTH = 640;
extern int SCREEN_HEIGHT = 420;

SDL_Rect RectMake(int x,int y,int w,int h)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return rect;
}