#include "level.h"

//manual
void manual_init(SDL_Renderer *ren,SDL_Event event,int &manualchoose, int &choose,DPipe& a,vector<DPipe>& DPIPES,vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES)
{
	vector<DPipe> A(1);
	vector<DoublePipe> B(1);
	vector<CrossPipe> C(1);
	DPipe back(600,400,1200,800);
	back.default_create(ren,"manual.jpg");
	DPipe pipe1(150,250,100,40);
	DoublePipe pipe2(150,400,70,40);
	CrossPipe pipe3(150,550,100,40);
	DPIPES=A; DOUBPIPES=B; CROSSPIPES=C;
	a=back;
	DPIPES[0]=pipe1;
	DOUBPIPES[0]=pipe2;
	CROSSPIPES[0]=pipe3;
	pipe1.default_create(ren,"text1.jpg");
	pipe2.default_create1(ren,"double1.jpg","double2.jpg");
	pipe3.default_create(ren,"CrossHor.jpg","CrossVert.jpg");
	SDL_RenderPresent(ren);
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=55) && (event.button.x<=172) && (event.button.y>=710) && (event.button.y<=734))
		{
			choose = 0; 
		}
		else if ((event.button.x>=952) && (event.button.x<=1039) && (event.button.y>713) && (event.button.y<=735))
		{
			choose = -1; 
		}
		if ((event.button.x>=100) && (event.button.x<=231) && (event.button.y>=200) && (event.button.y<=272))
		{
			manualchoose = 1;
		}

		else if ((event.button.x>=128) && (event.button.x<=172) && (event.button.y>=379) && (event.button.y<=436))
		{
			manualchoose = 1; 
		}

		else if ((event.button.x>=104) && (event.button.x<=192) && (event.button.y>=500) && (event.button.y<=591))
		{
			manualchoose = 1; 
		}
	}
}

void manual_animation(SDL_Renderer *ren,SDL_Event event,int &manualchoose,int &choose,DPipe& a,vector<DPipe>& DPIPES,vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
	{
		if ((event.button.x>=55) && (event.button.x<=172) && (event.button.y>=710) && (event.button.y<=734))
		{
			choose = 0; 
			manualchoose = 0;
		}
		else if ((event.button.x>=952) && (event.button.x<=1039) && (event.button.y>713) && (event.button.y<=735))
		{
			choose = -1; 
		}
		if ((event.button.x>=100) && (event.button.x<=231) && (event.button.y>=200) && (event.button.y<=272))
		{
			SDL_RenderClear(ren);
			a.default_create(ren,"manual.jpg");
			nochangesDoub(ren,DOUBPIPES);
			nochangesCross(ren,CROSSPIPES);
			somechanges(ren,DPIPES,0);
			SDL_RenderPresent(ren);
		}

		else if ((event.button.x>=128) && (event.button.x<=172) && (event.button.y>=379) && (event.button.y<=436))
		{
			SDL_RenderClear(ren);
			a.default_create(ren,"manual.jpg");
			nochanges(ren,DPIPES);
			nochangesCross(ren,CROSSPIPES);
			somechangesDoub(ren,DOUBPIPES,0);
			SDL_RenderPresent(ren);
		}
	}

}
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
				else if (a.Woda().x==10 && a.Woda().y==425)
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
				else if (a.Woda().x==10 && a.Woda().y==425)
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
				else if (a.Woda().x==10 && a.Woda().y==425)
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

