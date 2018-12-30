#include<dos.h>

int main()
{
   sound(250);delay(250);
   nosound();delay(20);
   sound(250);delay(300);
   sound(375);delay(250);
   nosound();delay(20);
   sound(375);delay(300);
   sound(425);delay(250);
   nosound();delay(20);
   sound(425);delay(300);
   sound(375);delay(600);      //1

   sound(330);delay(250);
   nosound();delay(20);
   sound(330);delay(300);
   sound(310);delay(250);
   nosound();delay(20);
   sound(310);delay(300);
   sound(280);delay(250);
   nosound();delay(20);
   sound(280);delay(300);
   sound(250);delay(600);      //2

   sound(375);delay(400);
   nosound();delay(20);
   sound(375);delay(150);
   sound(330);delay(400);
   nosound();delay(20);
   sound(330);delay(150);
   sound(310);delay(300);
   nosound();delay(20);
   sound(310);delay(300);
   sound(280);delay(600);      //3

   sound(375);delay(300);
   nosound();delay(20);
   sound(375);delay(300);
   sound(330);delay(300);
   nosound();delay(20);
   sound(330);delay(300);
   sound(310);delay(300);
   nosound();delay(20);
   sound(310);delay(300);
   sound(280);delay(600);      //4

   sound(250);delay(250);
   nosound();delay(20);
   sound(250);delay(300);
   sound(375);delay(250);
   nosound();delay(20);
   sound(375);delay(300);
   sound(425);delay(250);
   nosound();delay(20);
   sound(425);delay(300);
   sound(375);delay(600);      //5

   sound(330);delay(250);
   nosound();delay(20);
   sound(330);delay(300);
   sound(310);delay(250);
   nosound();delay(20);
   sound(310);delay(300);
   sound(280);delay(250);
   nosound();delay(20);
   sound(280);delay(300);
   sound(250);delay(600);      //6

   nosound();
   return 0;
}
