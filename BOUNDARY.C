#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<DOS.h>
void BoundaryFill(int x, int y, int newcolor, int Bcolor)
{
    int current = getpixel(x, y);
    if (current != Bcolor && current != newcolor)
    {
	putpixel(x, y, newcolor);
	delay(1);
	BoundaryFill(x+1, y, newcolor, Bcolor);
	BoundaryFill(x-1, y, newcolor, Bcolor);
	BoundaryFill(x, y+1, newcolor, Bcolor);
	BoundaryFill(x, y-1, newcolor, Bcolor);
    }
}

void main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

    rectangle(50,50,100,100);
    BoundaryFill(58,58,3,15);

    getch();
    closegraph();
}
