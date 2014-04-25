#include "game.h"

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}
	bool quit = false;
	SDL_Window *window = SDL_CreateWindow("Game", 300, 300,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
	    return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
	SDL_Event *event = new SDL_Event();

	SDL_Texture *background = IMG_LoadTexture (renderer, "background.bmp");
	
	SDL_Rect bg_rect;
	bg_rect.x = 0;
	bg_rect.y = 0;
	bg_rect.w = SCREEN_WIDTH;
	bg_rect.h = SCREEN_HEIGHT;
	
	while (!quit && event->type != SDL_QUIT)
	{
		SDL_PollEvent(event);
		SDL_RenderClear (renderer);
		SDL_RenderCopy (renderer, background, NULL, &bg_rect);
		for (int i=0;i<SCREEN_WIDTH/30;i++)
		{
			for (int j=0;j<SCREEN_HEIGHT/30;j++)
			{
				SDL_Texture *socket = IMG_LoadTexture (renderer,"socket.bmp");
				SDL_Rect socket_rect = RectMake(0+i*30,SCREEN_HEIGHT-30*(j+1),30,30);
				SDL_RenderCopy (renderer, socket, NULL, &socket_rect);
			}
		}
		SDL_RenderPresent (renderer);
	}
	SDL_DestroyWindow (window);
	SDL_DestroyRenderer(renderer);
	delete event;
	return 0;
}