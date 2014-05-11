#include "water.h"
#include "functions.h"
SDL_Event event;
int SCREEN_HEIGHT = 800;
int SCREEN_WIDTH = 1200;

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
		vector<DPipe> DPIPES(44);
	vector<DoublePipe> DOUBPIPES(18);
	vector<CrossPipe> CROSSPIPES(3);

	DPipe background(600,400,1200,800);

	DPipe a0(50,750,100,40);
	DPipe a1(150,650,100,40);
	DPipe a2(150,550,100,40);
	DPipe a3(650,450,100,40);
	DPipe a4(550,550,100,40);
	DPipe a5(450,350,100,40);
	DPipe a6(550,250,100,40);
	DPipe a7(650,250,100,40);
	DPipe a8(750,350,100,40);
	DPipe a9(750,450,100,40);
	DPipe a10(750,550,100,40);
	DPipe a11(650,650,100,40);
	DPipe a12(550,650,100,40);
	DPipe a13(450,650,100,40);
	DPipe a14(350,550,100,40);
	DPipe a15(350,350,100,40);
	DPipe a16(350,250,100,40);
	DPipe a17(450,150,100,40);
	DPipe a18(550,150,100,40);
	DPipe a19(650,150,100,40);
	DPipe a20(750,150,100,40);
	DPipe a21(850,250,100,40);
	DPipe a22(850,350,100,40);
	DPipe a23(850,450,100,40);
	DPipe a24(850,550,100,40);
	DPipe a25(850,650,100,40);
	DPipe a26(750,750,100,40);
	DPipe a27(650,750,100,40);
	DPipe a28(550,750,100,40);
	DPipe a29(450,750,100,40);
	DPipe a30(350,750,100,40);
	DPipe a31(250,650,100,40);
	DPipe a32(250,550,100,40);
	DPipe a33(250,350,100,40);
	DPipe a34(250,250,100,40);
	DPipe a35(250,150,100,40);
	DPipe a36(350,50,100,40);
	DPipe a37(450,50,100,40);
	DPipe a38(550,50,100,40);
	DPipe a39(650,50,100,40);
	DPipe a40(750,50,100,40);
	DPipe a41(850,50,100,40);
	DPipe a42(950,150,100,40);
	DPipe a43(950,250,100,40);
	

	DoublePipe b0(150,750,70,40);
	DoublePipe b1(150,450,70,40);
	DoublePipe b2(550,450,70,40);
	DoublePipe b3(550,350,70,40);
	DoublePipe b4(650,350,70,40);
	DoublePipe b5(650,550,70,40);
	DoublePipe b6(450,550,70,40);
	DoublePipe b7(450,250,70,40);
	DoublePipe b8(750,250,70,40);
	DoublePipe b9(750,650,70,40);
	DoublePipe b10(350,650,70,40);
	DoublePipe b11(350,150,70,40);
	DoublePipe b12(850,150,70,40);
	DoublePipe b13(850,750,70,40);
	DoublePipe b14(250,750,70,40);
	DoublePipe b15(250,50,70,40);
	DoublePipe b16(950,50,70,40);
	DoublePipe b17(950,350,70,40);
	DPipe d0(1050,400,100,40);

	CrossPipe c0(250,450,100,40);
	CrossPipe c1(350,450,100,40);
	CrossPipe c2(450,450,100,40);

	DPIPES[0]=a0;
	DPIPES[1]=a1;
	DPIPES[2]=a2;
	DPIPES[3]=a3;
	DPIPES[4]=a4;
	DPIPES[5]=a5;
	DPIPES[6]=a6;
	DPIPES[7]=a7;
	DPIPES[8]=a8;
	DPIPES[9]=a9;
	DPIPES[10]=a10;
	DPIPES[11]=a11;
	DPIPES[12]=a12;
	DPIPES[13]=a13;
	DPIPES[14]=a14;
	DPIPES[15]=a15;
	DPIPES[16]=a16;
	DPIPES[17]=a17;
	DPIPES[18]=a18;
	DPIPES[19]=a19;
	DPIPES[20]=a20;
	DPIPES[21]=a21;
	DPIPES[22]=a22;
	DPIPES[23]=a23;
	DPIPES[24]=a24;
	DPIPES[25]=a25;
	DPIPES[26]=a26;
	DPIPES[27]=a27;
	DPIPES[28]=a28;
	DPIPES[29]=a29;
	DPIPES[30]=a30;
	DPIPES[31]=a31;
	DPIPES[32]=a32;
	DPIPES[33]=a33;
	DPIPES[34]=a34;
	DPIPES[35]=a35;
	DPIPES[36]=a36;
	DPIPES[37]=a37;
	DPIPES[38]=a38;
	DPIPES[39]=a39;
	DPIPES[40]=a40;
	DPIPES[41]=a41;
	DPIPES[42]=a42;
	DPIPES[43]=a43;

	DOUBPIPES[0]=b0;
	DOUBPIPES[1]=b1;
	DOUBPIPES[2]=b2;
	DOUBPIPES[3]=b3;
	DOUBPIPES[4]=b4;
	DOUBPIPES[5]=b5;
	DOUBPIPES[6]=b6;
	DOUBPIPES[7]=b7;
	DOUBPIPES[8]=b8;
	DOUBPIPES[9]=b9;
	DOUBPIPES[10]=b10;
	DOUBPIPES[11]=b11;
	DOUBPIPES[12]=b12;
	DOUBPIPES[13]=b13;
	DOUBPIPES[14]=b14;
	DOUBPIPES[15]=b15;
	DOUBPIPES[16]=b16;
	DOUBPIPES[17]=b17;

	CROSSPIPES[0]=c0;
	CROSSPIPES[1]=c1;
	CROSSPIPES[2]=c2;
	Water a(20,750,40,40);

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
				if (menu_event->type == SDL_MOUSEBUTTONDOWN)
				{
					if (menu_event->button.button = SDL_BUTTON_LEFT)
					{
						if ((menu_event->button.x>=390) && (menu_event->button.x<=550) && (menu_event->button.y>=310) && (menu_event->button.y<=370))
						{
							choose = 1; 
							menu_quit = true;
						}
						if ((menu_event->button.x>=390) && (menu_event->button.x<=550) && (menu_event->button.y>410) && (menu_event->button.y<=470))
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
				for(int i=0;i<DPIPES.size();++i)
				{
					DPIPES[i].default_create(game_renderer,"text1.bmp");
				}
				for(int i=0;i<DOUBPIPES.size();++i)
				{
					DOUBPIPES[i].default_create1(game_renderer,"double1.bmp","double2.bmp");
				}
				for(int i=0;i<CROSSPIPES.size();++i)
				{
					CROSSPIPES[i].default_create(game_renderer,"CrossHor.bmp","CrossVert.bmp");
				}
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
							for(int i=1;i<DPIPES.size()-1;++i)
							{
								if(DPIPES[i].ismouse())
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
									nochangesDoub(game_renderer,DOUBPIPES);
									nochangesCross(game_renderer,CROSSPIPES);
									somechanges(game_renderer,DPIPES,i);
								}
							}
							for(int i=0;i<DOUBPIPES.size();i++)
							{
								if(DOUBPIPES[i].ismouse())
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
									nochanges(game_renderer,DPIPES);
									nochangesCross(game_renderer,CROSSPIPES);
									somechangesDoub(game_renderer,DOUBPIPES,i);
								}
							}
						}
						else if((event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_RIGHT))
						{
							while(a.isrange() && !won)
							{
								if(a.isDpipe(DPIPES))
								{
									a.Dpipebehaviour(game_renderer,DPIPES);
									SDL_RenderPresent(game_renderer);
									if (a.Woda().x==859 && a.Woda().y==330)
									{
										won = true;
									}
 								}
								else if(a.isDoubpipe(DOUBPIPES))
								{
									a.Doubpipebehavior(game_renderer,DOUBPIPES);
									SDL_RenderPresent(game_renderer); 
									if (a.Woda().x==859 && a.Woda().y==330)
									{
										won = true;
									}
								}
								else if(a.isCrosspipe(CROSSPIPES))
								{
									a.Crosspipebehaviour(game_renderer,CROSSPIPES);
									SDL_RenderPresent(game_renderer);
									if (a.Woda().x==859 && a.Woda().y==330)
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
								if ((menu2_event->button.x>=330) && (menu2_event->button.x<=540) && (menu2_event->button.y>=250) && (menu2_event->button.y<=290))
								{
									choose = 1;
									cout << choose << endl;
									won = false;
								}
								if ((menu2_event->button.x>=380) && (menu2_event->button.x<=480) && (menu2_event->button.y>=380) && (menu2_event->button.y<=420))
								{ 
									choose = 2;
									cout << choose << endl;
									won = false;
									quit = true;
								}
							}
						}
						SDL_RenderPresent (game_renderer);
					}
				}
				if (choose == 1 && !quit)
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
							for(int i=0;i<DPIPES.size();++i)
							{
								DPIPES[i].default_create(game_renderer,"text1.bmp");
							}
							for(int i=0;i<DOUBPIPES.size();++i)
							{
								DOUBPIPES[i].default_create1(game_renderer,"double1.bmp","double2.bmp");
							}
							for(int i=0;i<CROSSPIPES.size();++i)
							{
								CROSSPIPES[i].default_create(game_renderer,"CrossHor.bmp","CrossVert.bmp");
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
										for(int i=0;i<DPIPES.size();++i)
										{
											if(DPIPES[i].ismouse())
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
												nochangesDoub(game_renderer,DOUBPIPES);
												nochangesCross(game_renderer,CROSSPIPES);
												somechanges(game_renderer,DPIPES,i);
											}
										}
										for(int i=0;i<DOUBPIPES.size();i++)
										{
											if(DOUBPIPES[i].ismouse())
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
												nochanges(game_renderer,DPIPES);
												nochangesCross(game_renderer,CROSSPIPES);
												somechangesDoub(game_renderer,DOUBPIPES,i);
											}
										}
									}
									else if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
									{
										while(a.isrange())
										{
											if(a.isDpipe(DPIPES))
											{
												a.Dpipebehaviour(game_renderer,DPIPES);
												SDL_RenderPresent(game_renderer);
											}
											else if(a.isDoubpipe(DOUBPIPES))
											{
												a.Doubpipebehavior(game_renderer,DOUBPIPES);
												SDL_RenderPresent(game_renderer); 
											}
											else if(a.isCrosspipe(CROSSPIPES))
											{
												a.Crosspipebehaviour(game_renderer,CROSSPIPES);
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