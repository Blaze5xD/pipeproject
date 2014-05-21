#include "menu.h"
#include "DirectPipe.h"
#include "CrossPipe.h"
#include "DoublePipe.h"
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
		else if ((event.button.x>=504) && (event.button.x<=755) && (event.button.y>174) && (event.button.y<=215))
		{
			choose = -2; 
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
		if ((event.button.x>=449) && (event.button.x<=689) && (event.button.y>=269) && (event.button.y<=309))
		{
			choose += 1; 
		}
		else if ((event.button.x>=445) && (event.button.x<=572) && (event.button.y>492) && (event.button.y<=528))
		{
			choose = -1; 
		}
	}
}

void final(SDL_Renderer *ren,int &choose,SDL_Event event)
{
	DPipe back(600,400,1200,800);
	back.default_create(ren,"final.jpg");
	SDL_RenderPresent(ren);
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=400) && (event.button.x<=503) && (event.button.y>=308) && (event.button.y<=335))
		{
			choose = 0; 
		}
		else if ((event.button.x>=402) && (event.button.x<=457) && (event.button.y>465) && (event.button.y<=479))
		{
			choose = -1; 
		}
	}
}

