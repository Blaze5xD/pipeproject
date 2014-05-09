#include "game.h"

class DPipe {
public:
	DPipe(int xcent,int ycent,int wid,int heig);

	void default_create1(SDL_Renderer *ren,string a);
	void default_create(SDL_Renderer* ren,string a);
	void spin(SDL_Renderer* ren);

	void upgrade(SDL_Renderer* ren);

	int width() {return Pipe.w;}
	int width1() {return Pipe1.w;}

	int height() {return Pipe.h;}
	int height1() {return Pipe1.h;}

	SDL_Point center();
	SDL_Rect tryba() {return Pipe;}
private:

	int uses;
	SDL_Rect Pipe1;
	SDL_Rect Pipe;
}; 

//создаем трубу по указанию центра
DPipe::DPipe(int xcent,int ycent,int wid,int heig)
{
	uses=1;

	Pipe.x=xcent-0.5*wid;
	Pipe.y=ycent-0.5*heig;
	Pipe.w=wid;
	Pipe.h=heig;

	Pipe1.x=xcent-0.5*heig;
	Pipe1.y=ycent-0.5*wid;
	Pipe1.w=heig;
	Pipe1.h=wid;
}

SDL_Point DPipe::center()
{
	SDL_Point centr={Pipe.x+0.5*Pipe.w,Pipe.y+0.5*Pipe.h};
	return centr;
}


void DPipe::default_create(SDL_Renderer* ren,string a)
{

	SDL_Surface *BMP_DPipe=SDL_LoadBMP(a.c_str());
	if (BMP_DPipe == nullptr)
	{
	    cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
	}
	SDL_Texture *DPipe = SDL_CreateTextureFromSurface(ren, BMP_DPipe);

	SDL_RenderCopy(ren, DPipe, NULL, &Pipe);
}

void DPipe::default_create1(SDL_Renderer* ren,string a)
{

	SDL_Surface *BMP_DPipe=SDL_LoadBMP(a.c_str());
	if (BMP_DPipe == nullptr)
	{
	    cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
	}
	SDL_Texture *DPipe = SDL_CreateTextureFromSurface(ren, BMP_DPipe);

	SDL_RenderCopy(ren, DPipe, NULL, &Pipe1);
	return 
}


void DPipe::spin(SDL_Renderer* ren)
{
	uses+=1;
	if(uses ==1)
		default_create(ren,"text1.bmp");
	else if(uses==2)
		default_create1(ren,"text2.bmp");
	else if(uses==3)
		default_create(ren,"text3.bmp");
	else if(uses==4)
		default_create1(ren,"text4.bmp");
	else if(uses==5)
	{
		uses-=4;
		default_create(ren,"text1.bmp");
	}
} 

void DPipe::upgrade(SDL_Renderer *ren)
{
	if(uses ==1)
		default_create(ren,"text1.bmp");
	else if(uses==2)
		default_create1(ren,"text2.bmp");
	else if(uses==3)
		default_create(ren,"text3.bmp");
	else if(uses==4)
		default_create1(ren,"text4.bmp");
	else if(uses==5)
	{
		uses-=4;
		default_create(ren,"text1.bmp");
	}
}