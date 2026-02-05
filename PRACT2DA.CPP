#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void lineDDA(int xa, int xb, int ya, int yb){
int dx = xb-xa, dy = yb-ya, steps, k;
float xInc, yInc, x=xa, y=ya;

if(abs(dx) > abs(dy)){
	steps = abs(dx);
}
else
{
	steps = abs(dy);
	}
	xInc = dx/(float) steps;
	yInc = dy/(float) steps;

	putpixel((int) x, (int) y, RED);
	for (k=0; k<steps; k++)
	{
	x += xInc;
	y += yInc;
	putpixel((int) x, (int) y, RED);
	}
	}
 void main(){
 int gd = 0,gmode;
 initgraph(&gd, &gmode, "C:\\TC\\BGI");
 int xa, xb, ya, yb;
 printf("Enter xa: ");
 scanf("%d",&xa);
 printf("Enter xb: ");
 scanf("%d",&xb);
 printf("Enter ya: ");
 scanf("%d",&ya);
 printf("Enter yb: ");
 scanf("%d",&yb);
 lineDDA(xa, xb, ya, yb);
 getch();
 closegraph();
 }

