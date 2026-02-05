
#include<graphics.h>
#include<conio.h>
#include<stdio.h>


void main(void)
{

int gdriver=DETECT,gmode;
int x1=100,y1=100;
int x2=200,y2=100;
 int x3=200,y3=200;
 int x4=150,y4=200;
 int a3=250 ,b3=100;


 int a4=250 ,b4=200;
 int a1=300, b1=100;
 int a2=300, b2=200;
 int a5=250, b5=144;
 int a6=300, b6=144;
 int l1=333, m1=100;
 int l2=333, m2=200;
 int l3=400, m3=200;
 int c1=433, d1=100;
 int c2=433, d2=200;
 int c3=483, d3=100;
 int c4=483, d4=200;
 int c5=433, d5=144;
 int c6=483, d6=144;
 int c7=500, d7=100;
 int c8=600, d8=100;
 int c9=600, d9=200;
 int c10=555, d10=200;
 int i;
initgraph(&gdriver ,&gmode, "c:\\TC\\BGI");
setcolor(RED);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x4,y4);
line(a1,b1,a2,b2);
line(a3,b3,a4,b4);
line(a1,b1,a3,b3);
line(a5,b5,a6,b6);
line(l1,m1,l2,m2);
line(l2,m2,l3,m3);
line(c1,d1,c2,d2);
line(c3,d3,c4,d4);
line(c1,d1,c3,d3);
line(c5,d5,c6,d6);
line(c7,d7,c8,d8);
line(c8,d8,c9,d9);
line(c9,d9,c10,d10);

/*for(i=0;i<77;i++)
{
arc(i*40,i*40,0,360,i*40);
delay  (100);
} */
getch();
closegraph();
}