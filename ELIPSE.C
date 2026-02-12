#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void ellipsePlotPoints(int x_cen, int y_cen, int x, int y) {
    putpixel(x_cen + x, y_cen + y, WHITE);
    putpixel(x_cen - x, y_cen + y, BLUE);
    putpixel(x_cen + x, y_cen - y, GREEN);
    putpixel(x_cen - x, y_cen - y, RED);
    delay(10);
}

void ellipseMid(int x_cen, int y_cen, int rx, int ry) {
    long rx2 = (long)rx * rx;
    long ry2 = (long)ry * ry;
    long tworx2 = 2 * rx2;
    long twory2 = 2 * ry2;

    long x = 0;
    long y = ry;
    long px = 0;
    long py = tworx2 * y;

    // region1
    long p = ry2 - (rx2 * ry) + (0.25 * rx2);
    while (px < py) {
	ellipsePlotPoints(x_cen, y_cen, x, y);
	x++;
	px += twory2;
	if (p < 0) {
	    p += ry2 + px;
	} else {
	    y--;
	    py -= tworx2;
	    p += ry2 + px - py;
	}
    }

    // region2
    p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
    while (y >= 0) {
	ellipsePlotPoints(x_cen, y_cen, x, y);
	y--;
	py -= tworx2;
	if (p > 0) {
	    p += rx2 - py;
	} else {
	    x++;
	    px += twory2;
	    p += rx2 - py + px;
	}
    }
}

void main() {
    int gd = DETECT, gm;
    int x_cen, y_cen, rx, ry;

    initgraph(&gd, &gm, "c:\\tc\\bgi");

    printf("Enter x_cen ");
    scanf("%d", &x_cen);
    printf("Enter y_cen ");
    scanf("%d", &y_cen);
    printf("Enter x-rad");
    scanf("%d", &rx);
    printf("Enter y-rad");
    scanf("%d", &ry);

    ellipseMid(x_cen, y_cen, rx, ry);

    getch();
    closegraph();
}
