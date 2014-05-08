/*		~~
	Class DoublePipe
		~~
*/

#include "DoublePipe.h"

DoublePipe::DoublePipe(int xcent,int ycent,int wid12,int heig12)
{
	uses=1;
	Hor1.x=xcent-heig12/2;
	Hor1.y=ycent-heig12/2;
	Hor1.w=wid12;
	Hor1.h=heig12;

	Hor2.x=xcent-wid12+heig12/2;
	Hor2.y=ycent-heig12/2;
	Hor2.w=wid12;
	Hor2.h=heig12;

	Vert1.x=xcent-heig12/2;
	Vert1.y=ycent-heig12/2;
	Vert1.h=wid12;
	Vert1.w=heig12;

	Vert2.x=xcent-heig12/2;
	Vert2.y=ycent-wid12+heig12/2;
	Vert2.h=wid12;
	Vert2.w=heig12;
}

DoublePipe::DoublePipe()
{
	uses=1;
	Hor1.x=0;
	Hor1.y=0;
	Hor1.w=0;
	Hor1.h=0;

	Hor2.x=0;
	Hor2.y=0;
	Hor2.w=0;
	Hor2.h=0;

	Vert1.x=0;
	Vert1.y=0;
	Vert1.h=0;
	Vert1.w=0;

	Vert2.x=0;
	Vert2.y=0;
	Vert2.h=0;
	Vert2.w=0;
}

void DoublePipe::default_create1(SDL_Renderer* ren,string hor,string vert)
{
	SDL_Surface *BMP_DoubPipe1=SDL_LoadBMP(hor.c_str());
	SDL_Texture *DoubPipe1 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe1);
	SDL_RenderCopy(ren, DoubPipe1, NULL, &Hor1);

	SDL_Surface *BMP_DoubPipe2=SDL_LoadBMP(vert.c_str());
	SDL_Texture *DoubPipe2 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe2);
	SDL_RenderCopy(ren, DoubPipe2, NULL, &Vert1);
}

void DoublePipe::default_create2(SDL_Renderer* ren,string hor,string vert)
{
	SDL_Surface *BMP_DoubPipe1=SDL_LoadBMP(hor.c_str());
	SDL_Texture *DoubPipe1 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe1);
	SDL_RenderCopy(ren, DoubPipe1, NULL, &Hor2);

	SDL_Surface *BMP_DoubPipe2=SDL_LoadBMP(vert.c_str());
	SDL_Texture *DoubPipe2 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe2);
	SDL_RenderCopy(ren, DoubPipe2, NULL, &Vert1);
}

void DoublePipe::default_create3(SDL_Renderer* ren,string hor,string vert)
{
	SDL_Surface *BMP_DoubPipe1=SDL_LoadBMP(hor.c_str());
	SDL_Texture *DoubPipe1 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe1);
	SDL_RenderCopy(ren, DoubPipe1, NULL, &Hor2);

	SDL_Surface *BMP_DoubPipe2=SDL_LoadBMP(vert.c_str());
	SDL_Texture *DoubPipe2 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe2);
	SDL_RenderCopy(ren, DoubPipe2, NULL, &Vert2);
}

void DoublePipe::default_create4(SDL_Renderer* ren,string hor,string vert)
{
	SDL_Surface *BMP_DoubPipe1=SDL_LoadBMP(hor.c_str());
	SDL_Texture *DoubPipe1 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe1);
	SDL_RenderCopy(ren, DoubPipe1, NULL, &Hor1);

	SDL_Surface *BMP_DoubPipe2=SDL_LoadBMP(vert.c_str());
	SDL_Texture *DoubPipe2 = SDL_CreateTextureFromSurface(ren, BMP_DoubPipe2);
	SDL_RenderCopy(ren, DoubPipe2, NULL, &Vert2);
}

void DoublePipe::spin(SDL_Renderer* ren)
{
	uses+=1;
	if(uses ==1)
		default_create1(ren,"Double1.bmp","Double2.bmp");
	else if(uses==2)
		default_create2(ren,"Double1.bmp","Double2.bmp");
	else if(uses==3)
		default_create3(ren,"Double1.bmp","Double2.bmp");
	else if(uses==4)
		default_create4(ren,"Double1.bmp","Double2.bmp");
	else if(uses==5)
	{
		uses-=4;
		default_create1(ren,"Double1.bmp","Double2.bmp");
	}
}

vector<SDL_Point> DoublePipe::vision()
{
	vector<SDL_Point> radiusof(4);
	SDL_Point a={Hor1.x+Hor1.h-Hor1.w,Hor1.y-Hor1.w+Hor1.h};
	SDL_Point b={Hor1.x+Hor1.w,Hor1.y-Hor1.w+Hor1.h};
	SDL_Point c={Hor1.x+Hor1.w,Hor1.y+Hor1.w};
	SDL_Point d={Hor1.x-Hor1.w+Hor1.h,Hor1.y+Hor1.w};
		radiusof[0]=a;
		radiusof[1]=b;
		radiusof[2]=c;
		radiusof[3]=d;
	return radiusof;
}

void DoublePipe::upgrade(SDL_Renderer* ren)
{
	if(uses ==1)
		default_create1(ren,"Double1.bmp","Double2.bmp");
	else if(uses==2)
		default_create2(ren,"Double1.bmp","Double2.bmp");
	else if(uses==3)
		default_create3(ren,"Double1.bmp","Double2.bmp");
	else if(uses==4)
		default_create4(ren,"Double1.bmp","Double2.bmp");
	else if(uses==5)
	{
		uses-=4;
		default_create1(ren,"Double1.bmp","Double2.bmp");
	}
}

bool DoublePipe::ismouse()
{
	vector<SDL_Point> points=vision();
	if((event.button.x>points[0].x && event.button.x<points[1].x) && (event.button.y>points[0].y && event.button.y<points[2].y))
		return true;
	else
		return false;
}

void nochangesDoub(SDL_Renderer* ren,vector<DoublePipe>& a)
{
	for(int i=0;i<a.size();++i)
	{
			a[i].upgrade(ren);
	}
}

void somechangesDoub(SDL_Renderer* ren,vector<DoublePipe>& a,int num)
{
	for(int i=0;i<a.size();++i)
	{
		if(i==num)
			a[i].spin(ren);
		else
			a[i].upgrade(ren);
	}
	SDL_RenderPresent(ren);
}