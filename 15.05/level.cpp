#include "level.h"

//level1
void init_pipes_level_one(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe> & DOUBPIPES,vector<CrossPipe> & CROSSPIPES,Water& a)
{
	Water EASY(10,750,20,20);
	a=EASY;
	vector<DPipe> A(4);
	vector<DoublePipe> B(11);
	vector<CrossPipe> C(1);
	DPIPES=A;
	DOUBPIPES=B;
	CROSSPIPES=C;

	DPipe a0(20,750,50,20);
	DPipe a1(70,700,50,20);
	DPipe a2(220,500,50,20);
	DPipe a3(270,450,50,20);
	
	DoublePipe b0(70,750,35,20);
	DoublePipe b1(70,650,35,20);
	DoublePipe b2(170,650,35,20);
	DoublePipe b3(170,700,35,20);
	DoublePipe b4(120,700,35,20);
	DoublePipe b5(120,600,35,20);
	DoublePipe b6(170,600,35,20);
	DoublePipe b7(170,550,35,20);
	DoublePipe b8(220,550,35,20);
	DoublePipe b9(220,450,35,20);
	DoublePipe b10(320,450,35,20);

	CrossPipe c0(120,650,50,20);
	DPIPES[0]=a0;
	DPIPES[1]=a1;
	DPIPES[2]=a2;
	DPIPES[3]=a3;

	DOUBPIPES[0]=b0;
	DOUBPIPES[1]=b1;
	DOUBPIPES[2]=b2;
	DOUBPIPES[3]=b3;
	DOUBPIPES[4]=b4;
	DOUBPIPES[5]=b5;
	DOUBPIPES[6]=b6;
	DOUBPIPES[7]=b7;
	DOUBPIPES[8]=b8;
	DOUBPIPES[9]=b9;
	DOUBPIPES[10]=b10;

	CROSSPIPES[0]=c0;

	for(int i=0;i<DPIPES.size();++i)
	{
		DPIPES[i].default_create(game_renderer,"text1.jpg");
	}
	for(int i=0;i<DOUBPIPES.size();++i)
	{
		DOUBPIPES[i].default_create1(game_renderer,"double1.jpg","double2.jpg");
	}
	for(int i=0;i<CROSSPIPES.size();++i)
	{
		CROSSPIPES[i].default_create(game_renderer,"CrossHor.jpg","CrossVert.jpg");
	}
	a.default_create(game_renderer,"start.jpg");
	SDL_RenderPresent(game_renderer);
}

