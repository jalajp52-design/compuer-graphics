#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void bresenhamAlgorithm(int x1, int y1, int x2, int y2) {
    int deltax = x2 - x1;
    int deltay = y2 - y1;
    int p = 2 * deltay - deltax;
    int x = x1;
    int y = y1;

    
    putpixel(x, y, WHITE);

  
    if (deltay > deltax) {
    
        int temp = x;
        x = y;
        y = temp;

      
        deltax = x2 - x1;
        deltay = y2 - y1;
    }

    while (x <= x2) {
     
        putpixel(x, y, WHITE);

       
        if (p < 0) {
            x++;
            p = p + 2 * deltay;
        }
    
        else {
            x++;
            y++;
            p = p + 2 * (deltay - deltax);
        }
    }
}

int main() {
    int gd = DETECT, gmode;
    initgraph(&gd, &gmode, "C:\\Turboc3\\BGI");

    int x1, y1, x2, y2;
    printf("Enter x1: ");
    scanf("%d", &x1);
    printf("Enter y1: ");
    scanf("%d", &y1);
    printf("Enter x2: ");
    scanf("%d", &x2);
    printf("Enter y2: ");
    scanf("%d", &y2);

    bresenhamAlgorithm(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

