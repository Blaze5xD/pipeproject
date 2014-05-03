#include "std_lib_facilities.h"
#include "SDL.h"
#include "DirectPipe.h"
#include "DoublePipe.h"


class Water {
public:
	Water(int xright,int yright,int wid,int heig);

	void default_create1(SDL_Renderer* ren,string a);
	void default_create2(SDL_Renderer * ren,string a);
	void default_create3(SDL_Renderer* ren,string a);
	void default_create4(SDL_Renderer * ren,string a);

	void moveright();
	void moveleft();
	void moveup();
	void movedown();

	void Dpipebehaviour(SDL_Renderer* ren,vector<DPipe> a);
	void Doubpipebehavior(SDL_Renderer* ren,vector<DoublePipe> a);

	int whereiamDpipe(vector<DPipe> a);
	int whereiamDoubpipe(vector<DoublePipe> a);

	bool isDpipe(vector<DPipe> a);
	bool isDoubpipe(vector<DoublePipe> a);
	bool isrange();

	SDL_Rect Voda1() {return Hor1;}
	SDL_Rect Voda2() {return Vert1;}
	SDL_Rect Voda3() {return Hor2;}
	SDL_Rect Voda4() {return Vert2;}

	bool getright() {return right;}
	bool getleft() {return left;}
	bool getup() {return up;}
	bool getdown() {return down;}
private:
	bool right;
	bool left;
	bool up;
	bool down;

	SDL_Rect Hor1;
	SDL_Rect Vert1;
	SDL_Rect Hor2;
	SDL_Rect Vert2;
};
