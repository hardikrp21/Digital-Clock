#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
void main()
{
int gd=DETECT,gm,h1=9,m1=0,s1=1;
unsigned long i,n;
char t[1000];
char t1[1000];
char t2[1000];
float sec=-1.57,m=-1.57,h=-3.14;
initgraph(&gd,&gm,"c:\\tc\\bgi");
settextstyle(2,0,26);
/*
	for(i=1;i<=20;i++)//introduction
	{
	setcolor(i);
	outtextxy(80,80,"C L O C K");
	delay(300);
	outtextxy(180,180,"Developed by");
	outtextxy(180,240,"Dipak Patel");
	outtextxy(60,300,"princedip2978@yahoo.com");
	}
	*/
clearviewport(); //clock body creation
for(i=1;i<=10;i+=3){
setcolor(BLUE);
setlinestyle(0,0,2);
circle(320,240,190+i);
setcolor(GREEN);
circle(320,240,210+i);
}
setfillstyle(SOLID_FILL,BLACK);
	//Minuts
	setcolor(YELLOW);//initialize the sec,hr,and min hands
	setlinestyle(0,0,3);
	line(320,240,320+130*0.00079,240-130*0.99999);
	//Hours
	fillellipse(320+130*cos(-m),240-130*sin(-m),4,4);
	setcolor(MAGENTA);
	setlinestyle(0,0,3);
	//second
	line(320,240,320+100*cos(-h),240-100*sin(-h));
	fillellipse(320+100*cos(-h),240-100*sin(-h),4,4);
	setlinestyle(0,0,2);
	settextstyle(2,0,4);
	//gidit printing
	float angle=-1.571428;//printing the hours -1,2,3,...12
	for(i=1;i<=12;i++)
	{
		setcolor(i);
		angle=angle+5*0.104666;	//since 3.14/180=0.104666 = 1 degree
		sprintf(t,"%d",i);

		float x= 320+180*cos(-angle);//(-angle) so as to rotate clockwise
		sprintf(t1,"x=%f",x);

		float y= 240-180*sin(-angle);
		sprintf(t2,"y=%f",y);

		outtextxy(x,y,t);
		//print x and y
		outtextxy(x+10,y+10,t1);
		outtextxy(x+20,y+20,t2);

	}
	outtextxy(10,10,"Press any key to quit... ") ;
//start the clock
	i=0;
	do
	{
	sound(3800);//tick tick tick.......
	delay(50);
	nosound();
	setcolor(YELLOW);
	fillellipse(320,240,6,6);
	fillellipse(320,240,3,3);
	// second -1
	setcolor(BLUE);
	line(320,240,320+180*cos(-sec),240-180*sin(-sec));
	delay(800);
	//second -2
	setcolor(0);
	line(320,240,320+180*cos(-sec),240-180*sin(-sec));
	setfillstyle(SOLID_FILL,BLACK);
	bar(260,465,380,490); //for the small digital clock
		if(i%60==0)//minute hand movement
		{
		//minute  hand
		setcolor(BLACK);
		setlinestyle(0,0,3);
		m=m-.10466666;//radian to degree => 3.14/180 =0.1046666
		line(320,240,320+130*cos(-m),240-130*sin(-m));
		fillellipse(320+130*cos(-m),240-130*sin(-m),4,4);
		m=m+.10466666;

		//hour hand
		setcolor(YELLOW);
		setlinestyle(0,0,3);
		line(320,240,320+130*cos(-m),240-130*sin(-m));
		fillellipse(320+130*cos(-m),240-130*sin(-m),4,4);
		setlinestyle(0,0,2);
		m=m+.10466666;
		}
		if(i%720==0&&i!=0)//hour hand movement
		{
		setcolor(BLACK);
		setlinestyle(0,0,3);
		h=h-.10466666;
		line(320,240,320+100*cos(-h),240-100*sin(-h));
		fillellipse(320+100*cos(-h),240-100*sin(-h),4,4);
		h=h+.10466666;
		setcolor(MAGENTA);
		setlinestyle(0,0,3);
		line(320,240,320+100*cos(-h),240-100*sin(-h));
		fillellipse(320+100*cos(-h),240-100*sin(-h),4,4);
		setlinestyle(0,0,2);
		h=h+.10466666;
		}
		sec=sec+.1046666;
		i++;
		sprintf(t," %d : %d : %d",h1,m1,s1);
		setcolor(YELLOW);
		outtextxy(290,465,t);
		s1=s1+1;
		if(s1==60)
		{
			m1=m1+1;
			s1=0;
		}
		if(m1==60)
		{
			h1=h1+1;
			m1=0;
		}
		setfillstyle(11,gd+1);
		} while(!kbhit());
	outtextxy(240,280,"T I M E -- U P");
	getch();
}