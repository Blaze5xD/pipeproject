
#include "SDL_image.h"
#include "menu.h"
#include "level.h"


SDL_Event event;

int SCREEN_HEIGHT = 800;
int SCREEN_WIDTH = 1200;

int main(int argv,char **argc)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win = SDL_CreateWindow("Game", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED); 

	vector<DPipe> DPIPES;
	vector<DoublePipe> DOUBPIPES;
	vector<CrossPipe> CROSSPIPES;
	Water a(10,750,20,20);

	DPipe back(600,400,1200,800);

	int choose=0;
	int manualchoose=0;
	int level1choose=0;
	int level2choose=0;
	int level3choose=0;
	bool quit=false;
	while(!quit)
	{
		while (SDL_PollEvent(&event))
		{
			SDL_PumpEvents();
			if(event.type == SDL_QUIT)
				quit=true;
			if(choose==-2)
			{
				manual_init(ren,event,manualchoose,choose);
			}
			else if(choose==-1)
			{
				quit=true;
			}
			else if(choose==0)
			{
				menu_init(ren,choose,event);
			}
			//level1
			else if(choose==1)
			{
				if(level1choose==0)
				{
					SDL_RenderClear(ren);
					back.default_create(ren,"BACK.jpg");
					init_pipes_level_one(ren,DPIPES,DOUBPIPES,CROSSPIPES,a);
					level1choose=1;
				}
				else if(level1choose==1)
				{
					go_level_one(ren,DPIPES,DOUBPIPES,CROSSPIPES,a,back,choose,level1choose);
				}
			}
			else if(choose==2)
			{
				levels_change(ren,choose,event);
			}
			//level2
			else if(choose==3)
			{
				if(level2choose==0)
				{
					SDL_RenderClear(ren);
					back.default_create(ren,"BACK.jpg");
					init_pipes_level_two(ren,DPIPES,DOUBPIPES,CROSSPIPES,a);
					level2choose=1;
				}
				else if(level2choose==1)
				{
					go_level_two(ren,DPIPES,DOUBPIPES,CROSSPIPES,a,back,choose,level2choose);
				}
			}
			else if(choose==4)
			{
				levels_change(ren,choose,event);
			} 
			//level3
			else if(choose==5)
			{
				if(level3choose==0)
				{
					SDL_RenderClear(ren);
					back.default_create(ren,"BACK.jpg");
					init_pipes_level_three(ren,DPIPES,DOUBPIPES,CROSSPIPES,a);
					level3choose=1;
				}
				else if(level3choose==1)
				{
					go_level_three(ren,DPIPES,DOUBPIPES,CROSSPIPES,a,back,choose,level3choose);
				}
			}
		}
	}
	return 0;
}