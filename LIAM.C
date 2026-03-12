#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int xmin = 100, ymin = 100, xmax = 400, ymax = 400;

void main() {
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2, i;
    float t1 = 0.0, t2 = 1.0;
    float dx, dy, p[4], q[4], t;

    initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

    rectangle(xmin, ymin, xmax, ymax);

    printf("Enter X1 Y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter X2 Y2: ");
    scanf("%d %d", &x2, &y2);

    setcolor(RED);
    line(x1, y1, x2, y2);
    setcolor(WHITE);

    dx = x2 - x1;
    dy = y2 - y1;

    p[0] = -dx; q[0] = x1 - xmin;
    p[1] = dx;  q[1] = xmax - x1;
    p[2] = -dy; q[2] = y1 - ymin;
    p[3] = dy;  q[3] = ymax - y1;

    for (i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) {
            printf("Line is parallel and completely outside.\n");
            getch();
            closegraph();
            return;
        }

        if (p[i] < 0) {
            t = q[i] / p[i];
            if (t > t1) {
                t1 = t;
            }
        } else if (p[i] > 0) {
            t = q[i] / p[i];
            if (t < t2) {
                t2 = t;
            }
        }
    }

    if (t1 < t2) {
        int new_x1 = x1 + t1 * dx;
        int new_y1 = y1 + t1 * dy;
        int new_x2 = x1 + t2 * dx;
        int new_y2 = y1 + t2 * dy;

        cleardevice();
        setcolor(WHITE);
        rectangle(xmin, ymin, xmax, ymax);

        setcolor(GREEN);
        line(new_x1, new_y1, new_x2, new_y2);
        
        // Check if the endpoints changed
        if (t1 == 0.0 && t2 == 1.0) {
            printf("Line is completely inside.\n");
        } else {
            printf("Line is partially inside.\n");
        }

        printf("Line accepted from (%d, %d) to (%d, %d)\n", new_x1, new_y1, new_x2, new_y2);
    } else {
        printf("Line completely outside.\n");
    }

    getch();
    closegraph();
}