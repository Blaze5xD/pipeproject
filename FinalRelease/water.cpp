/*	~~
	Class Water
		~~
*/
#include "water.h"
#include "SDL_image.h"


Water::Water(int xcent,int ycent,int wid,int heig)
{
	right=true;
	left=false;
	up=false;
	down=false;

	Voda.x=xcent-wid/2;
	Voda.y=ycent-wid/2;
	Voda.w=wid;
	Voda.h=wid;
}

Water::Water()
{
	right=true;
	left=false;
	up=false;
	down=false;

	Voda.x=0;
	Voda.y=0;
	Voda.w=0;
	Voda.h=0;
}

void Water::moveright()
{
	right=true; left=false; up=false; down=false;
	Voda.x+=1;
}

void Water::moveleft()
{
	right=false; left=true; up=false; down=false;
	Voda.x-=1;
}

void Water::moveup()
{
	right=false; left=false; up=true; down=false;
	Voda.y+=1;
}

void Water::movedown()
{
	right=false; left=false; up=false; down=true;
	Voda.y-=1;
}


bool Water::isDpipe(vector<DPipe> a)
{
	vector<SDL_Point> A;
	
	for(int i=0;i<a.size();++i)
	{
		A=a[i].vision();
		if(right==true && (Voda.x+Voda.w>=A[0].x && Voda.x+Voda.w<A[1].x) && (Voda.y>A[0].y && Voda.y<A[3].y))
			return true;

		else if(left==true && (Voda.x<=A[1].x && Voda.x>A[0].x) && (Voda.y>A[1].y && Voda.y<A[2].y ))
			return true;

		else if(up==true && (Voda.y+Voda.h>=A[0].y && Voda.y+Voda.h<A[3].y) && (Voda.x>A[0].x && Voda.x<A[1].x))
			return true;
		
		else if(down==true && (Voda.y<=A[3].y && Voda.y>A[0].y) && (Voda.x>A[3].x && Voda.x<A[2].x) )
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
		if(right==true && (Voda.x+Voda.w>=A[0].x && Voda.x+Voda.w<A[1].x) && (Voda.y>A[0].y && Voda.y<A[3].y))
			return true;

		else if(left==true && (Voda.x<=A[1].x && Voda.x>A[0].x) && (Voda.y>A[1].y && Voda.y<A[2].y ))
			return true;

		else if(up==true && (Voda.y+Voda.h>=A[0].y && Voda.y+Voda.h<A[3].y) && (Voda.x>A[0].x && Voda.x<A[1].x))
			return true;
		
		else if(down==true && (Voda.y<=A[3].y && Voda.y>A[0].y) && (Voda.x>A[3].x && Voda.x<A[2].x) )
			return true;

		else
			A.clear();

	}
	return false;
}

bool Water::isCrosspipe(vector<CrossPipe> a)
{
	vector<SDL_Point> A;
	for(int i=0;i<a.size();++i)
	{
		A=a[i].vision();
		if(right==true && (Voda.x+Voda.w>=A[0].x && Voda.x+Voda.w<A[1].x) && (Voda.y>A[0].y && Voda.y<A[3].y))
			return true;

		else if(left==true && (Voda.x<=A[1].x && Voda.x>A[0].x) && (Voda.y>A[1].y && Voda.y<A[2].y ))
			return true;

		else if(up==true && (Voda.y+Voda.h>=A[0].y && Voda.y+Voda.h<A[3].y) && (Voda.x>A[3].x && Voda.x<A[2].x))
			return true;
		
		else if(down==true && (Voda.y<=A[3].y && Voda.y>A[0].y) && (Voda.x>A[0].x && Voda.x<A[1].x) )
			return true;

		else
			A.clear();
	}
	return false;
} 

void Water::default_create(SDL_Renderer *ren,string a)
{
	SDL_Texture *VVoda = IMG_LoadTexture(ren, a.c_str());
	SDL_RenderCopy(ren, VVoda, NULL, &Voda);

	SDL_DestroyTexture(VVoda);
}