void go_level_one(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe> & DOUBPIPES,vector<CrossPipe> & CROSSPIPES,Water& a,DPipe back,int &choose,int &level)
{
	int AA,BB,A,B;
	if(event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=483) && (event.button.x<=708) && (event.button.y>=0) && (event.button.y<=56))
		{
			level = 0; 
		}
		for(int i=1;i<DPIPES.size();++i)
		{
			if(DPIPES[i].ismouse())
			{
				SDL_RenderClear(game_renderer);
				back.default_create(game_renderer,"BACK.jpg");
				nochangesDoub(game_renderer,DOUBPIPES);
				nochangesCross(game_renderer,CROSSPIPES);
				somechanges(game_renderer,DPIPES,i);
				a.default_create(game_renderer,"start.jpg");
				SDL_RenderPresent(game_renderer);
			}
		}
		for(int i=0;i<DOUBPIPES.size();i++)
		{
			if(DOUBPIPES[i].ismouse())
			{
				SDL_RenderClear(game_renderer);
				back.default_create(game_renderer,"BACK.jpg");
				nochanges(game_renderer,DPIPES);
				nochangesCross(game_renderer,CROSSPIPES);
				somechangesDoub(game_renderer,DOUBPIPES,i);
				a.default_create(game_renderer,"start.jpg");
				SDL_RenderPresent(game_renderer);
			}
		}
	}
	else if((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_RIGHT))
	{	
		while(a.isrange())
		{
			A=a.Woda().x;
			AA=a.Woda().y;
			if(a.isDpipe(DPIPES))
			{
				a.Dpipebehaviour(game_renderer,DPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==310 && a.Woda().y==426)
				{
					choose += 1;
				}
 			}
			else if(a.isDoubpipe(DOUBPIPES))
			{
				a.Doubpipebehavior(game_renderer,DOUBPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==310 && a.Woda().y==426)
				{
					choose += 1;
				}
			}
			else if(a.isCrosspipe(CROSSPIPES))
			{
				a.Crosspipebehaviour(game_renderer,CROSSPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==310 && a.Woda().y==426)
				{
					choose += 1;
				}
			}
			B=a.Woda().x;
			BB=a.Woda().y;
			if((B-A)==0 &&(BB-AA)==0)
			{
				break;
			}
		}
	}
}
//level2
void init_pipes_level_two(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe> & DOUBPIPES,vector<CrossPipe> & CROSSPIPES,Water& a)
{
	Water EASY(10,750,20,20);
	a=EASY;
	vector<DPipe> A(18);
	vector<DoublePipe> B(13);
	vector<CrossPipe> C(1);
	DPIPES=A;
	DOUBPIPES=B;
	CROSSPIPES=C;

	DPipe A0(20,750,50,20);
	DPipe A1(70,700,50,20);
	DPipe A2(120,650,50,20);
	DPipe A3(170,700,50,20);
	DPipe A4(220,700,50,20);
	DPipe A5(320,500,50,20);
	DPipe A6(320,600,50,20);
	DPipe A7(370,600,50,20);
	DPipe A8(420,600,50,20);
	DPipe A9(420,650,50,20);
	DPipe A10(370,650,50,20);
	DPipe A11(320,650,50,20);
	DPipe A12(270,650,50,20);
	DPipe A13(220,600,50,20);
	DPipe A14(220,500,50,20);
	DPipe A15(270,450,50,20);
	DPipe A16(320,450,50,20);
	DPipe A17(170,600,50,20);

	DoublePipe B0(70,750,35,20);
	DoublePipe B1(70,650,35,20);
	DoublePipe B2(170,650,35,20);
	DoublePipe B3(170,750,35,20);
	DoublePipe B4(220,750,35,20);
	DoublePipe B5(170,550,35,20);
	DoublePipe B6(270,550,35,20);
	DoublePipe B7(270,600,35,20);
	DoublePipe B8(470,600,35,20);
	DoublePipe B9(470,650,35,20);
	DoublePipe B10(220,650,35,20);
	DoublePipe B11(220,450,35,20);
	DoublePipe B12(370,450,35,20);

	CrossPipe C0(220,550,50,20);

	DPIPES[0]=A0;
	DPIPES[1]=A1;
	DPIPES[2]=A2;
	DPIPES[3]=A3;
	DPIPES[4]=A4;
	DPIPES[5]=A5;
	DPIPES[6]=A6;
	DPIPES[7]=A7;
	DPIPES[8]=A8;
	DPIPES[9]=A9;
	DPIPES[10]=A10;
	DPIPES[11]=A11;
	DPIPES[12]=A12;
	DPIPES[13]=A13;
	DPIPES[14]=A14;
	DPIPES[15]=A15;
	DPIPES[16]=A16;
	DPIPES[17]=A17;

	DOUBPIPES[0]=B0;
	DOUBPIPES[1]=B1;
	DOUBPIPES[2]=B2;
	DOUBPIPES[3]=B3;
	DOUBPIPES[4]=B4;
	DOUBPIPES[5]=B5;
	DOUBPIPES[6]=B6;
	DOUBPIPES[7]=B7;
	DOUBPIPES[8]=B8;
	DOUBPIPES[9]=B9;
	DOUBPIPES[10]=B10;
	DOUBPIPES[11]=B11;
	DOUBPIPES[12]=B12;

	CROSSPIPES[0]=C0;

	for(int i=0;i<DPIPES.size();++i)
	{
		DPIPES[i].default_create(game_renderer,"text1.jpg");
	}
	for(int i=0;i<DOUBPIPES.size();++i)
	{
		DOUBPIPES[i].default_create1(game_renderer,"double1.jpg","double2.jpg");
	}
	for(int i=0;i<CROSSPIPES.size();++i)
	{
		CROSSPIPES[i].default_create(game_renderer,"CrossHor.jpg","CrossVert.jpg");
	}
	a.default_create(game_renderer,"start.jpg");
	SDL_RenderPresent(game_renderer);
}

