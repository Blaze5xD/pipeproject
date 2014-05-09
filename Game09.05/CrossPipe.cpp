/* 
		~~
	Class Cross Pipe
		~~
*/

#include "Water2.h"


CrossPipe::CrossPipe(int xcent,int ycent,int wid,int heig)
{
	Hor.x=xcent-wid/2;
	Hor.y=ycent-heig/2;
	Hor.w=wid;
	Hor.h=heig;

	Vert.x=xcent-heig/2;
	Vert.y=ycent-wid/2;
	Vert.w=heig;
	Vert.h=wid;
}

CrossPipe::CrossPipe()
{
	Hor.x=0;
	Hor.y=0;
	Hor.w=0;
	Hor.h=0;

	Vert.x=0;
	Vert.y=0;
	Vert.w=0;
	Vert.h=0;

}

vector <SDL_Point> CrossPipe::vision()
{
	vector<SDL_Point> radiusof(4);
	SDL_Point a={Hor.x,Vert.y};
	SDL_Point b={Hor.x+Hor.w,Vert.y};
	SDL_Point c={Hor.x+Hor.w,Vert.y+Vert.h};
	SDL_Point d={Hor.x,Vert.y+Vert.h};

	radiusof[0]=a;
	radiusof[1]=b;
	radiusof[2]=c;
	radiusof[3]=d;

	return radiusof;
}

void CrossPipe::default_create(SDL_Renderer *ren,string hor,string vert)
{
	SDL_Surface *BMP_CrossPipe1=SDL_LoadBMP(hor.c_str());
	SDL_Texture *CrossPipe1 = SDL_CreateTextureFromSurface(ren, BMP_CrossPipe1);
	SDL_RenderCopy(ren, CrossPipe1, NULL, &Hor);

	SDL_Surface *BMP_CrossPipe2=SDL_LoadBMP(vert.c_str());
	SDL_Texture *CrossPipe2 = SDL_CreateTextureFromSurface(ren, BMP_CrossPipe2);
	SDL_RenderCopy(ren, CrossPipe2, NULL, &Vert);

	SDL_DestroyTexture(CrossPipe1);
	SDL_DestroyTexture(CrossPipe2);
}
