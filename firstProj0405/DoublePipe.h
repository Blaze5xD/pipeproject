#include "std_lib_facilities.h"
#include "SDL.h"

extern SDL_Event event;

class DoublePipe {
public:
	DoublePipe(int xcent,int ycent,int wid12,int heig12);
	DoublePipe();

	void default_create1(SDL_Renderer* ren,string hor,string vert);
	void default_create2(SDL_Renderer* ren,string hor,string vert);
	void default_create3(SDL_Renderer* ren,string hor,string vert);
	void default_create4(SDL_Renderer* ren,string hor,string vert);

	void spin(SDL_Renderer* ren);
	void upgrade(SDL_Renderer* ren);
	bool ismouse();
	vector<SDL_Point> vision();

	int getuse() {return uses;}
	SDL_Rect HorPart1() {return Hor1;}
	SDL_Rect VertPart1() {return Vert1;}
	SDL_Rect HorPart2() {return Hor2;}
	SDL_Rect VertPart2() {return Vert2;}

private:
	int uses;
	SDL_Rect Hor1;
	SDL_Rect Vert1;
	SDL_Rect Hor2;
	SDL_Rect Vert2;
};

void nochangesDoub(SDL_Renderer* ren,vector<DoublePipe>& a);

void somechangesDoub(SDL_Renderer* ren,vector<DoublePipe>& a,int num);
