#include "water.h"
#include "functions.h"
SDL_Event event;
int SCREEN_HEIGHT = 420;
int SCREEN_WIDTH = 640;

SDL_Rect RectMake(int x,int y,int w,int h)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return rect;
}

int main(int argc, char *argv[])
{
		vector<DPipe> DirectPipes(12);
		vector<DoublePipe> DoublePipes(12);
		vector<CrossPipe> CrossPipes(2);
				DPipe a0(50,SCREEN_HEIGHT-50,100,40);
				DoublePipe b0(150,SCREEN_HEIGHT-50,70,40);
				DPipe a1(250,SCREEN_HEIGHT-50,100,40);
				DoublePipe b1(350,SCREEN_HEIGHT-50,70,40);
				DPipe a2(450,SCREEN_HEIGHT-50,100,40);
				DoublePipe b2(550,SCREEN_HEIGHT-50,70,40);
				DPipe a3(50,SCREEN_HEIGHT-150,100,40);
				DPipe a4(150,SCREEN_HEIGHT-150,100,40);
				DoublePipe b3(250,SCREEN_HEIGHT-150,70,40);
				DoublePipe b4(350,SCREEN_HEIGHT-150,70,40);
				CrossPipe c0(450,SCREEN_HEIGHT-150,100,40);
				DPipe a5(550,SCREEN_HEIGHT-150,100,40);
				DoublePipe b5(50,SCREEN_HEIGHT-250,70,40);
				DoublePipe b6(150,SCREEN_HEIGHT-250,70,40);
				DoublePipe b7(250,SCREEN_HEIGHT-250,70,40);
				DPipe a6(350,SCREEN_HEIGHT-250,100,40);
				DPipe a7(450,SCREEN_HEIGHT-250,100,40);
				DoublePipe b8(550,SCREEN_HEIGHT-250,70,40);
				DPipe a8(50,SCREEN_HEIGHT-350,100,40);
				DoublePipe b9(150,SCREEN_HEIGHT-350,70,40);
				CrossPipe c1(250,SCREEN_HEIGHT-350,100,40);
				DoublePipe b10(350,SCREEN_HEIGHT-350,70,40);
				DPipe a9(450,SCREEN_HEIGHT-350,100,40);
				DPipe a10(550,SCREEN_HEIGHT-350,100,40);

				DirectPipes[0] = a0; DoublePipes[0] = b0;
				DirectPipes[1] = a1; DoublePipes[1] = b1;
				DirectPipes[2] = a2; DoublePipes[2] = b2;
				DirectPipes[3] = a3; DoublePipes[3] = b3;
				DirectPipes[4] = a4; DoublePipes[4] = b4;
				DirectPipes[5] = a5; DoublePipes[5] = b5;
				DirectPipes[6] = a6; DoublePipes[6] = b6;
				DirectPipes[7] = a7; DoublePipes[7] = b7;
				DirectPipes[8] = a8; DoublePipes[8] = b8;
				DirectPipes[9] = a9; DoublePipes[9] = b9;
				DirectPipes[10] = a10; DoublePipes[10] = b10;
				CrossPipes[0] = c0; CrossPipes[1] = c1;
				Water a(50,SCREEN_HEIGHT-50,40,10);

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
		SDL_Texture *socket = IMG_LoadTexture (game_renderer, "socket.bmp");
		bool won = false;
		int levels = 1;
		
		while (!quit && event.type != SDL_QUIT)
		{
			SDL_RenderClear (game_renderer);
			SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);

			for (int i=0;i<SCREEN_WIDTH/100;i++)
			{
				for (int j=0;j<SCREEN_HEIGHT/100;j++)
				{
					SDL_Rect socket_rect = RectMake (i*100,SCREEN_HEIGHT-100-j*100,100,100);
					SDL_RenderCopy (game_renderer, socket, NULL, &socket_rect);
				}
			}
			if (levels == 1)
			{
				for(int i=0;i<DirectPipes.size();++i)
				{
					DirectPipes[i].default_create(game_renderer,"text1.bmp");
				}
				for(int i=0;i<DoublePipes.size();++i)
				{
					DoublePipes[i].default_create1(game_renderer,"double1.bmp","double2.bmp");
				}
				for(int i=0;i<CrossPipes.size();++i)
				{
					CrossPipes[i].default_create(game_renderer,"CrossHor.bmp","CrossVert.bmp");
				}
				a.default_create(game_renderer,"start.bmp");
				SDL_RenderPresent(game_renderer);
				while(!quit && !won)
				{
					while (SDL_PollEvent(&event) && !won)
					{
						SDL_PumpEvents();
						if(event.type == SDL_QUIT)
							quit=true;
						else if(event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_LEFT)
						{
							for(int i=0;i<DirectPipes.size();++i)
							{
								if(DirectPipes[i].ismouse())
								{
									SDL_RenderClear(game_renderer);
									SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
									for (int i=0;i<SCREEN_WIDTH/100;i++)
									{
										for (int j=0;j<SCREEN_HEIGHT/100;j++)
										{
											SDL_Rect socket_rect = RectMake (i*100,SCREEN_HEIGHT-100-j*100,100,100);
											SDL_RenderCopy (game_renderer, socket, NULL, &socket_rect);
										}
									}
									nochangesDoub(game_renderer,DoublePipes);
									nochangesCross(game_renderer,CrossPipes);
									somechanges(game_renderer,DirectPipes,i);
								}
							}
							for(int i=0;i<DoublePipes.size();i++)
							{
								if(DoublePipes[i].ismouse())
								{
									SDL_RenderClear(game_renderer);
									SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
									for (int i=0;i<SCREEN_WIDTH/100;i++)
									{
										for (int j=0;j<SCREEN_HEIGHT/100;j++)
										{
											SDL_Rect socket_rect = RectMake (i*100,SCREEN_HEIGHT-100-j*100,100,100);
											SDL_RenderCopy (game_renderer, socket, NULL, &socket_rect);
										}
									}
									nochanges(game_renderer,DirectPipes);
									nochangesCross(game_renderer,CrossPipes);
									somechangesDoub(game_renderer,DoublePipes,i);
								}
							}
						}
						else if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
						{
							while(a.isrange() && !won)
							{
								if(a.isDpipe(DirectPipes))
								{
									a.Dpipebehaviour(game_renderer,DirectPipes);
									SDL_RenderPresent(game_renderer);
									if (a.Woda().x==550 && a.Woda().y==50)
									{
										won = true;
									}
 								}
								else if(a.isDoubpipe(DoublePipes))
								{
									a.Doubpipebehavior(game_renderer,DoublePipes);
									SDL_RenderPresent(game_renderer); 
									if (a.Woda().x==550 && a.Woda().y==50)
									{
										won = true;
									}
								}
								else if(a.isCrosspipe(CrossPipes))
								{
									a.Crosspipebehaviour(game_renderer,CrossPipes);
									SDL_RenderPresent(game_renderer);
									if (a.Woda().x==550 && a.Woda().y==50)
									{
										won = true;
									}
								}
							}
						}
					}
				}
				while (won && !quit)
				{
					SDL_Event *menu2_event = new SDL_Event;
					SDL_RenderClear (game_renderer);
					SDL_Texture *back2 = IMG_LoadTexture (game_renderer, "background2.bmp");
					SDL_Rect bg2_rect = RectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
					SDL_RenderCopy (game_renderer, back2, NULL, &bg2_rect);
					while (SDL_PollEvent(menu2_event))
					{
						if (menu2_event->type == SDL_QUIT)
								quit=true;
						if (menu2_event->type == SDL_MOUSEBUTTONDOWN)
						{
							if (menu2_event->button.button = SDL_BUTTON_LEFT)
							{
								if ((menu2_event->button.x>=230) && (menu2_event->button.x<=380) && (menu2_event->button.y>=150) && (menu2_event->button.y<=180))
								{
									choose = 1;
									cout << choose << endl;
									won = false;
								}
								if ((menu2_event->button.x>=270) && (menu2_event->button.x<=340) && (menu2_event->button.y>=230) && (menu2_event->button.y<=250))
								{ 
									choose = 2;
									cout << choose << endl;
									won = false;
								}
							}
						}
						if (menu2_event->type == SDL_MOUSEMOTION)
						{
							cout << "mouse x = " << menu2_event->motion.x << endl;
							cout << "mouse y = " << menu2_event->motion.y << endl;
						}
						SDL_RenderPresent (game_renderer);
					}
				}
				if (choose == 1)
				{
					SDL_RenderClear (game_renderer);
					while (!quit && event.type != SDL_QUIT)
					{
						SDL_RenderClear (game_renderer);
						SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
						for (int i=0;i<SCREEN_WIDTH/100;i++)
						{
							for (int j=0;j<SCREEN_HEIGHT/100;j++)
							{
								SDL_Rect socket_rect = RectMake (i*100,SCREEN_HEIGHT-100-j*100,100,100);
								SDL_RenderCopy (game_renderer, socket, NULL, &socket_rect);
							}
						}
						if (levels == 1)
						{
							for(int i=0;i<DirectPipes.size();++i)
							{
								DirectPipes[i].default_create(game_renderer,"text1.bmp");
							}
							for(int i=0;i<DoublePipes.size();++i)
							{
								DoublePipes[i].default_create1(game_renderer,"double1.bmp","double2.bmp");
							}
							for(int i=0;i<CrossPipes.size();++i)
							{
								CrossPipes[i].default_create(game_renderer,"CrossHor.bmp","CrossVert.bmp");
							}
							a.default_create(game_renderer,"start.bmp");
							SDL_RenderPresent(game_renderer);
							while(!quit && !won)
							{
								while (SDL_PollEvent(&event))
								{
									SDL_PumpEvents();
									if(event.type == SDL_QUIT)
										quit=true;
									else if(event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_LEFT)
									{
										for(int i=0;i<DirectPipes.size();++i)
										{
											if(DirectPipes[i].ismouse())
											{
												SDL_RenderClear(game_renderer);
												SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
												for (int i=0;i<SCREEN_WIDTH/100;i++)
												{
													for (int j=0;j<SCREEN_HEIGHT/100;j++)
													{
														SDL_Rect socket_rect = RectMake (i*100,SCREEN_HEIGHT-100-j*100,100,100);
														SDL_RenderCopy (game_renderer, socket, NULL, &socket_rect);
													}
												}
												nochangesDoub(game_renderer,DoublePipes);
												nochangesCross(game_renderer,CrossPipes);
												somechanges(game_renderer,DirectPipes,i);
											}
										}
										for(int i=0;i<DoublePipes.size();i++)
										{
											if(DoublePipes[i].ismouse())
											{
												SDL_RenderClear(game_renderer);
												SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
												for (int i=0;i<SCREEN_WIDTH/100;i++)
												{
													for (int j=0;j<SCREEN_HEIGHT/100;j++)
													{
														SDL_Rect socket_rect = RectMake (i*100,SCREEN_HEIGHT-100-j*100,100,100);
														SDL_RenderCopy (game_renderer, socket, NULL, &socket_rect);
													}
												}
												nochanges(game_renderer,DirectPipes);
												nochangesCross(game_renderer,CrossPipes);
												somechangesDoub(game_renderer,DoublePipes,i);
											}
										}
									}
									else if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
									{
										while(a.isrange())
										{
											if(a.isDpipe(DirectPipes))
											{
												a.Dpipebehaviour(game_renderer,DirectPipes);
												SDL_RenderPresent(game_renderer);
											}
											else if(a.isDoubpipe(DoublePipes))
											{
												a.Doubpipebehavior(game_renderer,DoublePipes);
												SDL_RenderPresent(game_renderer); 
											}
											else if(a.isCrosspipe(CrossPipes))
											{
												a.Crosspipebehaviour(game_renderer,CrossPipes);
												SDL_RenderPresent(game_renderer);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		SDL_DestroyWindow (game_window);
		SDL_DestroyRenderer(game_renderer);
		delete game_event;
	}
	return 0;
}