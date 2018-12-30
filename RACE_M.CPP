#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>
#include<time.h>
//////////////////////////////////////////////////////////////////////////////
void start();                                  //Disclaimer
void load();                                   //Loading(Just Show Off ;-) )
void menu();                                   //The Menu Card
void instr();                                  //Instructions
void settings();
void car(int);                                 //Player's Car
void car2(int, int);                           //Traffic - The Trouble!!
long double timer();
int crash(int,int,int);                        //To Test For Crash
void boom();                                   //Fireworks
void road(int);
int  gdriver=DETECT,gmode;
int col1=RED, col2=BLUE, sec=20, speed=5;
//////////////////////////////////////////////////////////////////////////////
void main()
{clrscr();
long double t, tim=0;
int i, m, n, a, c, r, check;
		/*i=y-axis of traffic
		  m=loop for the game
		  n=side of traffic
		  a=side of player's car
		  c=number of cars passed
		  t=initial time
		  tim=time passed
		  check=test for crash(True1 or False0)*/
initgraph (&gdriver,&gmode,"D:\\bgi");
start();load();
Menu:
menu();
a=0;check=1;
randomize();
  //Main Game BK Screen
setbkcolor(0);
setcolor(WHITE);
setfillstyle(SOLID_FILL, 15);
rectangle(199,74,401,351);
floodfill(5,5,15);
  //The Game Begins
tim=0;c=0;
car(a);
delay(1500);
t=timer();
for (m=0;check && tim<sec;m++)                 //For every new car
{ n=random(50)%2;
  for (i=90;i<275 && tim<sec;i+=speed)         //For motion of current car
  { if (kbhit())
    {a=getch()%2;}
    setfillstyle(SOLID_FILL, 8);
    bar(200,75,400,350);
    car2(n,i);car(a);road(r);
    check=crash(i,a,n);
    if(!crash(i,a,n))
    break;
    tim=timer()-t;delay(20);r++;r=r%6;
  }
  setfillstyle(SOLID_FILL, BLACK);
  bar(200,75,400,350);
  car(a);c++;
}
setcolor(4);
if(check)
 {outtextxy(250,150,"Time Up!!!");delay(2000);
  }
else
 {outtextxy(250,150,"Crashed!!!");boom();
 boom();
 }
gotoxy(5,5);cout<<"Your Score:"<<c*10;
delay(1000);getch();
goto Menu;
}

//////////////////////////////////////////////////////////////////////////////

void car(int pos)
{setcolor(col1);setfillstyle(SOLID_FILL, col1);
switch(pos)
   {case 0:bar(245,275,270,325);               //Left
    setfillstyle(SOLID_FILL,0);
    bar(235,285,245,295);
    bar(270,285,280,295);
    bar(235,310,245,320);
    bar(270,310,280,320);
    break;
   case 1:                                     //Right
    bar(325,275,350,325);
    setfillstyle(SOLID_FILL,0);
    bar(315,285,325,295);
    bar(350,285,360,295);
    bar(315,310,325,320);
    bar(350,310,360,320);
    break;}
}

void car2(int pos, int y)
{setcolor(col2);
setfillstyle(SOLID_FILL,col2);
switch(pos)
   {case 0:bar(245,y,270,y+50);                //Left
    setfillstyle(SOLID_FILL,0);
    bar(235,y+10,245,y+20);
    bar(270,y+10,280,y+20);
    bar(235,y+35,245,y+45);
    bar(270,y+35,280,y+45);
   break;
   case 1:bar(325,y,350,y+50);                 //Right
    setfillstyle(SOLID_FILL,0);
    bar(315,y+10,325,y+20);
    bar(350,y+10,360,y+20);
    bar(315,y+35,325,y+45);
    bar(350,y+35,360,y+45);
   break;}
}

int crash(int y,int a,int n)
{if(y>225 && a==n)
return 0;
else
return 1;
}

void boom()
{for (int i=5;i<=25;i++)
      {
       setcolor(i);
       setfillstyle(SOLID_FILL,4);
       circle(300,265,i) ;
       floodfill(300,265,i);
       delay(30);
       cleardevice();
      }
}

long double timer()
{time_t t;
 time(&t);
 return t;
}