void go_level_two(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe> & DOUBPIPES,vector<CrossPipe> & CROSSPIPES,Water& a,DPipe back,int &choose,int &level)
{
	int AA,BB,A,B;
	if(event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=483) && (event.button.x<=708) && (event.button.y>=0) && (event.button.y<=56))
		{
			level = 0; 
		}
		for(int i=1;i<DPIPES.size();++i)
		{
			if(DPIPES[i].ismouse())
			{
				SDL_RenderClear(game_renderer);
				back.default_create(game_renderer,"BACK.jpg");
				nochangesDoub(game_renderer,DOUBPIPES);
				nochangesCross(game_renderer,CROSSPIPES);
				somechanges(game_renderer,DPIPES,i);
				a.default_create(game_renderer,"start.jpg");
				SDL_RenderPresent(game_renderer);
			}
		}
		for(int i=0;i<DOUBPIPES.size();i++)
		{
			if(DOUBPIPES[i].ismouse())
			{
				SDL_RenderClear(game_renderer);
				back.default_create(game_renderer,"BACK.jpg");
				nochanges(game_renderer,DPIPES);
				nochangesCross(game_renderer,CROSSPIPES);
				somechangesDoub(game_renderer,DOUBPIPES,i);
				a.default_create(game_renderer,"start.jpg");
				SDL_RenderPresent(game_renderer);
			}
		}
	}
	else if((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_RIGHT))
	{	
		while(a.isrange())
		{
			A=a.Woda().x;
			AA=a.Woda().y;
			if(a.isDpipe(DPIPES))
			{
				a.Dpipebehaviour(game_renderer,DPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==360 && a.Woda().y==426)
				{
					choose += 1;
				}
 			}
			else if(a.isDoubpipe(DOUBPIPES))
			{
				a.Doubpipebehavior(game_renderer,DOUBPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==360 && a.Woda().y==426)
				{
					choose += 1;
				}
			}
			else if(a.isCrosspipe(CROSSPIPES))
			{
				a.Crosspipebehaviour(game_renderer,CROSSPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==360 && a.Woda().y==426)
				{
					choose += 1;
				}
			}
			B=a.Woda().x;
			BB=a.Woda().y;
			if((B-A)==0 &&(BB-AA)==0)
			{
				break;
			}
		}
	}			
}

//level3
void init_pipes_level_three(SDL_Renderer *game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a)
{
	Water EASY(10,750,20,20);
	a=EASY;
	vector<DPipe> A(33);
	vector<DoublePipe> B(18);
	vector<CrossPipe> C(2);
	DPIPES=A;
	DOUBPIPES=B;
	CROSSPIPES=C;

	DPipe AA0(20,750,50,20);
	DPipe AA1(70,700,50,20);
	DPipe AA2(120,600,50,20);
	DPipe AA3(120,500,50,20);
	DPipe AA5(70,450,50,20);
	DPipe AA6(20,500,50,20);
	DPipe AA8(70,550,50,20);
	DPipe AA9(170,550,50,20);
	DPipe AA10(220,600,50,20);
	DPipe AA11(220,650,50,20);
	DPipe AA12(220,700,50,20);
	DPipe AA13(270,750,50,20);
	DPipe AA14(320,750,50,20);
	DPipe AA15(370,750,50,20);
	DPipe AA16(420,750,50,20);
	DPipe AA17(470,750,50,20);
	DPipe AA18(520,750,50,20);
	DPipe AA19(570,750,50,20);
	DPipe AA20(620,700,50,20);
	DPipe AA21(620,650,50,20);
	DPipe AA22(620,600,50,20);
	DPipe AA23(620,550,50,20);
	DPipe AA24(620,500,50,20);
	DPipe AA26(570,450,50,20);
	DPipe AA27(270,550,50,20);
	DPipe AA28(420,550,50,20);
	DPipe AA29(470,550,50,20);
	DPipe AA30(520,550,50,20);
	DPipe AA31(520,600,50,20);
	DPipe AA32(470,600,50,20);
	DPipe AA33(420,600,50,20);
	DPipe AA34(370,600,50,20);
	DPipe AA35(320,550,50,20);

	DoublePipe BB0(70,750,35,20);
	DoublePipe BB1(70,650,35,20);
	DoublePipe BB2(120,650,35,20);
	DoublePipe BB3(120,450,35,20);
	DoublePipe BB4(20,450,35,20);
	DoublePipe BB5(20,550,35,20);
	DoublePipe BB6(220,550,35,20);
	DoublePipe BB7(220,750,35,20);
	DoublePipe BB8(620,750,35,20);
	DoublePipe BB9(620,450,35,20);
	DoublePipe BB10(520,450,35,20);
	DoublePipe BB11(220,500,35,20);
	DoublePipe BB12(370,500,35,20);
	DoublePipe BB15(370,550,35,20);
	DoublePipe BB16(570,550,35,20);
	DoublePipe BB17(570,600,35,20);
	DoublePipe BB18(320,600,35,20);
	DoublePipe BB19(320,450,35,20);

	CrossPipe CC0(120,550,50,20);
	CrossPipe CC1(320,500,50,20);

	DPIPES[0]=AA0;
	DPIPES[1]=AA1;
	DPIPES[2]=AA2;
	DPIPES[3]=AA3;
	DPIPES[4]=AA5;
	DPIPES[5]=AA6;
	DPIPES[6]=AA8;
	DPIPES[7]=AA9;
	DPIPES[8]=AA10;
	DPIPES[9]=AA11;
	DPIPES[10]=AA12;
	DPIPES[11]=AA13;
	DPIPES[12]=AA14;
	DPIPES[13]=AA15;
	DPIPES[14]=AA16;
	DPIPES[15]=AA17;
	DPIPES[16]=AA18;
	DPIPES[17]=AA19;
	DPIPES[18]=AA20;
	DPIPES[19]=AA21;
	DPIPES[20]=AA22;
	DPIPES[21]=AA23;
	DPIPES[22]=AA24;
	DPIPES[23]=AA26;
	DPIPES[24]=AA27;
	DPIPES[25]=AA28;
	DPIPES[26]=AA29;
	DPIPES[27]=AA30;
	DPIPES[28]=AA31;
	DPIPES[29]=AA32;
	DPIPES[30]=AA33;
	DPIPES[31]=AA34;
	DPIPES[32]=AA35;

	DOUBPIPES[0]=BB0;
	DOUBPIPES[1]=BB1;
	DOUBPIPES[2]=BB2;
	DOUBPIPES[3]=BB3;
	DOUBPIPES[4]=BB4;
	DOUBPIPES[5]=BB5;
	DOUBPIPES[6]=BB6;
	DOUBPIPES[7]=BB7;
	DOUBPIPES[8]=BB8;
	DOUBPIPES[9]=BB9;
	DOUBPIPES[10]=BB10;
	DOUBPIPES[11]=BB11;
	DOUBPIPES[12]=BB12;
	DOUBPIPES[13]=BB15;
	DOUBPIPES[14]=BB16;
	DOUBPIPES[15]=BB17;
	DOUBPIPES[16]=BB18;
	DOUBPIPES[17]=BB19;

	CROSSPIPES[0]=CC0;
	CROSSPIPES[1]=CC1;

	for(int i=0;i<DPIPES.size();++i)
	{
		DPIPES[i].default_create(game_renderer,"text1.jpg");
	}
	for(int i=0;i<DOUBPIPES.size();++i)
	{
		DOUBPIPES[i].default_create1(game_renderer,"double1.jpg","double2.jpg");
	}
	for(int i=0;i<CROSSPIPES.size();++i)
	{
		CROSSPIPES[i].default_create(game_renderer,"CrossHor.jpg","CrossVert.jpg");
	}
	a.default_create(game_renderer,"start.jpg");
	SDL_RenderPresent(game_renderer);
}

