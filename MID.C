#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<DOS.h>
void circleplotpoint(int x_cen, int y_cen, int x, int y) {
    putpixel(x_cen + x, y_cen + y, WHITE);
    putpixel(x_cen - x, y_cen + y, WHITE);
    putpixel(x_cen + x, y_cen - y, WHITE);
    putpixel(x_cen - x, y_cen - y, WHITE);
    putpixel(x_cen + y, y_cen + x, WHITE);
    putpixel(x_cen - y, y_cen + x, WHITE);
    putpixel(x_cen + y, y_cen - x, WHITE);
    putpixel(x_cen - y, y_cen - x, WHITE);
    delay(100);
}




void circlemid(int x_cen, int y_cen, int rad) {
    int x = 0;
    int y = rad;
    int p = 1 - rad;

    circleplotpoint(x_cen, y_cen, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        circleplotpoint(x_cen, y_cen, x, y);
    }
}

void main() {
    int gd = DETECT, gm;
    int x_cen, y_cen, rad;
   
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    printf("enter the x center ");
    scanf("%d",&x_cen);
    printf("enter the y center ");
    scanf("%d",&y_cen);
    printf("enter the radius ");
    scanf("%d",&rad);
    circlemid(x_cen,y_cen,rad);

    getch();
    closegraph();
}
