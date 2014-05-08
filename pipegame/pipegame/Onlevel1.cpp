#include "levels.h"

void levels::Onlevel1()
{
	DPipe a0(50,SCREEN_HEIGHT-50,100,40);
	DoublePipe b0(150,SCREEN_HEIGHT-50,70,40);
	DPipe a1(250,SCREEN_HEIGHT-50,100,40);
	DoublePipe b1(350,SCREEN_HEIGHT-50,70,40);
	DPipe a2(450,SCREEN_HEIGHT-50,100,40);
	DoublePipe b2(550,SCREEN_HEIGHT-50,70,40);
	DPipe a3(50,SCREEN_HEIGHT-150,100,40);
	DPipe a4(150,SCREEN_HEIGHT-150,100,40);
	DoublePipe b3(250,SCREEN_HEIGHT-150,70,40);
	DoublePipe b4(350,SCREEN_HEIGHT-150,70,40);
	CrossPipe c0(450,SCREEN_HEIGHT-150,100,40);
	DPipe a5(550,SCREEN_HEIGHT-150,100,40);
	DoublePipe b5(50,SCREEN_HEIGHT-250,70,40);
	DoublePipe b6(150,SCREEN_HEIGHT-250,70,40);
	DoublePipe b7(250,SCREEN_HEIGHT-250,70,40);
	DPipe a6(350,SCREEN_HEIGHT-250,100,40);
	DPipe a7(450,SCREEN_HEIGHT-250,100,40);
	DoublePipe b8(550,SCREEN_HEIGHT-250,70,40);
	DPipe a8(50,SCREEN_HEIGHT-350,100,40);
	DoublePipe b9(150,SCREEN_HEIGHT-350,70,40);
	CrossPipe c1(250,SCREEN_HEIGHT-350,100,40);
	DoublePipe b10(350,SCREEN_HEIGHT-350,70,40);
	DPipe a9(450,SCREEN_HEIGHT-350,100,40);
	DPipe a10(550,SCREEN_HEIGHT-350,100,40);

	DirectPipes[0] = a0; DoublePipes[0] = b0;
	DirectPipes[1] = a1; DoublePipes[1] = b1;
	DirectPipes[2] = a2; DoublePipes[2] = b2;
	DirectPipes[3] = a3; DoublePipes[3] = b3;
	DirectPipes[4] = a4; DoublePipes[4] = b4;
	DirectPipes[5] = a5; DoublePipes[5] = b5;
	DirectPipes[6] = a6; DoublePipes[6] = b6;
	DirectPipes[7] = a7; DoublePipes[7] = b7;
	DirectPipes[8] = a8; DoublePipes[8] = b8;
	DirectPipes[9] = a9; DoublePipes[9] = b9;
	DirectPipes[10] = a10; DoublePipes[10] = b10;
	CrossPipes[0] = c0; CrossPipes[1] = c1;
	Water a(50,SCREEN_HEIGHT-50,40,10);
}