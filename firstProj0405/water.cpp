/*	~~
	Class Water
		~~
*/
#include "water.h"

Water::Water(int xcent,int ycent,int wid,int heig)
{
	right=true;
	left=false;
	up=false;
	down=false;

	Hor1.x=xcent+heig/2-wid;
	Hor1.y=ycent-heig/2;
	Hor1.w=wid;
	Hor1.h=heig;

	Vert1.x=xcent-heig/2;
	Vert1.y=ycent-heig/2;
	Vert1.w=heig;
	Vert1.h=wid;

	Hor2.x=xcent-heig/2;
	Hor2.y=ycent-heig/2;
	Hor2.w=wid;
	Hor2.h=heig;
	
	Vert2.x=xcent-heig/2;
	Vert2.y=ycent+heig/2-wid;
	Vert2.w=heig;
	Vert2.h=wid;
}

void Water::moveright()
{
	right=true; left=false; up=false; down=false;
	Hor1.x+=1;
	Vert1.x+=1;
	Hor2.x+=1;
	Vert2.x+=1;
}

void Water::moveleft()
{
	right=false; left=true; up=false; down=false;
	Hor1.x-=1;
	Vert1.x-=1;
	Hor2.x-=1;
	Vert2.x-=1;
}

void Water::moveup()
{
	right=false; left=false; up=true; down=false;
	Hor1.y+=1;
	Vert1.y+=1;
	Hor2.y+=1;
	Vert2.y+=1;
}

void Water::movedown()
{
	right=false; left=false; up=false; down=true;
	Hor1.y-=1;
	Vert1.y-=1;
	Hor2.y-=1;
	Vert2.y-=1;
}


bool Water::isDpipe(vector<DPipe> a)
{
	vector<SDL_Point> A;
	
	for(int i=0;i<a.size();++i)
	{
		A=a[i].vision();
		if(right==true && (Hor1.x+Hor1.w>=A[0].x && Hor1.x+Hor1.w<A[1].x) && (Hor1.y>A[0].y && Hor1.y<A[3].y))
			return true;

		else if(left==true && (Hor2.x<=A[1].x && Hor2.x>A[0].x) && (Hor2.y>A[1].y && Hor2.y<A[2].y))
			return true;

		else if(up==true && (Vert2.y+Vert2.h>=A[0].y && Vert2.y+Vert2.h <A[3].y) && (Vert2.x>A[0].x && Vert2.x<A[1].x))
			return true;
		
		else if(down==true && (Vert1.y<=A[3].y && Vert1.y>A[0].y) && (Vert1.x>A[3].x && Vert1.x<A[2].x))
			return true;

		else
			A.clear();
	}
	return false;
}

bool Water::isDoubpipe(vector<DoublePipe> a)
{
	vector<SDL_Point> A;
	for(int i=0;i<a.size();++i)
	{
		A=a[i].vision();
		if(right==true && (Hor1.x+Hor1.w>=A[0].x && Hor1.x+Hor1.w<A[1].x) && (Hor1.y>A[0].y && Hor1.y<A[3].y))
			return true;

		else if(left==true && (Hor2.x<=A[1].x && Hor2.x>A[0].x) && (Hor2.y>A[1].y && Hor2.y<A[2].y))
			return true;
		
		else if(up==true && (Vert2.y+Vert1.h>=A[0].y && Vert2.y+Vert1.h <A[3].y) && (Vert2.x>A[0].x && Vert2.x<A[1].x))
			return true;
		
		else if(down==true && (Vert1.y<=A[3].y && Vert1.y>A[0].y) && (Vert1.x>A[3].x && Vert1.x<A[2].x))
			return true;

		else
			A.clear();

	}
	return false;
}

void Water::default_create1(SDL_Renderer *ren,string a)
{
	SDL_Surface *BMP_Voda=SDL_LoadBMP(a.c_str());
	if (BMP_Voda == nullptr)
	{
	    cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
	}
	SDL_Texture *Voda = SDL_CreateTextureFromSurface(ren, BMP_Voda);

	SDL_RenderCopy(ren, Voda, NULL, &Hor1);
}

void Water::default_create2(SDL_Renderer *ren,string a)
{
	SDL_Surface *BMP_Voda=SDL_LoadBMP(a.c_str());
	if (BMP_Voda == nullptr)
	{
	    cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
	}
	SDL_Texture *Voda = SDL_CreateTextureFromSurface(ren,BMP_Voda);

	SDL_RenderCopy(ren, Voda, NULL, &Vert1);
}

void Water::default_create3(SDL_Renderer *ren,string a)
{
	SDL_Surface *BMP_Voda=SDL_LoadBMP(a.c_str());
	if (BMP_Voda == nullptr)
	{
	    cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
	}
	SDL_Texture *Voda = SDL_CreateTextureFromSurface(ren,BMP_Voda);

	SDL_RenderCopy(ren, Voda, NULL, &Hor2);
}