void road(int r)
{setfillstyle(SOLID_FILL,15);
r*=10;
bar(295,40+r,300,60+r);
bar(295,100+r,300,120+r);
bar(295,160+r,300,180+r);
bar(295,220+r,300,240+r);
bar(295,280+r,300,300+r);
bar(295,340+r,300,360+r);
}
//////////////////////////////////////////////////////////////////////////////
void start()
{
delay(1000);
setbkcolor(0);
cleardevice();
settextstyle(0,0,4);
for(int x=0;x<290;x+=2)
  {outtextxy(x,200,">>>");
  delay(1);}
setcolor(4);
  outtextxy(200,200,"Race");
for(x=getmaxx();x>200;x-=2)
  {outtextxy(x,227,"<<<");
  delay(1);}
setcolor(15);
  outtextxy(300,227,"Mania");
   {bar(400,170,425,220);
    rectangle(390,180,400,190);
    rectangle(425,180,435,190);
    rectangle(390,205,400,215);
    rectangle(425,205,435,215);
    setfillstyle(SOLID_FILL, 14);
    bar(400,170,407,175);
    bar(418,170,425,175);
    setfillstyle(SOLID_FILL, 8);
    bar(405,185,420,215);
    bar(392,220,433,225);}
getch();
cleardevice();
setcolor(2);
settextstyle(5,HORIZ_DIR,4) ;
      outtextxy(250,50,"Disclaimer");
settextstyle(0,HORIZ_DIR,1) ;
      outtextxy(90,150," This game is not yet furnished completely and may show");
      outtextxy(60,165," strange behaviour if anyone tries to test its efficiency.");
      outtextxy(90,185," I request all the users to use the game as per the");
      outtextxy(60,200," normal rules as any small mistake or attempt of immaturity");
      outtextxy(60,215," may show anomalous behaviour.");
      outtextxy(60,235," I hope you will enjoy and like the game....");
setcolor(9);
      settextstyle(1,0,4) ;
      outtextxy(200,250," Best of luck!!!");
      settextstyle(5,HORIZ_DIR,2) ;
      setcolor(14);
      outtextxy(450,300,"...Yash Dhing");
getch();
cleardevice();}

void load()
{int e;
setbkcolor(15);
setcolor(4);
settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(4, HORIZ_DIR, 4);
   outtextxy(getmaxx()/2,getmaxy()/2-25,"Loading");
delay(10);
setcolor(1);
setfillstyle(SOLID_FILL,1);
for (e=0;e<120;e++)
{  bar(20,385,20+5*e,400);
   delay(10);}
cleardevice();
  bar(20,385,20+5*e,400);
setcolor(4);
  outtextxy(getmaxx()/2,getmaxy()/2-25,"Loaded");
setcolor(1);
settextstyle(0, HORIZ_DIR, 1);
  outtextxy(375,250,"Press any key");
getch();
cleardevice();}

void menu()
{men:
cleardevice();setbkcolor(0);
int x, y, i;
char choice;
setcolor(4);
rectangle(2,2,getmaxx()-2,getmaxy()-2);
setfillstyle(SOLID_FILL,15);
bar3d(200,77,215,398,3,1);
bar3d(getmaxx()-200,77,getmaxx()-215,398,3,1);
for(i=0;i<=50;i++)
  {setfillstyle(SOLID_FILL,4);
   x=i*3;y=300-i*3;
   bar3d(x,60,getmaxx()-(300-x),75,3,1);
   bar3d(y,400,getmaxx()-(300-y),415,3,1);delay(7);
  }
setcolor(15);
settextstyle(4,0,6);
settextjustify(CENTER_TEXT, CENTER_TEXT);
   outtextxy(getmaxx()/2,100,"MENU");
delay(200);
settextjustify(LEFT_TEXT, CENTER_TEXT);
settextstyle(1,HORIZ_DIR,2);
   outtextxy(235,175,"1. New Game");delay(100);
   outtextxy(235,200,"2. Instructions");delay(100);
   outtextxy(235,225,"3. Settings");delay(100);
   outtextxy(235,250,"4. Credits");delay(300);
settextstyle(1,HORIZ_DIR,1);
   outtextxy(235,325,"Press escape to exit");
   outtextxy(307,135,"serve it hot!!");
invalid:
choice=getch();
switch(choice)
 {case 27:exit(0);break;
  case '2':instr();goto men;
  case '3':settings();goto men;
  case '4':cleardevice();outtextxy(250,250,"Area under construction!!!");getch();goto men;
  case '1':cleardevice();goto end;
  default: goto invalid;
 }
cleardevice();
end:
}
//////////////////////////////////////////////////////////////////////////////
void instr()
{cleardevice();
char choice;
settextstyle(5,HORIZ_DIR,4) ;
      outtextxy(250,50,"Instructions");
settextstyle(0,HORIZ_DIR,1) ;
      outtextxy(70,140," This game is is all about timing and controls");
      outtextxy(80,170," * To turn and accelarate car on left lane, keep pressing key'6'");
      outtextxy(80,195," * To turn and accelarate car on right lane, keep pressing key'7'");
      outtextxy(80,220," * You will have to hold the key to keep the car moving the car");
      outtextxy(80,245," * Beware of the traffic on the road.");
      outtextxy(70,275," For each car you cross, you get 10 points.");
      outtextxy(70,300," But you have only 20sec time to complete, so be fast...");
getch();}

