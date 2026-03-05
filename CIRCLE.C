#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int xmin = 100, ymin = 100, xmax = 400, ymax = 400;

int computeCode(int x, int y)
{
    int code = 0;
    if (y > ymax) code |= 8;  // Top
    if (y < ymin) code |= 4;  // Bottom
    if (x > xmax) code |= 2;  // Right
    if (x < xmin) code |= 1;  // Left
    return code;
}

void main()
{
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2;
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

    rectangle(xmin, ymin, xmax, ymax);

    printf("Enter X1 Y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter X2 Y2: ");
    scanf("%d %d", &x2, &y2);

   
    

    if (code1 == 0 && code2 == 0)
    {
        line(x1, y1, x2, y2);
        printf("Line is completely inside\n");
    }
    else if (code1 & code2)
    {
        printf("Line is completely outside\n");
    }
    else
    {
        float m;
        int y, x;

        m = (float)(y2 - y1) / (x2 - x1);

        if (x1 < xmin) { y = (int)(m * (xmin - x1) + y1); x1 = xmin; y1 = y; }
        if (x1 > xmax) { y = (int)(m * (xmax - x1) + y1); x1 = xmax; y1 = y; }
        if (y1 < ymin) { x = (int)((ymin - y1) / m + x1); y1 = ymin; x1 = x; }
        if (y1 > ymax) { x = (int)((ymax - y1) / m + x1); y1 = ymax; x1 = x; }

        if (x2 < xmin) { y = (int)(m * (xmin - x1) + y1); x2 = xmin; y2 = y; }
        if (x2 > xmax) { y = (int)(m * (xmax - x1) + y1); x2 = xmax; y2 = y; }
        if (y2 < ymin) { x = (int)((ymin - y1) / m + x1); y2 = ymin; x2 = x; }
        if (y2 > ymax) { x = (int)((ymax - y1) / m + x1); y2 = ymax; x2 = x; }

        line(x1, y1, x2, y2);
        printf("Line is partially inside\n");
    }

    getch();
    closegraph();
}
