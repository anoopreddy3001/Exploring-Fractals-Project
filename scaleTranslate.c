#include "FPToolkit.c"
double x = 0;
double y = 0;
double width = 800, height = 800;
void scale(double sfx, double sfy) {

  x *= sfx;
  y *= sfy;
}
void translate(double dx, double dy) {

  x = x + dx;
  y = y + dy;
}
void rotate(double d) {
  double r, a;
  double t = d * (M_PI / 180);
  double temp;
  double c, s;
  c = cos(t);
  s = sin(t);
  temp = (x * c) - (y * s);
  y = (y * c) + (x * s);
  x = temp;
}
void line(double r) {
  if (r < 0.5) {
    scale(0.5, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else {
    scale(0.5, 0.5);
    translate(0.5, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  }
}
void square(double r) {
  if (r < 0.25) {
    scale(0.5, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 0.5 && r > 0.25) {
    scale(0.5, 0.5);
    translate(0.5, 0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 0.75 && r > 0.5) {
    scale(0.5, 0.5);
    translate(0, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else {
    scale(0.5, 0.5);
    translate(0.5, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  }
}
void triangle(double r) {
  if (r < 0.33) {
    scale(0.5, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 0.66) {
    scale(0.5, 0.5);
    translate(0.5, 0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else {
    scale(0.5, 0.5);
    translate(0, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  }
}
void carpet(double r) {
  if (r < 0.11) {
    scale(0.33, 0.33);
    // translate(0, 0.5);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r > 0.11 && r < 0.22) {
    scale(0.33, 0.33);
    translate(0.33, 0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r > 0.22 && r < 0.33) {
    scale(0.33, 0.33);
    translate(0.66, 0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r > 0.33 && r < 0.44) // 4
  {
    scale(0.33, 0.33);
    translate(0, 0.33);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r > 0.55 && r < 0.66) // 6
  {
    scale(0.33, 0.33);
    translate(0.66, 0.33);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r > 0.66 && r < 0.77) // 7
  {
    scale(0.33, 0.33);
    translate(0, 0.66);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r > 0.77 && r < 0.88) // 8
  {
    scale(0.33, 0.33);
    translate(0.33, 0.66);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r > 0.88 && r < 0.99) // 9
  {
    scale(0.33, 0.33);
    translate(0.66, 0.66);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  }
}
void name(double r) {
  if (r < 1.0 / 12.0) // m-1
  {
    scale(6.0 / 18.0, 1.0 / 8.0);
    rotate(90);
    translate(1.0 / 18.0, 1.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 2.0 / 12.0) // m-2
  {
    scale(4.0 / 18.0, 1.0 / 8.0);
    rotate(120);
    translate(4.0 / 18.0, 3.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 3.0 / 12.0) // m-3
  {
    scale(4.0 / 18.0, 1.0 / 8.0);
    rotate(60);
    translate(4.0 / 18.0, 3.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 4.0 / 12.0) // m-4
  {
    scale(6.0 / 18.0, 1.0 / 8.0);
    rotate(90);
    translate(5.0 / 18.0, 1.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 5.0 / 12.0) // j-5
  {
    scale(5.0 / 18.0, 1.0 / 8.0);
    // rotate(90);
    translate(6.0 / 18.0, 6.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 6.0 / 12.0) // j-6
  {
    scale(5.0 / 18.0, 1.0 / 8.0);
    rotate(90);
    translate(9.0 / 18.0, 2.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 7.0 / 12.0) // j-7
  {
    scale(3.0 / 18.0, 1.0 / 8.0);
    // rotate(60);
    translate(7.0 / 18.0, 1.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 8.0 / 12.0) // r-8
  {
    scale(6.0 / 18.0, 1.0 / 8.0);
    rotate(90);
    translate(13.0 / 18.0, 1.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 9.0 / 12.0) // r-9
  {
    scale(4.0 / 18.0, 1.0 / 8.0);
    // rotate(60);
    translate(13.0 / 18.0, 6.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 10.0 / 12.0) // r-10
  {
    scale(3.0 / 18.0, 1.0 / 8.0);
    rotate(90);
    translate(16.0 / 18.0, 4.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else if (r < 11.0 / 12.0) // r-11
  {
    scale(4.0 / 18.0, 1.0 / 8.0);
    // rotate(60);
    translate(13.0 / 18.0, 4.0 / 18.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  } else // r-12
  {
    scale(4.0 / 18.0, 1.0 / 8.0);
    rotate(120);
    translate(16.0 / 18.0, 1.0 / 8.0);
    G_rgb(1, 1, 1);
    G_point(x * width, y * height);
  }
}
void fern(double r) {
  if (r < 0.25) {
    translate(-0.5, 0);
    rotate(14.715);
    scale(0, 0.156);
    translate(0, 0);
    translate(0.5, 0);
    G_rgb(0, 1, 0);

    G_point(x * width, y * height);
  } else if (r < 0.5) {

    translate(-0.5, 0);
    rotate(-2.678);
    scale(0.849, 0.849);
    translate(0, 0.160);
    translate(0.5, 0);
    G_rgb(0, 1, 0);

    G_point(x * width, y * height);
  } else if (r < 0.75) {

    translate(-0.5, 0);
    rotate(52.462);
    scale(-0.383, 0.383);
    translate(0, 0.040);
    translate(0.5, 0);
    G_rgb(0, 1, 0);

    G_point(x * width, y * height);
  } else {
    translate(-0.5, 0);
    rotate(51.418);
    scale(0.335, 0.335);
    translate(0, 0.160);
    translate(0.5, 0);
    G_rgb(0, 1, 0);

    G_point(x * width, y * height);
  }
}
int main() {
  int width, height;
  double x, y;
  int i, q;
  width = 800;
  height = 800;
  G_init_graphics(width, height);
  G_rgb(0, 0, 0);
  G_clear();
  double r;
  for (i = 0; i < 60000000; ++i) {
    r = drand48();
    // line(r);
    // square(r);
    // triangle(r);
    // carpet(r);
    name(r);
    // fern(r);
    //  if (i % 1000000 == 0) //{
    //  G_display_image();
    //  usleep(1000000);
    // }
  }
  int key;
  key = G_wait_key();
  G_save_to_bmp_file("demo14.bmp");
}