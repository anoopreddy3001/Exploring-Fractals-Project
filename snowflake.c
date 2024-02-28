#include "FPToolkit.c"

void kochCurve(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        G_rgb(255,0,0);
        G_line(x1, y1, x2, y2);
        return;
    }

    int deltaX = x2 - x1;
    int deltaY = y2 - y1;

    int x3 = x1 + deltaX / 3;
    int y3 = y1 + deltaY / 3;

    int x4 = x2 - deltaX / 3;
    int y4 = y2 - deltaY / 3;

    double angle = M_PI / 3;
    int x5 = (x3 + x4) / 2 + (y4 - y3) * sin(angle);
    int y5 = (y3 + y4) / 2 - (x3 - x4) * sin(angle);

    kochCurve(x1, y1, x3, y3, depth - 1);
    kochCurve(x3, y3, x5, y5, depth - 1);
    kochCurve(x5, y5, x4, y4, depth - 1);
    kochCurve(x4, y4, x2, y2, depth - 1);
}

int main() {
    
    int width, height;
    width = 600;
    height = 600;
    G_init_graphics(width, height);
    G_rgb(0,0,0);
    G_clear();

    int x1 = 100;
    int y1 = 100;
    int x2 = 500;
    int y2 = 100;

    kochCurve(x1, y1, x2, y2, 4);

    int key;
    key = G_wait_key(); // pause so user can see results
    //   G_save_image_to_file("demo.xwd") ;
    G_save_to_bmp_file("demo14.bmp");
}
