#include "std_lib_facilities.h"
#include "SDL.h"
#include "DirectPipe.h"
#include "DoublePipe.h"
#include "CrossPipe.h"


class Water {
public:
	Water(int xright,int yright,int wid,int heig);

	void default_create(SDL_Renderer* ren,string a);

	void moveright();
	void moveleft();
	void moveup();
	void movedown();

	void Dpipebehaviour(SDL_Renderer* ren,vector<DPipe> a);
	void Doubpipebehavior(SDL_Renderer* ren,vector<DoublePipe> a);
	void Crosspipebehaviour(SDL_Renderer* ren,vector<CrossPipe> a); 

	int whereiamDpipe(vector<DPipe> a);
	int whereiamDoubpipe(vector<DoublePipe> a);
	int whereiamCrosspipe(vector<CrossPipe> a);

	bool isDpipe(vector<DPipe> a);
	bool isDoubpipe(vector<DoublePipe> a);
	bool isCrosspipe(vector<CrossPipe> a);
	bool isrange();

	SDL_Rect Woda() {return Voda;}

	bool getright() {return right;}
	bool getleft() {return left;}
	bool getup() {return up;}
	bool getdown() {return down;}
private:
	bool right;
	bool left;
	bool up;
	bool down;

	SDL_Rect Voda;
};