void Water::default_create4(SDL_Renderer *ren,string a)
{
	SDL_Surface *BMP_Voda=SDL_LoadBMP(a.c_str());
	if (BMP_Voda == nullptr)
	{
	    cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
	}
	SDL_Texture *Voda = SDL_CreateTextureFromSurface(ren,BMP_Voda);

	SDL_RenderCopy(ren, Voda, NULL, &Vert2);
}

bool Water::isrange()
{
	if(Hor1.x>=10 && Hor1.x<=720 && Hor1.y>=50 && Hor1.y<=750)
		return true;
	else
		return false;
}

int Water::whereiamDpipe(vector<DPipe> a)
{
	vector<SDL_Point> A;
	int num;
	for(int i=0;i<a.size();++i)
	{
		A=a[i].vision();
		if(right==true && (Hor1.x+Hor1.w>=A[0].x && Hor1.x+Hor1.w<A[1].x) && (Hor1.y>A[0].y && Hor1.y<A[3].y))
		{
			num=i;
			return num;
		}

		else if(left==true && (Hor2.x<=A[1].x && Hor2.x>A[0].x) && (Hor2.y>A[1].y && Hor2.y<A[2].y))
		{
			num=i;
			return num;
		}

		else if(up==true && (Vert2.y+Vert2.h>=A[0].y && Vert2.y+Vert2.h <A[3].y) && (Vert2.x>A[0].x && Vert2.x<A[1].x))
		{
			num=i;
			return num;
		}
		
		else if(down==true && (Vert1.y<=A[3].y && Vert1.y>=A[0].y) && (Vert1.x>A[3].x && Vert1.x<A[2].x))
		{
			num=i;
			return num;
		}

		else
			A.clear();
	}
	return -1;
}

int Water::whereiamDoubpipe(vector<DoublePipe> a)
{
	vector<SDL_Point> A;
	int num;
	for(int i=0;i<a.size();++i)
	{
		A=a[i].vision();
		if(right==true && (Hor1.x+Hor1.w>=A[0].x && Hor1.x+Hor1.w<A[1].x) && (Hor1.y>A[0].y && Hor1.y<A[3].y))
		{
			num=i;
			return num;
		}

		else if(left==true && (Hor2.x<=A[1].x && Hor2.x>A[0].x) && (Hor2.y>A[1].y && Hor2.y<A[2].y))
		{
			num=i;
			return num;
		}

		else if(up==true && (Vert2.y+Vert2.h>=A[0].y && Vert2.y+Vert2.h <A[3].y) && (Vert2.x>A[0].x && Vert2.x<A[1].x))
		{
			num=i;
			return num;
		}
		
		else if(down==true && (Vert1.y<=A[3].y && Vert1.y>=A[0].y) && (Vert1.x>A[3].x && Vert1.x<A[2].x))
		{
			num=i;
			return num;
		}

		else
			A.clear();
	}
	return -1;
}

void Water::Dpipebehaviour(SDL_Renderer* ren,vector<DPipe> a)
{
	int num=whereiamDpipe(a);
	if(right==true && (a[num].getuse()==1 || a[num].getuse()==3) && num!=-1)
	{
		moveright();
		default_create1(ren,"start.bmp");
		
	}
	else if(left==true && (a[num].getuse()==1 || a[num].getuse()==3) && num!=-1)
	{
		moveleft();
		default_create1(ren,"start.bmp");
	}
	else if(up==true  && (a[num].getuse()==2 || a[num].getuse()==4) && num!=-1)
	{
		moveup();
		default_create2(ren,"start.bmp");
	}
	else if(down==true && (a[num].getuse()==2 || a[num].getuse()==4) && num!=-1)
	{
		movedown();
		default_create2(ren,"start.bmp");
	}
}

