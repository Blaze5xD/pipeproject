#include "menu.h"
#include "DirectPipe.h"
#include "SDL_image.h"

void menu_init(SDL_Renderer *ren,int &choose,SDL_Event event)
{
	DPipe back(600,400,1200,800);
	back.default_create(ren,"menu_bg.jpg");
	SDL_RenderPresent(ren);
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=542) && (event.button.x<=742) && (event.button.y>=365) && (event.button.y<=420))
		{
			choose = 1; 
		}
		else if ((event.button.x>=542) && (event.button.x<=725) && (event.button.y>465) && (event.button.y<=533))
		{
			choose = -1; 
		}
	}	
}

void levels_change(SDL_Renderer *ren,int &choose,SDL_Event event)
{
	DPipe back(600,400,1200,800);
	back.default_create(ren,"background2.jpg");
	SDL_RenderPresent(ren);
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=440) && (event.button.x<=715) && (event.button.y>=290) && (event.button.y<=331))
		{
			choose += 1; 
		}
		else if ((event.button.x>=504) && (event.button.x<=633) && (event.button.y>431) && (event.button.y<=480))
		{
			choose = -1; 
		}
	}
}