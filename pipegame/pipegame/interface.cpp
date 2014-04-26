#include "game.h"

int main(int argc, char *argv[])
{
	int choose = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}
	SDL_Window *game_window = SDL_CreateWindow("Game", 300, 300, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (game_window == nullptr)
	{
		cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
	    return 1;
	}
	SDL_Renderer *game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);
	bool quit = false;
	
	while (choose == 0)
	{
		int choser_position = 1;	
		SDL_Event *menu_event = new SDL_Event();
		SDL_Texture *menu = IMG_LoadTexture (game_renderer, "menu_bg.bmp");
		SDL_Rect menu_bg_rect = RectMake (0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		SDL_Texture *choser = IMG_LoadTexture (game_renderer, "choser.bmp");
		SDL_Rect menu_choser_up = RectMake (240, 225, 200, 10);
		SDL_Rect menu_choser_down = RectMake (240, 290, 200, 10);
		bool menu_quit = false;

		while (!menu_quit)
		{
			if (menu_event->type == SDL_QUIT)
			{
				menu_quit = true;
				choose = 2;
			}
			while (SDL_PollEvent (menu_event))
			{
				SDL_RenderClear (game_renderer);
				SDL_RenderCopy (game_renderer, menu, NULL, &menu_bg_rect);
				SDL_RenderPresent (game_renderer);

				if (menu_event->type == SDL_MOUSEMOTION)
				{
					cout << "mouse x = " << menu_event->motion.x << endl;
					cout << "mouse y = " << menu_event->motion.y << endl;
				}

				if (menu_event->type == SDL_MOUSEBUTTONDOWN)
				{
					if (menu_event->button.button = SDL_BUTTON_LEFT)
					{
						if ((menu_event->button.x>=280) && (menu_event->button.x<=390) && (menu_event->button.y>=190) && (menu_event->button.y<=220))
						{
							choose = 1; 
							menu_quit = true;
						}
						if ((menu_event->button.x>=280) && (menu_event->button.x<=390) && (menu_event->button.y>=250) && (menu_event->button.y<=280))
						{
							choose = 2; 
							menu_quit = true;
						}
					}

				}
				if (menu_event->type == SDL_KEYDOWN) 
				{
					if (menu_event->key.keysym.sym == SDLK_ESCAPE) 
					{
						menu_quit = true;
						choose = 2;
					}

					if (menu_event->key.keysym.sym == SDLK_UP) 
					{
					    if (choser_position == 2)
						{
							SDL_RenderClear (game_renderer);
							SDL_RenderCopy (game_renderer, menu, NULL, &menu_bg_rect);
							SDL_RenderCopy (game_renderer, choser, NULL, &menu_choser_up);
							SDL_RenderPresent (game_renderer);
							choser_position = 1;
							cout << "choser_position: " << choser_position << endl;
							SDL_Delay(1000);
							
						}

					}
	
					if (menu_event->key.keysym.sym == SDLK_DOWN) 
					{
						if (choser_position == 1)
						{	
							SDL_RenderClear (game_renderer);
							SDL_RenderCopy (game_renderer, menu, NULL, &menu_bg_rect);
							SDL_RenderCopy (game_renderer, choser, NULL, &menu_choser_down);
							SDL_RenderPresent (game_renderer);
							choser_position = 2;
							cout << "choser_position: " << choser_position << endl;
							SDL_Delay(1000);
						}
					}
					

					if (menu_event->key.keysym.sym == SDLK_SPACE)
					{
						if (choser_position == 1) {
							choose = 1; menu_quit = true; }
						else { choose = 2; menu_quit = true; }
					}
				}
			}
		}
		SDL_RenderClear (game_renderer);
		SDL_DestroyTexture (menu);
		SDL_DestroyTexture (choser);
		delete menu_event;
	}
	if (choose == 2)
	{
		quit = true;
	}

	if (choose == 1)
	{
		SDL_RenderClear (game_renderer);
		SDL_Event *game_event = new SDL_Event();
		SDL_Texture *background = IMG_LoadTexture (game_renderer, "background.bmp");
		SDL_Rect bg_rect = RectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
		while (!quit && game_event->type != SDL_QUIT)
		{
			SDL_PollEvent(game_event);
			SDL_RenderClear (game_renderer);
			SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
			for (int i=0;i<SCREEN_WIDTH/30;i++)
			{
				for (int j=0;j<SCREEN_HEIGHT/30;j++)
				{
					SDL_Texture *socket = IMG_LoadTexture (game_renderer,"socket.bmp");
					SDL_Rect socket_rect = RectMake(0+i*30,SCREEN_HEIGHT-30*(j+1),30,30);
					SDL_RenderCopy (game_renderer, socket, NULL, &socket_rect);
				}
			}
			SDL_RenderPresent (game_renderer);
		}
		SDL_DestroyWindow (game_window);
		SDL_DestroyRenderer(game_renderer);
		delete game_event;
	}
	return 0;
}