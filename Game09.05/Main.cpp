
#include "water.h"
#include "functions.h"

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

	SDL_Window *win = SDL_CreateWindow("Trubi", 300, 300,1200, 800, SDL_WINDOW_SHOWN);
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
	for(int i=0;i<CROSSPIPES.size();++i)
	{
		CROSSPIPES[i].default_create(ren,"CrossHor.bmp","CrossVert.bmp");
	}
	a.default_create(ren,"start.bmp");
	d0.default_create(ren,"kletka.bmp");
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
				for(int i=1;i<DPIPES.size();++i) 
				{
					
					if(DPIPES[i].ismouse())
					{
						SDL_RenderClear(ren);
						background.default_create(ren,"newbackground.bmp");
						nochangesDoub(ren,DOUBPIPES);
						nochangesCross(ren,CROSSPIPES);
						somechanges(ren,DPIPES,i); 
						a.default_create(ren,"start.bmp");
						d0.default_create(ren,"kletka.bmp");
						SDL_RenderPresent(ren);
					}
				}
				for(int i=0;i<DOUBPIPES.size();++i)
				{
					if(DOUBPIPES[i].ismouse())
					{
						SDL_RenderClear(ren);
						background.default_create(ren,"newbackground.bmp");
						nochanges(ren,DPIPES);
						nochangesCross(ren,CROSSPIPES);
						somechangesDoub(ren,DOUBPIPES,i);
						a.default_create(ren,"start.bmp");
						d0.default_create(ren,"kletka.bmp"); 
						SDL_RenderPresent(ren);
					}
				}
			}

			else if(event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_RIGHT)
			{
				while(a.isrange())
				{
					if(a.isDpipe(DPIPES))
					{
						a.Dpipebehaviour(ren,DPIPES);
						SDL_RenderPresent(ren);
					}

					else if(a.isDoubpipe(DOUBPIPES))
					{
						a.Doubpipebehavior(ren,DOUBPIPES);
						SDL_RenderPresent(ren); 
					}

					else if(a.isCrosspipe(CROSSPIPES))
					{
						a.Crosspipebehaviour(ren,CROSSPIPES);
						SDL_RenderPresent(ren);
					}
					else if(a.Woda().x==960 && a.Woda().y==330)
					{
						cout<<"POBEDA\n";
						//animation include.
					}
					else
						break;

				}
			}
		 }
	}
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 1;
}