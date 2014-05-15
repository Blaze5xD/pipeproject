#include "std_lib_facilities.h"
#include "SDL.h"

class CrossPipe {
public:
	CrossPipe(int xcent,int ycent,int wid,int heig);
	CrossPipe();

	void default_create(SDL_Renderer* ren, string Hor,string Vert);

	vector<SDL_Point> vision();

private:
	SDL_Rect Hor;
	SDL_Rect Vert;
};

void nochangesCross(SDL_Renderer* ren,vector<CrossPipe>& a);