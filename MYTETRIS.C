#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
int a[9],n=0,o,i;
char q;

void frame()
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,CYAN);


	settextstyle(7,0,6);
	outtextxy(140,3," TETTRIS ");
	setcolor(WHITE);
	settextstyle(1,0,1);
	outtextxy(400,315,"Use Arrow Keys To Move");
	outtextxy(400,250,"Press enter to start!");
	bar(100,100,125,450);
	bar(125,425,325,450);
	bar(325,100,350,450);
}
int compare (int a,int b,int c,int d)
{
	int e;
	e=(a>b?(a>c?a:c):(b>c?b:c));
	return (e>d?e:d);
}

void main()
{
	int a[9];
	int gd=DETECT,gm,j,x,y=0;
	char c,score[10];
	int p=0,t;
	int r,spd=0,scr=0;
	initgraph(&gd,&gm,"C:\TC\BGI");
	srand(time(NULL));

	for(i=0;i<9;i++)
		a[i]=0;

	settextstyle(4,0,7);
	setcolor(BLUE);

	outtextxy(100,200,"Welcome!");
	settextstyle(5,0,4);
	setcolor(WHITE);
	outtextxy(200,300,"Press Enter to continue:");
	if(getch())
		cleardevice();

	setcolor(CYAN);
	settextstyle(6,0,4);
	outtextxy(100,200,"Select your level:");
	outtextxy(100,250,"1.Beginner\n2.Intermediate\n3.Expert");
	c=getch();
	if(c=='1')spd=300;
	if(c=='2')spd=200;
	if(c=='3')spd=100;
	if(spd)
		cleardevice();
	frame();

	while(p<16)
	{
	r=rand()%4+1;
	switch(r)
	{
		case 1: //long horiz


		for(i=0,o=0;i<300,i!=300-(20*compare(a[n],a[n+1],a[n+2],a[n+3]));i+=20)
		{

			 if(kbhit())
		{
			q=getch();
			if(q==77)
			{
				if(n==5)
					goto label1;
				else
				{
					o+=20;
					n+=1;
				}
			 }
			else if(q==75&&n!=0)
			{
				o-=20;
				n-=1;
			}
			else if(q==27)
			{
				cleardevice();
				goto labele;
			}
			flushall();
			}
			label1:{	setcolor(WHITE);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(150+o,100+i,170+o,120+i);
			rectangle(170+o,100+i,190+o,120+i);
			rectangle(190+o,100+i,210+o,120+i);

			delay(spd);
			setcolor(BLACK);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(150+o,100+i,170+o,120+i);
			rectangle(170+o,100+i,190+o,120+i);
			rectangle(190+o,100+i,210+o,120+i);

			delay(spd);}
		}

		if(p==0&&a[n]==a[n+1]==a[n+2]==a[n+3])
			y=0;
		else if(a[n]==a[n+1]==a[n+2]==a[n+3]&&n<6)
			y=a[n];
		else
		{
			for(i=n,y=a[n];i<n+4;i++)
			{
				if(y<a[i])
					y=a[i];
			}
		}
		 setcolor(LIGHTBLUE);
		 rectangle(130+o,(400-(20*y)),150+o,(420-(20*y)));
		 rectangle(150+o,(400-(20*y)),170+o,(420-(20*y)));
		 rectangle(170+o,(400-(20*y)),190+o,(420-(20*y)));
		 rectangle(190+o,(400-(20*y)),210+o,(420-(20*y)));
		 a[n]=y+1;
		 a[n+1]=a[n];
		 a[n+2]=a[n];
		 a[n+3]=a[n];
		 scr+=4;
		 n=0;


		for(i=0,x=a[0];i<9;i++)
	{
		if(x<a[i])
		x=a[i];
	}
		p=x;
			break;


	case 2: //square


		for(i=0,o=0;i<300,i!=300-(20*compare(a[n],a[n+1],0,0));i+=20)
		{
			if(kbhit())
	{
		q=getch();
		if(q==77)
		{
			if(n==7)
				goto label1;
			else{
				o+=20;
				n+=1;}
			 }

			else if(q==75&&n!=0)
			{
				o-=20;
				n-=1;
			}
			else if(q==27)
			{
				cleardevice();
				goto labele;
			}
			flushall();
}
			label2:{	setcolor(WHITE);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(130+o,80+i,150+o,100+i);
			rectangle(150+o,80+i,170+o,100+i);
			rectangle(150+o,100+i,170+o,120+i);
			delay(spd);
			setcolor(BLACK);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(130+o,80+i,150+o,100+i);
			rectangle(150+o,80+i,170+o,100+i);
			rectangle(150+o,100+i,170+o,120+i);
			delay(spd);}
		}

		if(p==0&&a[n]==a[n+1])
			y=0;
		else if(a[n]==a[n+1]&&n<8)
			y=a[n];
		else
		{
			 for(i=n,y=a[n];i<n+2;i++)
			{
				if(y<a[i])
				y=a[i];
			}
		}
			 setcolor(LIGHTBLUE);

			 rectangle(130+o,(400-(20*y)),150+o,(420-(20*y)));
			 setfillstyle(1,3);
			 rectangle(130+o,(380-(20*y)),150+o,(400-(20*y)));
			 setfillstyle(1,3);
			 rectangle(150+o,(400-(20*y)),170+o,(420-(20*y)));
			 setfillstyle(1,3);
			 rectangle(150+o,(380-(20*y)),170+o,(400-(20*y)));
			 if(a[n]>a[n+1])
			 {	a[n]+=2;
				a[n+1]=a[n];
			 }
			 else
			 {
				a[n+1]+=2;
				a[n]=a[n+1];
			 }
			 n=0;
			 for(i=0,x=a[0];i<9;i++)
	{
		if(x<a[i])
		x=a[i];
	}
		p=x;
		scr+=4;

			break;


	case 3: //three


		for(i=0,o=0;i<300,i!=300-(20*compare(a[n],a[n+1],a[n+2],0));i+=20)
		{
			if(kbhit())
	{
		q=getch();
		if(q==77)
		{
			if(n==6)
				goto label1;
			else{
				o+=20;
				n+=1;}
			 }

			else if(q==75&&n!=0)
			{
				o-=20;
				n-=1;
			}
			else if(q==27)
			{
				cleardevice();
				goto labele;
			}
			flushall();
}
			label3:{
			setcolor(WHITE);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(150+o,100+i,170+o,120+i);
			rectangle(150+o,80+i,170+o,100+i);
			rectangle(170+o,100+i,190+o,120+i);
			delay(spd);
			setcolor(BLACK);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(150+o,100+i,170+o,120+i);
			rectangle(150+o,80+i,170+o,100+i);
			rectangle(170+o,100+i,190+o,120+i);
			delay(spd);}
		}

		if(p==0&&a[n]==a[n+1]==a[n+2])
			y=0;
		else if(a[n]==a[n+1]==a[n+2]&&n<7)
			y=a[n];
		else
		{
			 for(i=n,y=a[n];i<n+3;i++)
			{
				if(y<=a[i])
					y=a[i];
			}
		 }
		 setcolor(LIGHTCYAN);
		 rectangle(130+o,(400-(20*y)),150+o,(420-(20*y)));
		 rectangle(150+o,(400-(20*y)),170+o,(420-(20*y)));
		 rectangle(150+o,(380-(20*y)),170+o,(400-(20*y)));
		 rectangle(170+o,(400-(20*y)),190+o,(420-(20*y)));

		 a[n+1]=y+2;
		 a[n]=a[n+1]-1;
		 a[n+2]=a[n];
		 n=0;
		 scr+=4;

		 for(i=0,x=a[0];i<9;i++)
	{
		if(x<a[i])
		x=a[i];
	}
		p=x;
		break;

	case 4: //sleeping l


		for(i=0,o=0;i<300,i!=300-(20*(compare(a[n],a[n+1],a[n+2],0)));i+=20)
		{
			if(kbhit())
	{
		q=getch();
		if(q==77)
		{
			if(n==6)
				goto label1;
			else{
				o+=20;
				n+=1;}
			 }

			else if(q==75&&n!=0)
			{
				o-=20;
				n-=1;
			}
			else if(q==27)
			{
				cleardevice();
				goto labele;
			}
			flushall();
		}
			label4:{
			setcolor(WHITE);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(130+o,80+i,150+o,100+i);
			rectangle(150+o,100+i,170+o,120+i);
			rectangle(170+o,100+i,190+o,120+i);
			delay(spd);
			setcolor(BLACK);
			rectangle(130+o,100+i,150+o,120+i);
			rectangle(130+o,80+i,150+o,100+i);
			rectangle(150+o,100+i,170+o,120+i);
			rectangle(170+o,100+i,190+o,120+i);
			delay(spd);}

		}
		if(p==0&&a[n]==a[n+1]==a[n+2])
			y=0;
		else if(a[n]==a[n+1]==a[n+2]&&n<7)
			y=a[n];
		else
		{
			 for(i=n,y=a[n];i<n+3;i++)
			{
				if(y<=a[i])
					y=a[i];
			}
		 }
		 setcolor(LIGHTCYAN);

		 rectangle(130+o,(400-(20*y)),150+o,(420-(20*y)));
		 setfillstyle(1,3);
		 rectangle(130+o,(380-(20*y)),150+o,(400-(20*y)));
		 setfillstyle(1,3);
		 rectangle(150+o,(400-(20*y)),170+o,(420-(20*y)));
		 setfillstyle(1,3);
		 rectangle(170+o,(400-(20*y)),190+o,(420-(20*y)));
		 setfillstyle(1,3);

		 a[n]=y+2;
		 a[n+1]=a[n]-1;
		 a[n+2]=a[n+1];
		 scr+=4;
		 n=0;

		for(i=0,x=a[0];i<9;i++)
	{
		if(x<a[i])
		x=a[i];
	}
		p=x;
	break;
	}
	}
	delay(1500);
	cleardevice();

	labele:{
		sprintf(score,"%d",scr);
		settextstyle(0,0,3);
		setcolor(RED);
		outtextxy(100,100,"Game Over");
		settextstyle(1,0,2);
		setcolor(WHITE);
		outtextxy(150,200,"Your score is:");
		outtextxy(300,250,score);
	}
	getch();

}