//level4
void init_pipes_level_four(SDL_Renderer *game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a)
{
	Water EASY(10,750,20,20);
	a=EASY;
	vector<DPipe> A(15);
	vector<DoublePipe> B(30);
	vector<CrossPipe> C(8);
	DPIPES=A;
	DOUBPIPES=B;
	CROSSPIPES=C;

	DPipe AA0(20,750,50,20);
	DPipe AA1(320,750,50,20);
	DPipe AA2(120,700,50,20);
	DPipe AA3(470,700,50,20);
	DPipe AA4(170,650,50,20);
	DPipe AA5(220,650,50,20);
	DPipe AA6(170,550,50,20);
	DPipe AA7(370,550,50,20);
	DPipe AA8(170,500,50,20);
	DPipe AA9(320,500,50,20);
	DPipe AA10(470,500,50,20);
	DPipe AA11(120,450,50,20);
	DPipe AA12(320,450,50,20);
	DPipe AA13(420,450,50,20);
	DPipe AA14(70,750,50,20);

	DoublePipe BB0(120,750,35,20);
	DoublePipe BB1(220,750,35,20);
	DoublePipe BB2(420,750,35,20);
	DoublePipe BB3(470,750,35,20);
	DoublePipe BB4(170,700,35,20);
	DoublePipe BB5(220,700,35,20);
	DoublePipe BB6(270,700,35,20);
	DoublePipe BB7(370,700,35,20);
	DoublePipe BB8(420,700,35,20);
	DoublePipe BB9(70,650,35,20);
	DoublePipe BB10(270,650,35,20);
	DoublePipe BB11(320,650,35,20);
	DoublePipe BB12(370,650,35,20);
	DoublePipe BB13(420,650,35,20);
	DoublePipe BB14(470,650,35,20);
	DoublePipe BB15(70,600,35,20);
	DoublePipe BB16(120,600,35,20);
	DoublePipe BB17(220,600,35,20);
	DoublePipe BB18(270,600,35,20);
	DoublePipe BB19(370,600,35,20);
	DoublePipe BB20(470,600,35,20);
	DoublePipe BB21(120,550,35,20);
	DoublePipe BB22(270,550,35,20);
	DoublePipe BB23(320,550,35,20);
	DoublePipe BB24(420,550,35,20);
	DoublePipe BB25(470,550,35,20);
	DoublePipe BB26(220,500,35,20);
	DoublePipe BB27(270,500,35,20);
	DoublePipe BB28(370,500,35,20);
	DoublePipe BB29(470,450,35,20);


	CrossPipe CC0(170,750,50,20);
	CrossPipe CC1(370,750,50,20);
	CrossPipe CC2(320,700,50,20);
	CrossPipe CC3(120,650,50,20);
	CrossPipe CC4(320,600,50,20);
	CrossPipe CC5(420,600,50,20);
	CrossPipe CC6(220,550,50,20);
	CrossPipe CC7(120,500,50,20);

	DPIPES[0]=AA0;
	DPIPES[1]=AA1;
	DPIPES[2]=AA2;
	DPIPES[3]=AA3;
	DPIPES[4]=AA4;
	DPIPES[5]=AA5;
	DPIPES[6]=AA6;
	DPIPES[7]=AA7;
	DPIPES[8]=AA8;
	DPIPES[9]=AA9;
	DPIPES[10]=AA10;
	DPIPES[11]=AA11;
	DPIPES[12]=AA12;
	DPIPES[13]=AA13;
	DPIPES[14]=AA14;

	
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
	DOUBPIPES[13]=BB13;
	DOUBPIPES[14]=BB14;
	DOUBPIPES[15]=BB15;
	DOUBPIPES[16]=BB16;
	DOUBPIPES[17]=BB17;
	DOUBPIPES[18]=BB18;
	DOUBPIPES[19]=BB19;
	DOUBPIPES[20]=BB20;
	DOUBPIPES[21]=BB21;
	DOUBPIPES[22]=BB22;
	DOUBPIPES[23]=BB23;
	DOUBPIPES[24]=BB24;
	DOUBPIPES[25]=BB25;
	DOUBPIPES[26]=BB26;
	DOUBPIPES[27]=BB27;
	DOUBPIPES[28]=BB28;
	DOUBPIPES[29]=BB29;

	CROSSPIPES[0]=CC0;
	CROSSPIPES[1]=CC1;
	CROSSPIPES[2]=CC2;
	CROSSPIPES[3]=CC3;
	CROSSPIPES[4]=CC4;
	CROSSPIPES[5]=CC5;
	CROSSPIPES[6]=CC6;
	CROSSPIPES[7]=CC7;
	

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

void go_level_four(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level)
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
				if (a.Woda().x==110 && a.Woda().y==425)
				{
					choose += 1;
				}
 			}
			else if(a.isDoubpipe(DOUBPIPES))
			{
				a.Doubpipebehavior(game_renderer,DOUBPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==110 && a.Woda().y==425)
				{
					choose += 1;
				}
			}
			else if(a.isCrosspipe(CROSSPIPES))
			{
				a.Crosspipebehaviour(game_renderer,CROSSPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==110 && a.Woda().y==425)
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

//level5
void init_pipes_level_five(SDL_Renderer *game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a)
{
	Water EASY(10,750,20,20);
	a=EASY;
	vector<DPipe> A(33);
	vector<DoublePipe> B(26);
	vector<CrossPipe> C(6);
	DPIPES=A;
	DOUBPIPES=B;
	CROSSPIPES=C;

	DPipe AA0(20,750,50,20);
	DPipe AA1(70,700,50,20);
	DPipe AA2(120,600,50,20);
	DPipe AA3(20,450,50,20);
	DPipe AA4(120,500,50,20);
	DPipe AA5(120,450,50,20);
	DPipe AA6(220,500,50,20);
	DPipe AA7(220,600,50,20);
	DPipe AA8(220,700,50,20);
	DPipe AA9(270,550,50,20);
	DPipe AA10(320,550,50,20);
	DPipe AA11(370,600,50,20);
	DPipe AA12(270,450,50,20);
	DPipe AA13(320,450,50,20);
	DPipe AA14(370,450,50,20);
	DPipe AA15(320,750,50,20);
	DPipe AA16(370,750,50,20);
	DPipe AA17(420,700,50,20);
	DPipe AA18(420,650,50,20);
	DPipe AA19(420,600,50,20);
	DPipe AA20(420,550,50,20);
	DPipe AA21(320,600,50,20);
	DPipe AA22(470,500,50,20);
	DPipe AA23(470,450,50,20);
	DPipe AA24(570,500,50,20);
	DPipe AA25(570,550,50,20);
	DPipe AA26(570,600,50,20);
	DPipe AA27(470,650,50,20);
	DPipe AA28(520,700,50,20);
	DPipe AA29(520,650,50,20);
	DPipe AA30(520,600,50,20);
	DPipe AA31(520,550,50,20);
	DPipe AA32(520,450,50,20);

	DoublePipe BB0(70,750,35,20);
	DoublePipe BB1(70,650,35,20);
	DoublePipe BB2(120,650,35,20);
	DoublePipe BB3(120,550,35,20);
	DoublePipe BB4(70,500,35,20);
	DoublePipe BB5(170,500,35,20);
	DoublePipe BB6(170,550,35,20);
	DoublePipe BB7(370,550,35,20);
	DoublePipe BB8(370,650,35,20);
	DoublePipe BB9(270,650,35,20);
	DoublePipe BB10(170,700,35,20);
	DoublePipe BB11(170,750,35,20);
	DoublePipe BB12(120,750,35,20);
	DoublePipe BB13(270,700,35,20);
	DoublePipe BB14(220,650,35,20);
	DoublePipe BB15(270,750,35,20);
	DoublePipe BB16(420,750,35,20);
	DoublePipe BB17(370,700,35,20);
	DoublePipe BB18(320,700,35,20);
	DoublePipe BB19(420,500,35,20);
	DoublePipe BB20(520,500,35,20);
	DoublePipe BB21(520,750,35,20);
	DoublePipe BB22(570,450,35,20);
	DoublePipe BB23(220,450,35,20);
	DoublePipe BB24(70,550,35,20);
	DoublePipe BB25(570,650,35,20);

	CrossPipe CC0(120,700,50,20);
	CrossPipe CC1(20,500,50,20);
	CrossPipe CC2(220,550,50,20);
	CrossPipe CC3(320,650,50,20);
	CrossPipe CC4(470,750,50,20);
	CrossPipe CC5(420,450,50,20);
	
	DPIPES[0]=AA0;
	DPIPES[1]=AA1;
	DPIPES[2]=AA2;
	DPIPES[3]=AA3;
	DPIPES[4]=AA4;
	DPIPES[5]=AA5;
	DPIPES[6]=AA6;
	DPIPES[7]=AA7;
	DPIPES[8]=AA8;
	DPIPES[9]=AA9;
	DPIPES[10]=AA10;
	DPIPES[11]=AA11;
	DPIPES[12]=AA12;
	DPIPES[13]=AA13;
	DPIPES[14]=AA14;
	DPIPES[15]=AA15;
	DPIPES[16]=AA16;
	DPIPES[17]=AA17;
	DPIPES[18]=AA18;
	DPIPES[19]=AA19;
	DPIPES[20]=AA20;
	DPIPES[21]=AA21;
	DPIPES[22]=AA22;
	DPIPES[23]=AA23;
	DPIPES[24]=AA24;
	DPIPES[25]=AA25;
	DPIPES[26]=AA26;
	DPIPES[27]=AA27;
	DPIPES[28]=AA28;
	DPIPES[29]=AA29;
	DPIPES[30]=AA30;
	DPIPES[31]=AA31;
	DPIPES[32]=AA32;

	
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
	DOUBPIPES[13]=BB13;
	DOUBPIPES[14]=BB14;
	DOUBPIPES[15]=BB15;
	DOUBPIPES[16]=BB16;
	DOUBPIPES[17]=BB17;
	DOUBPIPES[18]=BB18;
	DOUBPIPES[19]=BB19;
	DOUBPIPES[20]=BB20;
	DOUBPIPES[21]=BB21;
	DOUBPIPES[22]=BB22;
	DOUBPIPES[23]=BB23;
	DOUBPIPES[24]=BB24;
	DOUBPIPES[25]=BB25;

	CROSSPIPES[0]=CC0;
	CROSSPIPES[1]=CC1;
	CROSSPIPES[2]=CC2;
	CROSSPIPES[3]=CC3;
	CROSSPIPES[4]=CC4;
	CROSSPIPES[5]=CC5;

	
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

void go_level_five(SDL_Renderer* game_renderer,vector<DPipe> &DPIPES, vector<DoublePipe>& DOUBPIPES,vector<CrossPipe>& CROSSPIPES,Water& a,DPipe back,int &choose,int &level)
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
				if (a.Woda().x==210 && a.Woda().y==425)
				{
					choose += 1;
				}
				else if (a.Woda().x==510 && a.Woda().y==425)
				{
					choose += 1;
				}
 			}
			else if(a.isDoubpipe(DOUBPIPES))
			{
				a.Doubpipebehavior(game_renderer,DOUBPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==210 && a.Woda().y==425)
				{
					choose += 1;
				}
				else if (a.Woda().x==510 && a.Woda().y==425)
				{
					choose += 1;
				}
			}
			else if(a.isCrosspipe(CROSSPIPES))
			{
				a.Crosspipebehaviour(game_renderer,CROSSPIPES);
				SDL_RenderPresent(game_renderer);
				if (a.Woda().x==210 && a.Woda().y==425)
				{
					choose += 1;
				}
				else if (a.Woda().x==510 && a.Woda().y==425)
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