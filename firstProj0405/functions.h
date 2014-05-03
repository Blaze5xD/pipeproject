

void nochanges(SDL_Renderer* ren,vector<DPipe>& a)
{
	for(int i=0;i<a.size();++i)
	{
			a[i].upgrade(ren);
	}
} 

ostream& operator<<(ostream& os,vector<SDL_Point> a)
{
	for(int i=0;i<a.size();++i)
	{
		os<<"("<<a[i].x<<","<<a[i].y<<") \n";
	}
	return os;
}

ostream& operator<<(ostream& os,SDL_Rect a)
{
	return os<<"("<<a.x<<","<<a.y<<";"<<a.w<<","<<a.h<<"\n";
}
