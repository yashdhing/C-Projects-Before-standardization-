#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
void main()                           //Yash's upgraded version
{randomize();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"D:\\bgi");
int k=5,t=5,i=0,Ly,midx=200,score=0,midy=0,Px=15,Py=244,rad=10;
setbkcolor(2);
for( ;t>0 ;midy+=5)
{
 for(Ly=40;Ly<=220;Ly+=10)
  line(3,Ly,7,Ly);
 outtextxy(8,38,"40");
 outtextxy(8,78,"80");
 outtextxy(8,118,"120");
 outtextxy(8,158,"160");
 outtextxy(8,198,"200");
 setcolor(1);
 setfillstyle(SOLID_FILL,4);
 circle(midx,midy,rad);
 line(midx,midy+10,midx,midy+17);
 floodfill(midx,midy,1);
 setcolor(1);
 setfillstyle(1,8);
 rectangle(0,240,15,247);
 floodfill(6,246,1);
 rectangle(0,247,5,254);
 floodfill(4,248,1);
 pieslice(5,247,270,360,3);
 rectangle(550,15,630,75);
 outtextxy(565,22,"SCORE : ");
 gotoxy(74,3);
 cout<<score;
 gotoxy(72,4);
//////////////////////////////////////////////
 for(k=t;k>0;k--)
   cout<<(char)3;
 if(midy==400)
 {
  t--;
  b:
  getch();
  Px=15;
  midy=0;
  midx=200+random(400);
 }
   if(kbhit())
   {
      for(i=-1;i<2;i++)
       {
	putpixel(Px+i,Py,1);
	putpixel(Px,Py+i,1);
	putpixel(Px+i,Py+i,1);
       }

      if(Px>midx-10&&Px<midx+10&&Py>midy-10&&Py<midy+10)
      {
       for(i=5;i<=10;i++)
       {
	setcolor(i);
	setfillstyle(7+random(6),4);
	circle(midx,midy,rad+i) ;
	floodfill(midx,midy,i);
	delay(175);
	cleardevice();
       }
       delay(100);
       score+=10;
       goto b;
      }
     Px+=15;
   }
delay(100);
cleardevice();
}

closegraph();
}