void Water::Doubpipebehavior(SDL_Renderer* ren,vector<DoublePipe> a)
{
	int num=whereiamDoubpipe(a);

	if(right==true && a[num].getuse()==2)
	{
		if((Hor1.x+Hor1.w<a[num].HorPart2().x+a[num].HorPart2().w) &&(Vert1.y+Vert1.h!=a[num].VertPart1().y+a[num].VertPart1().h) )
		{
			moveright();
			default_create1(ren,"start.bmp");
		}
		else if((Hor1.x+Hor1.w==a[num].HorPart2().x+a[num].HorPart2().w)  &&(Vert1.y+Vert1.h!=a[num].VertPart1().y+a[num].VertPart1().h))
		{
			Hor1.y+=1;
			Hor2.y+=1;
			Vert1.y+=1;
			Vert2.y+=1;
			default_create2(ren,"start.bmp");
		}

		if(Vert1.y+Vert1.h==a[num].VertPart1().y+a[num].VertPart1().h)
		{
			up=true; down=false; right=false; left=false;
		}
	}
	/* ================================================== */

	else if(right==true && a[num].getuse()==3)
	{
		if((Hor1.x+Hor1.w<a[num].HorPart2().x+a[num].HorPart2().w) &&(Vert1.y!=a[num].VertPart2().y))
		{
			moveright();
			default_create1(ren,"start.bmp");
		}
		else if((Hor1.x+Hor1.w==a[num].HorPart2().x+a[num].HorPart2().w)  &&(Vert1.y!=a[num].VertPart2().y))
		{
			Hor1.y-=1;
			Hor2.y-=1;
			Vert1.y-=1;
			Vert2.y-=1;
			default_create2(ren,"start.bmp");
		}

		if(Vert1.y==a[num].VertPart2().y)
		{
			up=false; down=true; right=false; left=false;
		}
	}
	
	/* ================================================== */
	else if(left==true && a[num].getuse()==1)
	{
		if(Hor2.x>a[num].HorPart1().x)
		{
			moveleft();
			default_create1(ren,"start.bmp");
		}
		else if(Hor2.x==a[num].HorPart1().x)
		{
			default_create2(ren,"start.bmp");
			Hor1.y+=1;
			Hor2.y+=1;
			Vert1.y+=1;
			Vert2.y+=1;
		}
		if(Vert1.y==a[num].VertPart2().y)
		{
			up=true; down=false; right=false; left=false;
		}
	}

	/* ================================================== */
	else if(left==true && a[num].getuse()==4)
	{
		if(Hor2.x>a[num].HorPart1().x)
		{
			moveleft();
			default_create1(ren,"start.bmp");
		}
		else if(Hor2.x==a[num].HorPart1().x)
		{
			default_create4(ren,"start.bmp");
			default_create2(ren,"start.bmp");
			Hor1.y-=1;
			Hor2.y-=1;
			Vert1.y-=1;
			Vert2.y-=1;
		}
		if(Vert1.y==a[num].VertPart2().y)
		{
			up=false; down=true; right=false; left=false;
		}
	}

	/* ================================================== */
	else if(up==true && a[num].getuse()==3)
	{
		if((Vert2.y+Vert2.h<a[num].VertPart2().y+a[num].VertPart2().h) && (Hor2.x!=a[num].HorPart2().x) )
		{
			moveup();
			default_create2(ren,"start.bmp");
		}
		else if((Vert2.y+Vert2.h==a[num].VertPart2().y+a[num].VertPart2().h) && (Hor2.x!=a[num].HorPart2().x))
		{
			default_create1(ren,"start.bmp");
			Hor1.x-=1;
			Hor2.x-=1;
			Vert1.x-=1;
			Vert2.x-=1;
		}
		if(Hor2.x==a[num].HorPart2().x)
		{
			
			right=false; left=true; down=false; up=false;
		}
	}
	
	/* ================================================== */
	else if(up==true && a[num].getuse()==4)
	{
		if((Vert2.y+Vert2.h<a[num].VertPart2().y+a[num].VertPart2().h) )
		{
			moveup();
			default_create2(ren,"start.bmp");
		}
		else if((Vert2.y+Vert2.h==a[num].VertPart2().y+a[num].VertPart2().h) )
		{
			default_create3(ren,"start.bmp");
			default_create1(ren,"start.bmp");
			Hor1.x+=1;
			Hor2.x+=1;
			Vert1.x+=1;
			Vert2.x+=1;
		}
		if(Hor2.x+Hor2.w==a[num].HorPart1().x+a[num].HorPart1().w)
		{
			right=true; left=false; down=false; up=false;
		}
	}

	/* ================================================== */
	else if(down==true && a[num].getuse()==2)
	{
		if(Vert1.y>a[num].VertPart1().y)
		{
			movedown();
			default_create2(ren,"start.bmp");
		}
		else if(Vert1.y==a[num].VertPart1().y)
		{
			Hor1.x-=1;
			Hor2.x-=1;
			Vert1.x-=1;
			Vert2.x-=1;
			default_create3(ren,"start.bmp");
			default_create1(ren,"start.bmp");
		}
		if(Hor2.x==a[num].HorPart2().x)
		{
			right=false; left=true; up=false; down=false;
		}
	
	}

	/* ================================================== */
	else if(down==true && a[num].getuse()==1)
	{
		if(Vert1.y>a[num].VertPart1().y)
		{
			movedown();
			default_create2(ren,"start.bmp");
		}
		else if(Vert1.y==a[num].VertPart1().y)
		{
			Hor1.x+=1;
			Hor2.x+=1;
			Vert1.x+=1;
			Vert2.x+=1;
			default_create1(ren,"start.bmp");
		}
		if(Hor1.x+Hor1.w==a[num].HorPart1().x+a[num].HorPart1().w)
		{
			right=true; left=false; up=false; down=false;
		}
	}
}