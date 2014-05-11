
void background()
{
	extern DPipe background(400,400,800,800);
}

void level_one()
{
	vector<DPipe> DPIPES(5);
	vector<DoublePipe> DOUBPIPES(8);
	vector<CrossPipe> CROSSPIPES(1);

	DPipe a0(70,600,100,40);
	DPipe a1(170,600,100,40);
	DoublePipe b0(270,600,70,40);
	DoublePipe b1(270,500,70,40);
	DoublePipe b2(170,500,70,40);
	DoublePipe b3(170,400,70,40);
	DPipe a2(270,400,100,40);
	CrossPipe c0(370,400,100,40);
	DoublePipe b4(470,400,70,40);
	DoublePipe b5(470,300,70,40);
	DoublePipe b6(370,300,70,40);
	DoublePipe b7(370,500,70,40);
	DPipe a3(470,500,100,40);
	DPipe a4(570,500,100,40);

	DPIPES[0]=a0;
	DPIPES[1]=a1;
	DPIPES[2]=a2;
	DPIPES[3]=a3;
	DPIPES[4]=a4;

	DOUBPIPES[0]=b0;
	DOUBPIPES[1]=b1;
	DOUBPIPES[2]=b2;
	DOUBPIPES[3]=b3;
	DOUBPIPES[4]=b4;
	DOUBPIPES[5]=b5;
	DOUBPIPES[6]=b6;
	DOUBPIPES[7]=b7;

	CROSSPIPES[0]=c0;
}

void level_two()
{
		vector<DPipe> DPIPES(44);
	vector<DoublePipe> DOUBPIPES(18);
	vector<CrossPipe> CROSSPIPES(3);

	DPipe background(600,400,1200,800);

	DPipe a0(50,750,100,40);
	DPipe a1(150,650,100,40);
	DPipe a2(150,550,100,40);
	DPipe a3(650,450,100,40);
	DPipe a4(550,550,100,40);
	DPipe a5(450,350,100,40);
	DPipe a6(550,250,100,40);
	DPipe a7(650,250,100,40);
	DPipe a8(750,350,100,40);
	DPipe a9(750,450,100,40);
	DPipe a10(750,550,100,40);
	DPipe a11(650,650,100,40);
	DPipe a12(550,650,100,40);
	DPipe a13(450,650,100,40);
	DPipe a14(350,550,100,40);
	DPipe a15(350,350,100,40);
	DPipe a16(350,250,100,40);
	DPipe a17(450,150,100,40);
	DPipe a18(550,150,100,40);
	DPipe a19(650,150,100,40);
	DPipe a20(750,150,100,40);
	DPipe a21(850,250,100,40);
	DPipe a22(850,350,100,40);
	DPipe a23(850,450,100,40);
	DPipe a24(850,550,100,40);
	DPipe a25(850,650,100,40);
	DPipe a26(750,750,100,40);
	DPipe a27(650,750,100,40);
	DPipe a28(550,750,100,40);
	DPipe a29(450,750,100,40);
	DPipe a30(350,750,100,40);
	DPipe a31(250,650,100,40);
	DPipe a32(250,550,100,40);
	DPipe a33(250,350,100,40);
	DPipe a34(250,250,100,40);
	DPipe a35(250,150,100,40);
	DPipe a36(350,50,100,40);
	DPipe a37(450,50,100,40);
	DPipe a38(550,50,100,40);
	DPipe a39(650,50,100,40);
	DPipe a40(750,50,100,40);
	DPipe a41(850,50,100,40);
	DPipe a42(950,150,100,40);
	DPipe a43(950,250,100,40);

	DoublePipe b0(150,750,70,40);
	DoublePipe b1(150,450,70,40);
	DoublePipe b2(550,450,70,40);
	DoublePipe b3(550,350,70,40);
	DoublePipe b4(650,350,70,40);
	DoublePipe b5(650,550,70,40);
	DoublePipe b6(450,550,70,40);
	DoublePipe b7(450,250,70,40);
	DoublePipe b8(750,250,70,40);
	DoublePipe b9(750,650,70,40);
	DoublePipe b10(350,650,70,40);
	DoublePipe b11(350,150,70,40);
	DoublePipe b12(850,150,70,40);
	DoublePipe b13(850,750,70,40);
	DoublePipe b14(250,750,70,40);
	DoublePipe b15(250,50,70,40);
	DoublePipe b16(950,50,70,40);
	DoublePipe b17(950,350,70,40);

	CrossPipe c0(250,450,100,40);
	CrossPipe c1(350,450,100,40);
	CrossPipe c2(450,450,100,40);

	DPIPES[0]=a0;
	DPIPES[1]=a1;
	DPIPES[2]=a2;
	DPIPES[3]=a3;
	DPIPES[4]=a4;
	DPIPES[5]=a5;
	DPIPES[6]=a6;
	DPIPES[7]=a7;
	DPIPES[8]=a8;
	DPIPES[9]=a9;
	DPIPES[10]=a10;
	DPIPES[11]=a11;
	DPIPES[12]=a12;
	DPIPES[13]=a13;
	DPIPES[14]=a14;
	DPIPES[15]=a15;
	DPIPES[16]=a16;
	DPIPES[17]=a17;
	DPIPES[18]=a18;
	DPIPES[19]=a19;
	DPIPES[20]=a20;
	DPIPES[21]=a21;
	DPIPES[22]=a22;
	DPIPES[23]=a23;
	DPIPES[24]=a24;
	DPIPES[25]=a25;
	DPIPES[26]=a26;
	DPIPES[27]=a27;
	DPIPES[28]=a28;
	DPIPES[29]=a29;
	DPIPES[30]=a30;
	DPIPES[31]=a31;
	DPIPES[32]=a32;
	DPIPES[33]=a33;
	DPIPES[34]=a34;
	DPIPES[35]=a35;
	DPIPES[36]=a36;
	DPIPES[37]=a37;
	DPIPES[38]=a38;
	DPIPES[39]=a39;
	DPIPES[40]=a40;
	DPIPES[41]=a41;
	DPIPES[42]=a42;
	DPIPES[43]=a43;

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
	DOUBPIPES[11]=b11;
	DOUBPIPES[12]=b12;
	DOUBPIPES[13]=b13;
	DOUBPIPES[14]=b14;
	DOUBPIPES[15]=b15;
	DOUBPIPES[16]=b16;
	DOUBPIPES[17]=b17;

	CROSSPIPES[0]=c0;
	CROSSPIPES[1]=c1;
	CROSSPIPES[2]=c2;
}

