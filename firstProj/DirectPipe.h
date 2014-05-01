#include "std_lib_facilities.h"
#include "SDL.h"


class DPipe {
public:
	DPipe(int xcent,int ycent,int wid,int heig);
	DPipe();

	void default_create1(SDL_Renderer *ren,string a);
	void default_create(SDL_Renderer* ren,string a);
	void spin(SDL_Renderer* ren);

	vector<SDL_Point> vision();
	vector<SDL_Point> visionRightLeft();
	vector<SDL_Point> visionUpDown();

	bool ismouse();

	void upgrade(SDL_Renderer* ren);


	int getuse() {return uses;}

	SDL_Point center();
	SDL_Rect tryba() {return Pipe;}
private:

	int uses;
	SDL_Rect Pipe1;
	SDL_Rect Pipe;
}; 

void nochanges(SDL_Renderer* ren,vector<DPipe>& a)
{
	for(int i=0;i<a.size();++i)
	{
			a[i].upgrade(ren);
	}
} 


void somechanges(SDL_Renderer* ren,vector<DPipe>& TRYBI,int num);
