/*

	~Class DPipe~

*/

#include "std_lib_facilities.h"
#include "SDL.h"

const int SCREEN_WIDTH=700;
const int SCREEN_HEIGHT=700;
SDL_Event event;


class DPipe {
public:
	DPipe(int xcent,int ycent,int wid,int heig);
	DPipe();

	void default_create1(SDL_Renderer *ren,string a);
	void default_create(SDL_Renderer* ren,string a);
	void spin(SDL_Renderer* ren);

	vector<SDL_Point> vision();

	bool ismouse();

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

DPipe::DPipe()
{
	uses=1;
	Pipe.x=0;
	Pipe.y=0;
	Pipe.w=0;
	Pipe.h=0;

	Pipe1.x=0;
	Pipe1.y=0;
	Pipe1.w=0;
	Pipe1.h=0;
}

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

vector<SDL_Point> DPipe::vision()
{
	vector<SDL_Point> radiusof(4);

	if(Pipe.w>Pipe.h)
	{
		SDL_Point a={Pipe.x,Pipe.y-Pipe.w/2+Pipe.h/2};
		SDL_Point b={Pipe.x+Pipe.w,Pipe.y-Pipe.w/2+Pipe.h/2};
		SDL_Point c={Pipe.x+Pipe.w,Pipe.y+Pipe.w/2+Pipe.h/2};
		SDL_Point d={Pipe.x,Pipe.y+Pipe.w/2+Pipe.h/2};
		radiusof[0]=a;
		radiusof[1]=b;
		radiusof[2]=c;
		radiusof[3]=d;
	}

	else if(Pipe.h>Pipe.w)
	{
		SDL_Point a={Pipe1.x+Pipe1.w/2-Pipe1.h/2,Pipe1.y};
		SDL_Point b={Pipe1.x+Pipe1.w/2+Pipe1.h/2,Pipe1.y};
		SDL_Point c={Pipe1.x+Pipe1.w/2+Pipe1.h/2,Pipe1.y+Pipe1.h};
		SDL_Point d={Pipe1.x+Pipe1.w/2-Pipe1.h/2,Pipe1.y+Pipe1.h};
		radiusof[0]=a;
		radiusof[1]=b;
		radiusof[2]=c;
		radiusof[3]=d;
	}

	return radiusof;
}

bool DPipe::ismouse()
{
	vector<SDL_Point> points=vision();
	if((event.button.x>=points[0].x && event.button.x<=points[1].x) && (event.button.y>=points[0].y && event.button.y<=points[2].y))
		return true;
	else
		return false;
}

void somechanges(SDL_Renderer* ren,vector<DPipe>& TRYBI,int num)
{
	for(int i=0;i<TRYBI.size();++i)
	{
		if(i==num)
			TRYBI[i].spin(ren);
		else
			TRYBI[i].upgrade(ren);
	}
	SDL_RenderPresent(ren);
}