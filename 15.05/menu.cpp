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

void manual_init(SDL_Renderer *ren,SDL_Event event,int &manualchoose, int &choose)
{
	DPipe back(600,400,1200,800);
	back.default_create(ren,"manual.jpg");
	DPipe pipe1(150,250,100,40);
	DoublePipe pipe2(150,400,70,40);
	CrossPipe pipe3(150,550,100,40);
	pipe1.default_create(ren,"text1.jpg");
	pipe2.default_create1(ren,"double1.jpg","double2.jpg");
	pipe3.default_create(ren,"CrossHor.jpg","CrossVert.jpg");
	SDL_RenderPresent(ren);
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=20) && (event.button.x<=112) && (event.button.y>=720) && (event.button.y<=738))
		{
			choose = 0; 
		}
		else if ((event.button.x>=1109) && (event.button.x<=1176) && (event.button.y>716) && (event.button.y<=735))
		{
			choose = -1; 
		}
	}
	else if(event.type == SDL_MOUSEMOTION)
	{
		if ((event.button.x>=100) && (event.button.x<=231) && (event.button.y>=200) && (event.button.y<=272))
		{
			manualchoose = 1; 
		}

		else if ((event.button.x>=128) && (event.button.x<=172) && (event.button.y>=379) && (event.button.y<=436))
		{
			manualchoose = 1; 
		}

		else if ((event.button.x>=104) && (event.button.x<=192) && (event.button.y>=500) && (event.button.y<=591))
		{
			manualchoose = 1; 
		}
	}
}