#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void FloodFill(int x, int y, int newcolor, int Bcolor)
{
    if(getpixel(x, y) == Bcolor)   
    {
	putpixel(x, y, newcolor);

        FloodFill(x+1, y, newcolor, Bcolor);
        FloodFill(x-1, y, newcolor, Bcolor);
        FloodFill(x, y+1, newcolor, Bcolor);
        FloodFill(x, y-1, newcolor, Bcolor);
    }
}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

    rectangle(50, 50, 100, 100);   
    FloodFill(58, 58, 3, 0);       
    getch();
    closegraph();
    return 0;
}
