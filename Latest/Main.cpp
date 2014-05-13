
#include "water.h"
#include "functions.h"
#include "SDL_image.h"

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

int main(int argc,char **argv)
{
	SDL_Event *menu2_event = new SDL_Event;
	SDL_Event *menu_event = new SDL_Event();
	SDL_Event *menu3_event = new SDL_Event;
	
	vector<DPipe> DPIPES(4);
	vector<DoublePipe> DOUBPIPES(11);
	vector<CrossPipe> CROSSPIPES(1);

	vector<DPipe> DPIPES1(18);
	vector<DoublePipe> DOUBPIPES1(13);
	vector<CrossPipe> CROSSPIPES1(1);

	vector<DPipe> DPIPES2(33);
	vector<DoublePipe> DOUBPIPES2(18);
	vector<CrossPipe> CROSSPIPES2(2);

	DPipe back(600,400,1200,800);
	// level_1
	DPipe a0(20,750,50,20);
	DPipe a1(70,700,50,20);
	DPipe a2(220,500,50,20);
	DPipe a3(270,450,50,20);
	
	DoublePipe b0(70,750,35,20);
	DoublePipe b1(70,650,35,20);
	DoublePipe b2(170,650,35,20);
	DoublePipe b3(170,700,35,20);
	DoublePipe b4(120,700,35,20);
	DoublePipe b5(120,600,35,20);
	DoublePipe b6(170,600,35,20);
	DoublePipe b7(170,550,35,20);
	DoublePipe b8(220,550,35,20);
	DoublePipe b9(220,450,35,20);
	DoublePipe b10(320,450,35,20);

	CrossPipe c0(120,650,50,20);
	DPIPES[0]=a0;
	DPIPES[1]=a1;
	DPIPES[2]=a2;
	DPIPES[3]=a3;

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

	CROSSPIPES[0]=c0;
	
	//level_2
	DPipe A0(20,750,50,20);
	DPipe A1(70,700,50,20);
	DPipe A2(120,650,50,20);
	DPipe A3(170,700,50,20);
	DPipe A4(220,700,50,20);
	DPipe A5(320,500,50,20);
	DPipe A6(320,600,50,20);
	DPipe A7(370,600,50,20);
	DPipe A8(420,600,50,20);
	DPipe A9(420,650,50,20);
	DPipe A10(370,650,50,20);
	DPipe A11(320,650,50,20);
	DPipe A12(270,650,50,20);
	DPipe A13(220,600,50,20);
	DPipe A14(220,500,50,20);
	DPipe A15(270,450,50,20);
	DPipe A16(320,450,50,20);
	DPipe A17(170,600,50,20);

	DoublePipe B0(70,750,35,20);
	DoublePipe B1(70,650,35,20);
	DoublePipe B2(170,650,35,20);
	DoublePipe B3(170,750,35,20);
	DoublePipe B4(220,750,35,20);
	DoublePipe B5(170,550,35,20);
	DoublePipe B6(270,550,35,20);
	DoublePipe B7(270,600,35,20);
	DoublePipe B8(470,600,35,20);
	DoublePipe B9(470,650,35,20);
	DoublePipe B10(220,650,35,20);
	DoublePipe B11(220,450,35,20);
	DoublePipe B12(370,450,35,20);

	CrossPipe C0(220,550,50,20);

	DPIPES1[0]=A0;
	DPIPES1[1]=A1;
	DPIPES1[2]=A2;
	DPIPES1[3]=A3;
	DPIPES1[4]=A4;
	DPIPES1[5]=A5;
	DPIPES1[6]=A6;
	DPIPES1[7]=A7;
	DPIPES1[8]=A8;
	DPIPES1[9]=A9;
	DPIPES1[10]=A10;
	DPIPES1[11]=A11;
	DPIPES1[12]=A12;
	DPIPES1[13]=A13;
	DPIPES1[14]=A14;
	DPIPES1[15]=A15;
	DPIPES1[16]=A16;
	DPIPES1[17]=A17;

	DOUBPIPES1[0]=B0;
	DOUBPIPES1[1]=B1;
	DOUBPIPES1[2]=B2;
	DOUBPIPES1[3]=B3;
	DOUBPIPES1[4]=B4;
	DOUBPIPES1[5]=B5;
	DOUBPIPES1[6]=B6;
	DOUBPIPES1[7]=B7;
	DOUBPIPES1[8]=B8;
	DOUBPIPES1[9]=B9;
	DOUBPIPES1[10]=B10;
	DOUBPIPES1[11]=B11;
	DOUBPIPES1[12]=B12;

	CROSSPIPES1[0]=C0;

	//level_3
	DPipe AA0(20,750,50,20);
	DPipe AA1(70,700,50,20);
	DPipe AA2(120,600,50,20);
	DPipe AA3(120,500,50,20);
	DPipe AA5(70,450,50,20);
	DPipe AA6(20,500,50,20);
	DPipe AA8(70,550,50,20);
	DPipe AA9(170,550,50,20);
	DPipe AA10(220,600,50,20);
	DPipe AA11(220,650,50,20);
	DPipe AA12(220,700,50,20);
	DPipe AA13(270,750,50,20);
	DPipe AA14(320,750,50,20);
	DPipe AA15(370,750,50,20);
	DPipe AA16(420,750,50,20);
	DPipe AA17(470,750,50,20);
	DPipe AA18(520,750,50,20);
	DPipe AA19(570,750,50,20);
	DPipe AA20(620,700,50,20);
	DPipe AA21(620,650,50,20);
	DPipe AA22(620,600,50,20);
	DPipe AA23(620,550,50,20);
	DPipe AA24(620,500,50,20);
	DPipe AA26(570,450,50,20);
	DPipe AA27(270,550,50,20);
	DPipe AA28(420,550,50,20);
	DPipe AA29(470,550,50,20);
	DPipe AA30(520,550,50,20);
	DPipe AA31(520,600,50,20);
	DPipe AA32(470,600,50,20);
	DPipe AA33(420,600,50,20);
	DPipe AA34(370,600,50,20);
	DPipe AA35(320,550,50,20);

	DoublePipe BB0(70,750,35,20);
	DoublePipe BB1(70,650,35,20);
	DoublePipe BB2(120,650,35,20);
	DoublePipe BB3(120,450,35,20);
	DoublePipe BB4(20,450,35,20);
	DoublePipe BB5(20,550,35,20);
	DoublePipe BB6(220,550,35,20);
	DoublePipe BB7(220,750,35,20);
	DoublePipe BB8(620,750,35,20);
	DoublePipe BB9(620,450,35,20);
	DoublePipe BB10(520,450,35,20);
	DoublePipe BB11(220,500,35,20);
	DoublePipe BB12(370,500,35,20);
	DoublePipe BB15(370,550,35,20);
	DoublePipe BB16(570,550,35,20);
	DoublePipe BB17(570,600,35,20);
	DoublePipe BB18(320,600,35,20);
	DoublePipe BB19(320,400,35,20);

	CrossPipe CC0(120,550,50,20);
	CrossPipe CC1(320,500,50,20);

	DPIPES2[0]=AA0;
	DPIPES2[1]=AA1;
	DPIPES2[2]=AA2;
	DPIPES2[3]=AA3;
	DPIPES2[4]=AA5;
	DPIPES2[5]=AA6;
	DPIPES2[6]=AA8;
	DPIPES2[7]=AA9;
	DPIPES2[8]=AA10;
	DPIPES2[9]=AA11;
	DPIPES2[10]=AA12;
	DPIPES2[11]=AA13;
	DPIPES2[12]=AA14;
	DPIPES2[13]=AA15;
	DPIPES2[14]=AA16;
	DPIPES2[15]=AA17;
	DPIPES2[16]=AA18;
	DPIPES2[17]=AA19;
	DPIPES2[18]=AA20;
	DPIPES2[19]=AA21;
	DPIPES2[20]=AA22;
	DPIPES2[21]=AA23;
	DPIPES2[22]=AA24;
	DPIPES2[23]=AA26;
	DPIPES2[24]=AA27;
	DPIPES2[25]=AA28;
	DPIPES2[26]=AA29;
	DPIPES2[27]=AA30;
	DPIPES2[28]=AA31;
	DPIPES2[29]=AA32;
	DPIPES2[30]=AA33;
	DPIPES2[31]=AA34;
	DPIPES2[32]=AA35;

	DOUBPIPES2[0]=BB0;
	DOUBPIPES2[1]=BB1;
	DOUBPIPES2[2]=BB2;
	DOUBPIPES2[3]=BB3;
	DOUBPIPES2[4]=BB4;
	DOUBPIPES2[5]=BB5;
	DOUBPIPES2[6]=BB6;
	DOUBPIPES2[7]=BB7;
	DOUBPIPES2[8]=BB8;
	DOUBPIPES2[9]=BB9;
	DOUBPIPES2[10]=BB10;
	DOUBPIPES2[11]=BB11;
	DOUBPIPES2[12]=BB12;
	DOUBPIPES2[13]=BB15;
	DOUBPIPES2[14]=BB16;
	DOUBPIPES2[15]=BB17;
	DOUBPIPES2[16]=BB18;
	DOUBPIPES2[17]=BB19;

	CROSSPIPES2[0]=CC0;
	CROSSPIPES2[1]=CC1;
	//

	Water a(10,750,20,20);
	int count=0;
	int now;
	int last=0;
	int choose = 0;
	int A=0; int B=0;
	int AA=0; int BB=0;
	bool won1=false;
	bool won2=false;
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
		SDL_Texture *menu = IMG_LoadTexture (game_renderer, "menu_bg.jpg");
		SDL_Rect menu_bg_rect = RectMake (0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		SDL_Texture *choser = IMG_LoadTexture (game_renderer, "choser.jpg");
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
						if ((menu_event->button.x>=542) && (menu_event->button.x<=742) && (menu_event->button.y>=365) && (menu_event->button.y<=420))
						{
							choose = 1; 
							menu_quit = true;
						}
						if ((menu_event->button.x>=542) && (menu_event->button.x<=725) && (menu_event->button.y>465) && (menu_event->button.y<=533))
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
		SDL_Texture *background = IMG_LoadTexture (game_renderer, "background.jpg");
		SDL_Rect bg_rect = RectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		
		bool won = false;
		int levels = 1;
		
		while (!quit && event.type != SDL_QUIT)
		{
			SDL_RenderClear (game_renderer);
			SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
			if (levels == 1)
			{
				back.default_create(game_renderer,"BACK.jpg");
				for(int i=0;i<DPIPES.size();++i)
				{
					DPIPES[i].default_create(game_renderer,"text1.jpg");
				}
				for(int i=0;i<DOUBPIPES.size();++i)
				{
					DOUBPIPES[i].default_create1(game_renderer,"double1.jpg","double2.jpg");
				}
				for(int i=0;i<CROSSPIPES.size();++i)
				{
					CROSSPIPES[i].default_create(game_renderer,"CrossHor.jpg","CrossVert.jpg");
				}
				a.default_create(game_renderer,"start.jpg");
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
							for(int i=1;i<DPIPES.size();++i)
							{
								if(DPIPES[i].ismouse())
								{
									SDL_RenderClear(game_renderer);
									back.default_create(game_renderer,"BACK.jpg");
									nochangesDoub(game_renderer,DOUBPIPES);
									nochangesCross(game_renderer,CROSSPIPES);
									somechanges(game_renderer,DPIPES,i);
									a.default_create(game_renderer,"start.jpg");
									SDL_RenderPresent(game_renderer);
								}
							}
							for(int i=0;i<DOUBPIPES.size();i++)
							{
								if(DOUBPIPES[i].ismouse())
								{
									SDL_RenderClear(game_renderer);
									back.default_create(game_renderer,"BACK.jpg");
									nochanges(game_renderer,DPIPES);
									nochangesCross(game_renderer,CROSSPIPES);
									somechangesDoub(game_renderer,DOUBPIPES,i);
									a.default_create(game_renderer,"start.jpg");
									SDL_RenderPresent(game_renderer);
								}
							}
						}
						else if((event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_RIGHT))
						{
							
							while(a.isrange() && !won)
							{
								A=a.Woda().x;
								AA=a.Woda().y;
								if(a.isDpipe(DPIPES))
								{
									a.Dpipebehaviour(game_renderer,DPIPES);
									SDL_RenderPresent(game_renderer);
									if (a.Woda().x==310 && a.Woda().y==426)
									{
										won = true;
									}
 								}
								else if(a.isDoubpipe(DOUBPIPES))
								{
									a.Doubpipebehavior(game_renderer,DOUBPIPES);
									SDL_RenderPresent(game_renderer); 
									if (a.Woda().x==310 && a.Woda().y==426)
									{
										won = true;
									}

								}
								else if(a.isCrosspipe(CROSSPIPES))
								{
									a.Crosspipebehaviour(game_renderer,CROSSPIPES);
									SDL_RenderPresent(game_renderer);
									if (a.Woda().x==310 && a.Woda().y==426)
									{
										won = true;
									}
								}
								B=a.Woda().x;
								BB=a.Woda().y;
								if((B-A)==0 &&(BB-AA)==0 &&!won)
								{
								//	lose==true;
									break;
								}
							}
						}
					}
				}
				while (won && !quit)
				{
					SDL_RenderClear (game_renderer);
					SDL_Texture *back2 = IMG_LoadTexture (game_renderer, "background2.jpg");
					SDL_Rect bg2_rect = RectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
					SDL_RenderCopy (game_renderer, back2, NULL, &bg2_rect);
					SDL_DestroyTexture(back2);
					while (SDL_PollEvent(menu2_event))
					{
						if (menu2_event->type == SDL_QUIT)
								quit=true;
						if (menu2_event->type == SDL_MOUSEBUTTONDOWN)
						{
							if (menu2_event->button.button = SDL_BUTTON_LEFT)
							{
								if ((menu2_event->button.x>=440) && (menu2_event->button.x<=715) && (menu2_event->button.y>=290) && (menu2_event->button.y<=331))
								{
									choose = 1;
									cout << choose << endl;
									won = false;
								}
								if ((menu2_event->button.x>=504) && (menu2_event->button.x<=633) && (menu2_event->button.y>=431) && (menu2_event->button.y<=480))
								{ 
									choose = 2;
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
					a.comeback(10,750,20);
					SDL_RenderClear (game_renderer);
					while (!quit && event.type != SDL_QUIT)
					{
						SDL_RenderClear (game_renderer);
						SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
						if (levels == 1)
						{
							back.default_create(game_renderer,"BACK.jpg");
							for(int i=0;i<DPIPES1.size();++i)
							{
								DPIPES1[i].default_create(game_renderer,"text1.jpg");
							}
							for(int i=0;i<DOUBPIPES1.size();++i)
							{
								DOUBPIPES1[i].default_create1(game_renderer,"double1.jpg","double2.jpg");
							}
							for(int i=0;i<CROSSPIPES1.size();++i)
							{
								CROSSPIPES1[i].default_create(game_renderer,"CrossHor.jpg","CrossVert.jpg");
							}
							a.default_create(game_renderer,"start.jpg");
							SDL_RenderPresent(game_renderer);
							while(!quit && !won1)
							{
								while (SDL_PollEvent(&event))
								{
									SDL_PumpEvents();
									if(event.type == SDL_QUIT)
										quit=true;
									else if(event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_LEFT)
									{
										for(int i=0;i<DPIPES1.size();++i)
										{
											if(DPIPES1[i].ismouse())
											{
												SDL_RenderClear(game_renderer);
												back.default_create(game_renderer,"BACK.jpg");
												nochangesDoub(game_renderer,DOUBPIPES1);
												nochangesCross(game_renderer,CROSSPIPES1);
												somechanges(game_renderer,DPIPES1,i);
												a.default_create(game_renderer,"start.jpg");
												SDL_RenderPresent(game_renderer);
											}
										}
										for(int i=0;i<DOUBPIPES1.size();i++)
										{
											if(DOUBPIPES1[i].ismouse())
											{
												SDL_RenderClear(game_renderer);
												back.default_create(game_renderer,"BACK.jpg");
												nochanges(game_renderer,DPIPES1);
												nochangesCross(game_renderer,CROSSPIPES1);
												somechangesDoub(game_renderer,DOUBPIPES1,i);
												a.default_create(game_renderer,"start.jpg");
												SDL_RenderPresent(game_renderer);
											}
										}
									}
									else if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE || event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_RIGHT)
									{
										while(a.isrange())
										{
											A=a.Woda().x;
											AA=a.Woda().y;
											if(a.isDpipe(DPIPES1))
											{
												a.Dpipebehaviour(game_renderer,DPIPES1);
												SDL_RenderPresent(game_renderer);
												if (a.Woda().x==360 && a.Woda().y==426)
												{
													won1 = true;
												}
											}
											else if(a.isDoubpipe(DOUBPIPES1))
											{
												cout<<a.Woda().x<<" "<<a.Woda().y<<"\n";
												a.Doubpipebehavior(game_renderer,DOUBPIPES1);
												SDL_RenderPresent(game_renderer); 
												if (a.Woda().x==360 && a.Woda().y==426)
												{
													won1 = true;
												}
											}
											else if(a.isCrosspipe(CROSSPIPES1))
											{
												a.Crosspipebehaviour(game_renderer,CROSSPIPES1);
												SDL_RenderPresent(game_renderer);
												if (a.Woda().x==360 && a.Woda().y==426)
												{
													won1 = true;
												}
											}
											B=a.Woda().x;
											BB=a.Woda().y;
											if((B-A)==0 &&(BB-AA)==0 &&!won)
											{
												break;
											}
										}
									}
								}
							}
							while (won1 && !quit)
							{
								SDL_RenderClear (game_renderer);
								SDL_Texture *back2 = IMG_LoadTexture (game_renderer, "background2.jpg");
								SDL_Rect bg2_rect = RectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
								SDL_RenderCopy (game_renderer, back2, NULL, &bg2_rect);
								SDL_DestroyTexture(back2);
								while (SDL_PollEvent(menu3_event))
								{
									if (menu3_event->type == SDL_QUIT)
											quit=true;
									if (menu3_event->type == SDL_MOUSEBUTTONDOWN)
									{
										if (menu3_event->button.button = SDL_BUTTON_LEFT)
										{
											if ((menu3_event->button.x>=440) && (menu3_event->button.x<=715) && (menu3_event->button.y>=290) && (menu3_event->button.y<=331))
											{
												choose = 1;
												won1 = false;
											}
											if ((menu3_event->button.x>=504) && (menu3_event->button.x<=633) && (menu3_event->button.y>=431) && (menu3_event->button.y<=480))
											{ 
												choose = 2;
												won1 = false;
												quit = true;
											}
										}
									}
									SDL_RenderPresent (game_renderer);
								}
							}
							if(choose==1 && !quit)
							{
								a.comeback(10,750,20);
								SDL_RenderClear (game_renderer);
								SDL_RenderCopy (game_renderer, background, NULL, &bg_rect);
								if (levels == 1)
								{
									back.default_create(game_renderer,"BACK.jpg");
								for(int i=0;i<DPIPES2.size();++i)
								{
									DPIPES2[i].default_create(game_renderer,"text1.jpg");
								}
								for(int i=0;i<DOUBPIPES2.size();++i)
								{
									DOUBPIPES2[i].default_create1(game_renderer,"double1.jpg","double2.jpg");
								}
								for(int i=0;i<CROSSPIPES2.size();++i)
								{
									CROSSPIPES2[i].default_create(game_renderer,"CrossHor.jpg","CrossVert.jpg");
								}
								a.default_create(game_renderer,"start.jpg");
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
											for(int i=1;i<DPIPES2.size();++i)
											{
												if(DPIPES2[i].ismouse())
												{
													SDL_RenderClear(game_renderer);
													back.default_create(game_renderer,"BACK.jpg");
													nochangesDoub(game_renderer,DOUBPIPES2);
													nochangesCross(game_renderer,CROSSPIPES2);
													somechanges(game_renderer,DPIPES2,i);
													a.default_create(game_renderer,"start.jpg");
													SDL_RenderPresent(game_renderer);
												}
											}
											for(int i=0;i<DOUBPIPES2.size();i++)
											{
												if(DOUBPIPES2[i].ismouse())
												{
													SDL_RenderClear(game_renderer);
													back.default_create(game_renderer,"BACK.jpg");
													nochanges(game_renderer,DPIPES2);
													nochangesCross(game_renderer,CROSSPIPES2);
													somechangesDoub(game_renderer,DOUBPIPES2,i);
													a.default_create(game_renderer,"start.jpg");
													SDL_RenderPresent(game_renderer);
												}
											}
										}
										else if((event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_RIGHT))
										{
							
											while(a.isrange() && !won)
											{
												A=a.Woda().x;
												AA=a.Woda().y;
												if(a.isDpipe(DPIPES))
												{
													a.Dpipebehaviour(game_renderer,DPIPES2);
													SDL_RenderPresent(game_renderer);
													if (a.Woda().x==310 && a.Woda().y==426)
													{
														won2 = true;
													}
 												}
												else if(a.isDoubpipe(DOUBPIPES2))
												{
													a.Doubpipebehavior(game_renderer,DOUBPIPES2);
													SDL_RenderPresent(game_renderer); 
													if (a.Woda().x==310 && a.Woda().y==426)
													{
														won2 = true;
													}
				
												}
												else if(a.isCrosspipe(CROSSPIPES2))
												{
													a.Crosspipebehaviour(game_renderer,CROSSPIPES2);
													SDL_RenderPresent(game_renderer);
													if (a.Woda().x==310 && a.Woda().y==426)
													{
														won2 = true;
													}
												}
												B=a.Woda().x;
												BB=a.Woda().y;
												if((B-A)==0 &&(BB-AA)==0 &&!won)
												{
												//	lose==true;
													break;
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
			}
		}
		SDL_DestroyWindow (game_window);
		SDL_DestroyRenderer(game_renderer);
		delete game_event; 
	}
	return 0;
}
