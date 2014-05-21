#include "SDL.h"
#include "SDL_image.h"
#include "std_lib_facilities.h"
#include "water.h"

void manual_init(SDL_Renderer *ren,SDL_Event event,int &manualchoose,int &choose,DPipe& a,vector<DPipe>& DPIPES,vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES);

void manual_animation(SDL_Renderer *ren,SDL_Event event,int &manualchoose,int &choose,DPipe& a,vector<DPipe>& DPIPES,vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES);
//level1
void init_pipes_level_one(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_one(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int& choose,int &level);

//level2
void init_pipes_level_two(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_two(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level);

//level3
void init_pipes_level_three(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_three(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level);

//level4
void init_pipes_level_four(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_four(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level);

//level5
void init_pipes_level_five(SDL_Renderer *ren,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a);

void go_level_five(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level);