void level_three()
{
	vector<DPipe> DirectPipes(13);
		vector<DoublePipe> DoublePipes(13);
		vector<CrossPipe> CrossPipes(2);
				DPipe a0(50,SCREEN_HEIGHT-50,100,40);
				DoublePipe b0(150,SCREEN_HEIGHT-50,70,40);
				DPipe a1(150,SCREEN_HEIGHT-150,100,40);
				DoublePipe b1(150,SCREEN_HEIGHT-250,70,40);
				DPipe a2(250,SCREEN_HEIGHT-350,100,40);
				DoublePipe b2(350,SCREEN_HEIGHT-250,70,40);
				DPipe a3(350,SCREEN_HEIGHT-350,100,40);
				DPipe a4(350,SCREEN_HEIGHT-150,100,40);
				DoublePipe b3(250,SCREEN_HEIGHT-450,70,40);
				DoublePipe b4(350,SCREEN_HEIGHT-450,70,40);
				CrossPipe c0(250,SCREEN_HEIGHT-250,100,40);
				DPipe a5(550,SCREEN_HEIGHT-50,100,40);
				DoublePipe b5(250,SCREEN_HEIGHT-150,70,40);
				DoublePipe b6(450,SCREEN_HEIGHT-50,70,40);
				DoublePipe b7(650,SCREEN_HEIGHT-150,70,40);
				DPipe a6(550,SCREEN_HEIGHT-50,100,40);
				DPipe a7(550,SCREEN_HEIGHT-150,100,40);
				DoublePipe b8(750,SCREEN_HEIGHT-50,70,40);
				DPipe a8(550,SCREEN_HEIGHT-250,100,40);
				DoublePipe b9(750,SCREEN_HEIGHT-350,70,40);
				CrossPipe c1(450,SCREEN_HEIGHT-150,100,40);
				DoublePipe b10(350,SCREEN_HEIGHT-450,70,40);
				DPipe a9(750,SCREEN_HEIGHT-150,100,40);
				DPipe a10(750,SCREEN_HEIGHT-250,100,40);
				DoublePipe b11(450,SCREEN_HEIGHT-250,70,40);
				DoublePipe b12(650,SCREEN_HEIGHT-250,70,40);
				DPipe a11(650,SCREEN_HEIGHT-50,100,40);
				DPipe a12(850,SCREEN_HEIGHT-350,100,40);

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
				DirectPipes[11] = a11; DoublePipes[11] = b11;
				DirectPipes[12] = a12; DoublePipes[12] = b12;
				CrossPipes[0] = c0; CrossPipes[1] = c1;
				Water a(20,SCREEN_HEIGHT-50,40,40);
}