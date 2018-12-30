#include<iostream.h>
#include<conio.h>
#include<dos.h>
void instructor();
void sketcher();

void main()
{clrscr();
instructor();
getch();clrscr();
sketcher();
}

void sketcher()
{int i=0, draw=0, dir='d', x=4,y=4;
 for (i=0;dir!='x';i++)
   {gotoxy(x,y);                        //Pen
    switch(draw)
    {case 1:break;
    case 2:cout<<"*";break;
    case 3:cout<<" ";break;}

    delay(10);


    if (kbhit())                        //Selector
	{dir=getch();}
    else continue;


    switch(dir)                         //Hand
      {case 'a':x--;break;
       case 'd':x++;break;
       case 'w':y--;break;
       case 's':y++;break;
       case 'q':draw=1;break;
       case 'e':draw=2;break;
       case 'r':draw=3;break;
       default:break;
      }
   /*gotoxy(x-5,y);
    cout<<" ";*/


   }
}

void instructor()
{cout<<"\n\t\t\t\t  Sketchman";
 cout<<"\n\n\t\t\t\tInstructions";
 cout<<"\n\n\n  1.To control the pen use the keys:";
 cout<<"\n\n\t  W\n\tA   D\n\t  S";
 cout<<"\n\n  2.To start Drawing Mode press:  'E'";
 cout<<"\n\n  3.To start Inkless Mode press:  'Q'";
 cout<<"\n\n  4.To start Eraser Mode press:  'R'";
 cout<<"\n\n  5.To Exit press:  'X'";
 cout<<"\n\n\n\n  Press any ky to start...";
}