void go_level_three(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level)
{
	int AA,BB,A,B;
	if(event.type==SDL_MOUSEBUTTONDOWN &&  event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=483) && (event.button.x<=708) && (event.button.y>=0) && (event.button.y<=56))
		{
			level = 0; 
		}
		for(int i=1;i<DPIPES.size();++i)
		{
			if(DPIPES[i].ismouse())
			{
				SDL_RenderClear(game_renderer);
				back.default_create(game_renderer,"BACK.jpg");
				nochangesDoub(game_renderer,DOUBPIPES);
				nochangesCross(game_renderer,CROSSPIPES);
				somechanges(game_renderer,DPIPES,i);
				a.default_create(game_renderer,"start.jpg");
				SDL_RenderPresent(game_renderer);
			}
		}
		for(int i=0;i<DOUBPIPES.size();i++)
		{
			if(DOUBPIPES[i].ismouse())
			{
				SDL_RenderClear(game_renderer);
				back.default_create(game_renderer,"BACK.jpg");
				nochanges(game_renderer,DPIPES);
				nochangesCross(game_renderer,CROSSPIPES);
				somechangesDoub(game_renderer,DOUBPIPES,i);
				a.default_create(game_renderer,"start.jpg");
				SDL_RenderPresent(game_renderer);
			}
		}
	}
	else if((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_RIGHT))
	{	
		while(a.isrange())
		{
			A=a.Woda().x;
			AA=a.Woda().y;
			if(a.isDpipe(DPIPES))
			{
				a.Dpipebehaviour(game_renderer,DPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==510 && a.Woda().y==425)
				{
					choose += 1;
				}
 			}
			else if(a.isDoubpipe(DOUBPIPES))
			{
				a.Doubpipebehavior(game_renderer,DOUBPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==510 && a.Woda().y==425)
				{
					choose += 1;
				}
			}
			else if(a.isCrosspipe(CROSSPIPES))
			{
				a.Crosspipebehaviour(game_renderer,CROSSPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==510 && a.Woda().y==425)
				{
					choose += 1;
				}
			}
			B=a.Woda().x;
			BB=a.Woda().y;
			if((B-A)==0 &&(BB-AA)==0)
			{
				break;
			}
		}
	}			
}