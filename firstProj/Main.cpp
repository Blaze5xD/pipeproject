#include "DirectPipe.h"
#include "DoublePipe.h"

SDL_Event event;

int main(int argc,char **argv)
{
	setlocale(LC_ALL,"RUSSIAN");

	SDL_DisplayMode displayMode;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    return 1;
	}

	int request = SDL_GetDesktopDisplayMode(0,&displayMode); 

	SDL_Window *win = SDL_CreateWindow("Trubi", 300, 300,800, 800, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
	    return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
	    return 1;
	}

	vector<DPipe> DPIPES(13);
	vector<DoublePipe> DOUBPIPES(6);

	DPipe background(400,400,800,800);
	DPipe a0(70,300,100,40);
	DPipe a1(170,300,100,40);
	DPipe a2(270,300,100,40);
	DPipe a3(370,400,100,40);
	DPipe a4(370,500,100,40);
	DPipe a5(470,600,100,40);
	DPipe a6(570,600,100,40);
	DPipe a7(670,500,100,40);
	DPipe a8(670,400,100,40);
	
	DPipe a9(370,200,100,40);
	DPipe a10(470,100,100,40);
	DPipe a11(570,100,100,40);
	DPipe a12(670,200,100,40);
	DPipe kletka(370,300,100,100);

	DoublePipe b0(370,300,70,40);
	DoublePipe b1(370,600,70,40);
	DoublePipe b2(670,600,70,40);
	DoublePipe b3(670,300,70,40);
	DoublePipe b4(370,100,70,40);
	DoublePipe b5(670,100,70,40);

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
	
	DOUBPIPES[0]=b0;
	DOUBPIPES[1]=b1;
	DOUBPIPES[2]=b2;
	DOUBPIPES[3]=b3;
	DOUBPIPES[4]=b4;
	DOUBPIPES[5]=b5;

	SDL_RenderClear(ren);
	background.default_create(ren,"newbackground.bmp");
	for(int i=0;i<DPIPES.size();++i)
	{
		DPIPES[i].default_create(ren,"text1.bmp");
	}
	for(int i=0;i<DOUBPIPES.size();++i)
	{
		DOUBPIPES[i].default_create1(ren,"double1.bmp","double2.bmp");
	}
	SDL_RenderPresent(ren); 

	bool quit=false;
	while(!quit)
	{
		 while(SDL_PollEvent(&event))
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
						SDL_RenderClear(ren);
						background.default_create(ren,"newbackground.bmp");
						nochangesDoub(ren,DOUBPIPES);
						somechanges(ren,DPIPES,i);
					}
				}
				for(int i=0;i<DOUBPIPES.size();++i)
				{
					if(DOUBPIPES[i].ismouse())
					{
						SDL_RenderClear(ren);
						background.default_create(ren,"newbackground.bmp");
						nochanges(ren,DPIPES);
						somechangesDoub(ren,DOUBPIPES,i);
					}
				}
			}
		 }
	}
	return 1;
}