bool Water::isrange()
{
	if(Voda.x>=0 && Voda.x<=1000 && Voda.y>=0 && Voda.y<=800)
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
		if(right==true && (Voda.x+Voda.w>=A[0].x && Voda.x+Voda.w<A[1].x) && (Voda.y>A[0].y && Voda.y<A[3].y))
		{
			num=i;
			return num;
		}
		else if(left==true && (Voda.x<=A[1].x && Voda.x>A[0].x) && (Voda.y>A[1].y && Voda.y<A[2].y ))
		{
			num=i;
			return num;
		}

		else if(up==true && (Voda.y+Voda.h>=A[0].y && Voda.y+Voda.h<A[3].y) && (Voda.x>A[3].x && Voda.x<A[2].x))
		{
			num=i;
			return num;
		}
		
		else if(down==true && (Voda.y<=A[3].y && Voda.y>A[0].y) && (Voda.x>A[0].x && Voda.x<A[1].x) )
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
		if(right==true && (Voda.x+Voda.w>=A[0].x && Voda.x+Voda.w<A[1].x) && (Voda.y>A[0].y && Voda.y<A[3].y))
		{
			num=i;
			return num;
		}
		else if(left==true && (Voda.x<=A[1].x && Voda.x>A[0].x) && (Voda.y>A[1].y && Voda.y<A[2].y ))
		{
			num=i;
			return num;
		}

		else if(up==true && (Voda.y+Voda.h>=A[0].y && Voda.y+Voda.h<A[3].y) && (Voda.x>A[3].x && Voda.x<A[2].x))
		{
			num=i;
			return num;
		}
		
		else if(down==true && (Voda.y<=A[3].y && Voda.y>A[0].y) && (Voda.x>A[0].x && Voda.x<A[1].x) )
		{
			num=i;
			return num;
		}

		else
			A.clear();
	}
	return -1;
}

int Water::whereiamCrosspipe(vector<CrossPipe> a)
{
	vector<SDL_Point> A;
	int num;
	for(int i=0;i<a.size();++i)
	{
		A=a[i].vision();
		if(right==true && (Voda.x+Voda.w>=A[0].x && Voda.x+Voda.w<A[1].x) && (Voda.y>A[0].y && Voda.y<A[3].y))
		{
			num=i;
			return num;
		}
		else if(left==true && (Voda.x<=A[1].x && Voda.x>A[0].x) && (Voda.y>A[1].y && Voda.y<A[2].y ))
		{
			num=i;
			return num;
		}

		else if(up==true && (Voda.y+Voda.h>=A[0].y && Voda.y+Voda.h<A[3].y) && (Voda.x>A[3].x && Voda.x<A[2].x))
		{
			num=i;
			return num;
		}
		
		else if(down==true && (Voda.y<=A[3].y && Voda.y>A[0].y) && (Voda.x>A[0].x && Voda.x<A[1].x) )
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
		default_create(ren,"start.jpg");
		
	}
	else if(left==true && (a[num].getuse()==1 || a[num].getuse()==3) && num!=-1)
	{

		moveleft();
		default_create(ren,"start.jpg");
	}
	else if(up==true  && (a[num].getuse()==2 || a[num].getuse()==4) && num!=-1)
	{

		moveup();
		default_create(ren,"start.jpg");
	}
	else if(down==true && (a[num].getuse()==2 || a[num].getuse()==4) && num!=-1)
	{

		movedown();
		default_create(ren,"start.jpg");
	}
}

