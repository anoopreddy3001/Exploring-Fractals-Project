#include "FPToolkit.c"

void kochCurve(double x1, double y1, double x2, double y2, double depth) {
 
  if (depth == 0) {
    G_rgb(255, 0, 0);
    G_line(x1, y1, x2, y2);

    return;
  }

  else {
    double deltaX = x2 - x1;
    double deltaY = y2 - y1;
    double x3 = x1 + deltaX / 3;
    double y3 = y1 + deltaY / 3;
    double x4 = x2 - deltaX / 3;
    double y4 = y2 - deltaY / 3;
    double angle = M_PI / 3;
    double x5 = ((x3 + x4) / 2) + ((y4 - y3) * sin(angle));
    double y5 = ((y3 + y4) / 2) + ((x3 - x4) * sin(angle));
    kochCurve(x1, y1, x3, y3, depth - 1);
    kochCurve(x4, y4, x2, y2, depth - 1);
    kochCurve(x3, y3, x5, y5, depth - 1);
    kochCurve(x5, y5, x4, y4, depth - 1);
  }
}

int main() {

  int width, height;
  width = 800;
  height = 700;
  G_init_graphics(width, height);
  G_rgb(0, 0, 0);
  G_clear();
  double p[2], q[2];
  G_rgb(1, 0, 0);
  G_wait_click(p);
  G_fill_circle(p[0], p[1], 2);
  G_wait_click(q);
  G_fill_circle(q[0], q[1], 2);
  int x1 = p[0];
  int x2 = q[0];
  int y1 = p[1];
  int y2 = q[1];
  int d = x2 - x1;
  int h = d * sqrt(3.0) / 2.0;
  double x6 = x1 + d / 2;
  double y6 = y1 + h;
  kochCurve(x1, y1, x2, y2, 11);
  kochCurve(x2, y2, x6, y6, 11);
  kochCurve(x6, y6, x1, y1, 11);

  int key;
  key = G_wait_key(); // pause so user can see results
  //   G_save_image_to_file("demo.xwd") ;
  G_save_to_bmp_file("demo14.bmp");
}