void settings()
{cleardevice();
char choice, sel;
setcolor(4);
settextstyle(5,HORIZ_DIR,4) ;
      outtextxy(250,50,"Settings");
setcolor(2);
settextstyle(0,HORIZ_DIR,1) ;
      outtextxy(60,140," Press");
      outtextxy(90,180," 1 - To change your cars colour");
      outtextxy(90,200," 2 - To change traffics colour");
      outtextxy(90,220," 3 - To set race time");
      outtextxy(90,240," 4 - To change speed");
      outtextxy(70,260," Esc - To return to menu");
choice=getch();
switch(choice)
 {case 27:menu();break;
//Car Colour
  case '1':
  cleardevice();
  outtextxy(60,140," Please select your colour:");
  outtextxy(90,180," 1-Blue");
  outtextxy(90,200," 2-Green");
  outtextxy(90,220," 3-Red");
  outtextxy(90,240," 4-Voilet");
  outtextxy(90,260," 5-Pink");
  outtextxy(90,280," 6-White");
  sel=getch();
     switch(sel)
     {case '1':col1=BLUE;break;
     case '2':col1=GREEN;break;
     case '3':col1=RED;break;
     case '4':col1=9;break;
     case '5':col1=13;break;
     case '6':col1=WHITE;break;
     default:settings();
     }
  outtextxy(60,310,"Colour Set!");
  break;
//Traffic Colour
  case '2':
  cleardevice();
  outtextxy(60,140," Please select your colour:");
  outtextxy(90,180," 1-Blue");
  outtextxy(90,200," 2-Green");
  outtextxy(90,220," 3-Red");
  outtextxy(90,240," 4-Voilet");
  outtextxy(90,260," 5-Pink");
  outtextxy(90,280," 6-White");
  sel=getch();
     switch(sel)
     {case '1':col2=BLUE;break;
     case '2':col2=GREEN;break;
     case '3':col2=RED;break;
     case '4':col2=9;break;
     case '5':col2=13;break;
     case '6':col2=WHITE;break;
     default:settings();
     }
  outtextxy(60,310,"Colour Set!");
  break;
//Time
  case '3':
  cleardevice();
  outtextxy(60,140," Please select your time:");
  outtextxy(90,180," 1 - 10 seconds");
  outtextxy(90,200," 2 - 20 seconds");
  outtextxy(90,220," 3 - 30 seconds");
  outtextxy(90,240," 4 - 40 seconds");
  outtextxy(90,260," 5 - 1 minute");
  sel=getch();
     switch(sel)
     {case '1':sec=10;break;
     case '2':sec=20;break;
     case '3':sec=30;break;
     case '4':sec=40;break;
     case '5':sec=60;break;
     default:settings();
     }
  outtextxy(60,310,"Time Set!");
  break;
//Speed
  case '4':
  cleardevice();
  outtextxy(60,140," Please select your speed:");
  outtextxy(90,180," 1 - LOW");
  outtextxy(90,200," 2 - MID");
  outtextxy(90,220," 3 - HIGH");
  sel=getch();
     switch(sel)
     {case '1':speed=5;break;
     case '2':speed=10;break;
     case '3':speed=15;break;
     default:settings();
     }
  outtextxy(60,310,"Speed Set!");
  break;
default:menu();
 }
getch();
}
//////////////////////////////////////////////////////////////////////////////