void Water::Doubpipebehavior(SDL_Renderer* ren,vector<DoublePipe> a)
{
	int num=whereiamDoubpipe(a);

	if(right==true && a[num].getuse()==2)
	{
		if((Voda.x+Voda.w<a[num].HorPart2().x+a[num].HorPart2().w) &&(Voda.y+Voda.h!=a[num].VertPart1().y+a[num].VertPart1().h) )
		{
	
			moveright();
			default_create(ren,"start.jpg");
		}
		else if((Voda.x+Voda.w==a[num].HorPart2().x+a[num].HorPart2().w) &&(Voda.y+Voda.h!=a[num].VertPart1().y+a[num].VertPart1().h))
		{

			Voda.y+=1;
			default_create(ren,"start.jpg");
		}

		if(Voda.y+Voda.h==a[num].VertPart1().y+a[num].VertPart1().h)
		{
			up=true; down=false; right=false; left=false;
		}

	}
	/* ================================================== */

	else if(right==true && a[num].getuse()==3)
	{
		if((Voda.x+Voda.w<a[num].HorPart2().x+a[num].HorPart2().w) &&(Voda.y!=a[num].VertPart2().y))
		{
			
			moveright();
			default_create(ren,"start.jpg");
		}
		else if((Voda.x+Voda.w==a[num].HorPart2().x+a[num].HorPart2().w) &&(Voda.y!=a[num].VertPart2().y))
		{
			;
			Voda.y-=1;
			default_create(ren,"start.jpg");
		}

		if(Voda.y==a[num].VertPart2().y)
		{
			up=false; down=true; right=false; left=false;
		}
		
	}
	
	/* ================================================== */
	else if(left==true && a[num].getuse()==1)
	{
		if(Voda.x>a[num].HorPart1().x)
		{
		
			moveleft();
			default_create(ren,"start.jpg");
		}
		else if(Voda.x==a[num].HorPart1().x)
		{

			default_create(ren,"start.jpg");
			Voda.y+=1;
		}
		if(Voda.y+Voda.h==a[num].VertPart1().y+a[num].VertPart1().h)
		{
			up=true; down=false; right=false; left=false;
		}
	
	}

	/* ================================================== */
	else if(left==true && a[num].getuse()==4)
	{
		if(Voda.x>a[num].HorPart1().x)
		{

			moveleft();
			default_create(ren,"start.jpg");
		}
		else if(Voda.x==a[num].HorPart1().x)
		{

			default_create(ren,"start.jpg");
			Voda.y-=1;
		}
		if(Voda.y==a[num].VertPart2().y)
		{
			up=false; down=true; right=false; left=false;
		}
		
	}

	/* ================================================== */
	else if(up==true && a[num].getuse()==3)
	{
		if((Voda.y+Voda.h<a[num].VertPart2().y+a[num].VertPart2().h) && (Voda.x!=a[num].HorPart2().x) )
		{
			
			moveup();
			default_create(ren,"start.jpg");
		}
		else if((Voda.y+Voda.h==a[num].VertPart2().y+a[num].VertPart2().h) && (Voda.x!=a[num].HorPart2().x))
		{
			
			default_create(ren,"start.jpg");
			Voda.x-=1;
		}
		if(Voda.x==a[num].HorPart2().x)
		{
			right=false; left=true; down=false; up=false;
		}
	
	}
	
	/* ================================================== */
	else if(up==true && a[num].getuse()==4)
	{
		if((Voda.y+Voda.h<a[num].VertPart2().y+a[num].VertPart2().h) )
		{
			
			moveup();
			default_create(ren,"start.jpg");
		}
		else if((Voda.y+Voda.h==a[num].VertPart2().y+a[num].VertPart2().h))
		{
			default_create(ren,"start.jpg");
			Voda.x+=1;
		}
		if(Voda.x+Voda.w==a[num].HorPart1().x+a[num].HorPart1().w)
		{
			right=true; left=false; down=false; up=false;
		}
		
	}
	else if(down==true && a[num].getuse()==1)
	{
		if(Voda.y>a[num].VertPart1().y)
		{
			
			movedown();
			default_create(ren,"start.jpg");
		}
		else if(Voda.y==a[num].VertPart1().y)
		{
			
			Voda.x+=1;
			default_create(ren,"start.jpg");
		}
		if(Voda.x+Voda.w==a[num].HorPart1().x+a[num].HorPart1().w)
		{
			right=true; left=false; up=false; down=false;
		}
		
	}
	/* ================================================== */
	else if(down==true && a[num].getuse()==2)
	{
		if(Voda.y>a[num].VertPart1().y)
		{
			
			movedown();
			default_create(ren,"start.jpg");
		}
		else if(Voda.y==a[num].VertPart1().y)
		{
			
			Voda.x-=1;
			default_create(ren,"start.jpg");
		}
		if(Voda.x==a[num].HorPart2().x)
		{
			right=false; left=true; up=false; down=false;
		}
		
	} 

	/* ================================================== */
}

void Water::Crosspipebehaviour(SDL_Renderer *ren, vector<CrossPipe> a)
{
	int num=whereiamCrosspipe(a);
	if(right==true && isCrosspipe(a) &&num!=-1)
	{
		
		moveright();
		default_create(ren,"start.jpg");
		
	}
	else if(left==true && isCrosspipe(a) && num!=-1)
	{
		
		moveleft();
		default_create(ren,"start.jpg");
	}
	else if(up==true  && isCrosspipe(a) && num!=-1)
	{
		
		moveup();
		default_create(ren,"start.jpg");
	}
	else if(down==true && isCrosspipe(a) &&num!=-1)
	{
		
		movedown();
		default_create(ren,"start.jpg");
	}
}
