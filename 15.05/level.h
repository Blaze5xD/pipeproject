#include "SDL.h"
#include "SDL_image.h"
#include "std_lib_facilities.h"
#include "water.h"

void init_pipes_level_one(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_one(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int& choose,int &level);

void init_pipes_level_two(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_two(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level);

void init_pipes_level_three(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_three(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level);