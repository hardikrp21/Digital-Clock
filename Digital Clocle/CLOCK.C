//DIGITAL CLOCK

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

void main()
{
   int gd=DETECT,gm;
   struct time tt;
   char hour[5],min[5],sec[5];

   clrscr();

   initgraph(&gd,&gm,"c:\\tc\\bgi");

   while(1)
   {
      if(kbhit())
	break;

      gettime(&tt);

      itoa(tt.ti_hour,hour,10);
      itoa(tt.ti_min,min,10);
      itoa(tt.ti_sec,sec,10);

      settextstyle(GOTHIC_FONT,HORIZ_DIR,10);
      setcolor(3);
      outtextxy(50,150,hour);

      setcolor(15);
      outtextxy(210,135,":");

      setcolor(5);
      outtextxy(240,150,min);

      setcolor(15);
      outtextxy(400,135,":");

      setcolor(9);
      outtextxy(430,150,sec);

      sleep(1);
      cleardevice();
   }
   getch();
   closegraph();
}




