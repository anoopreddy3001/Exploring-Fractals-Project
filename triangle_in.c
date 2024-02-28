#include "FPToolkit.c"
double width = 800;
void triangle(double x0, double y0, double x1, double y1, double x2, double y2,
              double depth) {
  if (depth == 0) {

    // for (int i = 0; i <= depth; i++) {
    double r, g, b;
    r = 255.0 / 255.0;
    g = 0 / 255.0;
    b = 0 / 255.0;
    G_rgb(r, g, b);
    G_triangle(x0, y0, x1, y1, x2, y2);
    G_fill_triangle(x0, y0, x1, y1, x2, y2);
    double gh = 60.0 / 255.0;
    double bh = 60.0 / 255.0;
    g = g + gh;
    b = b + bh;
    // return;
    // }
  } else {
    double x02 = (x0 + x2) / 2.0;
    double y02 = (y0 + y2) / 2.0;
    double x12 = (x1 + x2) / 2.0;
    double y12 = (y1 + y2) / 2.0;
    double x01 = (x1 + x0) / 2.0;
    double y01 = (y1 + y0) / 2.0;
    // G_rgb(1, 0, 0);
    // G_triangle(x0, y0, x1, y1, x2, y2);
    // G_fill_triangle(x01, y01, x02, y02, x12, y12);
    triangle(x0, y0, x02, y02, x01, y01, depth - 1);
    triangle(x02, y02, x2, y2, x12, y12, depth - 1);
    triangle(x01, y01, x12, y12, x1, y1, depth - 1);
  }
}
void triangle1(double x0, double y0, double x2, double y2, double x66,
               double y66, double depth) {
  if (depth == 0) {

    // for (int i = 0; i <= depth; i++) {
    double r, g, b;
    r = 0 / 255.0;
    g = 255.0 / 255.0;
    b = 0 / 255.0;
    G_rgb(r, g, b);
    G_triangle(x0, y0, x2, y2, x66, y66);
    G_fill_triangle(x0, y0, x2, y2, x66, y66);
    double rh = 60.0 / 255.0;
    double bh = 60.0 / 255.0;
    r = r + rh;
    b = b + bh;
    // return;
    // }
  } else {
    double x02 = (x0 + x2) / 2.0;
    double y02 = (y0 + y2) / 2.0;
    double x066 = (x0 + x66) / 2.0;
    double y066 = (y0 + y66) / 2.0;
    double x266 = (x2 + x66) / 2.0;
    double y266 = (y2 + y66) / 2.0;
    // G_rgb(1, 0, 0);
    // G_triangle(x0, y0, x1, y1, x2, y2);
    // G_fill_triangle(x01, y01, x02, y02, x12, y12);
    triangle(x0, y0, x066, y066, x02, y02, depth - 1);
    triangle(x066, y066, x66, y66, x266, y266, depth - 1);
    triangle(x02, y02, x266, y266, x2, y2, depth - 1);
  }
}
int main() {
  double swidth, sheight;
  double x0, y0, x1, y1, x2, y2, depth;
  swidth = 1000;
  sheight = 1000;
  printf("enter the depth value");
  scanf("%lf", &depth);
  G_init_graphics(swidth, sheight);
  float l;
  G_rgb(1, 1, 1);
  G_clear();
  double p[2], q[2];
  p[0] = 300;
  p[1] = 100;
  q[0] = 600;
  q[1] = 100;
  //double center_x = q[0] - p[0];
  //double center_y = q[1] - p[1];
  //double u[2];
  //u[0] = p[0] - center_y;
  //u[1] = p[1] + center_x;
  double d = x2 - x0;
  double h = d * sqrt(3.0) / 2.0;
  x2 = x0 + d / 2;
  y2 = y0 + h;
  x0 = p[0];
  y0 = p[1];
  x1 = q[0];
  y1 = q[1];
  //x2 = u[0];
  //y2 = u[1];
  double d1 = x2 - x0;
  double h1 = d1 * sqrt(3.0) / 2.0;
  double x66 = x0 + d1 / 2;
  double y66 = y0 + h1;
  triangle(x0, y0, x1, y1, x2, y2, depth);
  //triangle1(x0, y0, x2, y2, x66, y66, depth);
  int key;
  key = G_wait_key();
  G_save_to_bmp_file("demo6.bmp");
}