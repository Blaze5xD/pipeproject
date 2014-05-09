#include "levels.h"

levels::levels(vector<DPipe> dp, vector<DoublePipe> doubp, vector<CrossPipe> cp)
{
	complete = 0;
	DirectPipes = dp;
	DoublePipes = doubp;
	CrossPipes = cp;
}
