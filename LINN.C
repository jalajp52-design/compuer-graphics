#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int xmin = 100, ymin = 100, xmax = 400, ymax = 400;


int computeCode(int x, int y) {
    int code = 0;
    if (y > ymax) { code |= 8; } // Top
    if (y < ymin) { code |= 4; } // Bottom
    if (x > xmax) { code |= 2; } // Right
    if (x < xmin) { code |= 1; } // Left
    return code;
}

void main() {
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2;
    int code1, code2, code_out;
    int accept = 0;
    int x, y;

    initgraph(&gdriver, &gmode, "C:\\TC\\BGI"); 
    
 
    rectangle(xmin, ymin, xmax, ymax);
    
    printf("Enter X1 Y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter X2 Y2: ");
    scanf("%d %d", &x2, &y2);
    
 
    setcolor(RED);
    line(x1, y1, x2, y2);
    setcolor(WHITE);

    code1 = computeCode(x1, y1);
    code2 = computeCode(x2, y2);

   
    while (1) {
        if (code1 == 0 && code2 == 0) {
            
            accept = 1;
            break;
        } else if (code1 & code2) {
  
            break;
        } else {
     
            if (code1 != 0) {
                code_out = code1;
            } else {
                code_out = code2;
            }

            
            if (code_out & 8) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & 4) { 
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & 2) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code_out & 1) { 
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
      
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(GREEN);
        line(x1, y1, x2, y2);
        printf("Line accepted from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
    } else {
        printf("Line completely outside.\n");
    }

    getch();
    closegraph();
}
