#include "FPToolkit.c"

void drawTree(int x1, int y1, int x2, int y2, int level) {
  if (level == 0) {
    return;
  }
  int dx = x2 - x1;
  int dy = y2 - y1;

  int x3 = x2 - dy;
  int y3 = y2 + dx;

  int x4 = x1 - dy;
  int y4 = y1 + dx;

  int x5 = x4 + (dx - dy) / 2;
  int y5 = y4 + (dx + dy) / 2;
  G_rgb(0, 1, 0);
  G_fill_triangle(x3, y3, x4, y4, x5, y5);

  G_rgb(0, 0, 0);
  G_line(x1, y1, x2, y2);
  G_line(x2, y2, x3, y3);
  G_line(x3, y3, x4, y4);
  G_line(x4, y4, x1, y1);
  double a[4], b[4];
  G_rgb(0.4, 0.2, 0.1); // brown
  a[0] = x1;
  b[0] = y1;
  a[1] = x2;
  b[1] = y2;
  a[2] = x3;
  b[2] = y3;
  a[3] = x4;
  b[3] = y4;
  double numab = 4;
  G_fill_polygon(a, b, numab);

  drawTree(x4, y4, x5, y5, level - 1);
  drawTree(x5, y5, x3, y3, level - 1);
}
int main() {
  double swidth, sheight;
  double center_x, center_y, size, x3, y3, x4, y4, i, r1, x, y;
  double lowleftx, lowlefty, width, height;
  double lowleftx1, lowlefty1, width1, height1;

  swidth = 800;
  sheight = 800;
  G_init_graphics(swidth, sheight);
  double l[2], f[2];
  double sr = 255 / 255.0;
  double sg = 0 / 255.0;
  double sb = 0 / 255.0;

  double er = 255 / 255.0;
  double eg = 255 / 255.0;
  double eb = 0 / 255.0;
  l[0] = 0;
  l[1] = 800;
  f[0] = swidth;
  f[1] = 800;
  for (i = 0; i < 1; i += 0.0001) {

    double r1 = sr + i * (er - sr);
    double g = sg + i * (eg - sg);
    double b = sb + i * (eb - sb);

    G_rgb(r1, g, b);
    double ny = l[1] - ((pow(i, 2)) * (f[0] - l[0]));

    G_line(l[0], ny, f[0], ny);
  }

  double er2 = 194 / 255.0;
  double eg2 = 178 / 255.0;
  double eb2 = 128 / 255.0;
  G_rgb(er2, eg2, eb2);
  lowleftx1 = 0;
  lowlefty1 = 0;
  width1 = 800;
  height = 200;
  G_rectangle(lowleftx, lowlefty, width, height);
  G_fill_rectangle(lowleftx1, lowlefty1, width1, height);

  double d[2], c[2], r, dx1, dy1;
  d[0] = 100;
  d[1] = 620;
  c[0] = 150;
  c[1] = 620;
  dx1 = d[0] - c[0];
  dy1 = d[1] - c[1];
  r = sqrt((dx1 * dx1) + (dy1 * dy1));
  G_rgb(1, 0, 0);
  G_circle(d[0], d[1], r);
  G_fill_circle(d[0], d[1], r);

  double u[2];
  double v[2];
  u[0] = 500;
  u[1] = 80;
  v[0] = 700;
  v[1] = 80;
  double dx3;
  double dy3;
  double x10 = u[0];
  double y10 = u[1];
  double x11 = v[0];
  double y11 = v[1];
  dx3 = x11 - x10;
  dy3 = y11 - y10;

  int x12 = x11 - dy3;
  int y12 = y11 + dx3;

  int x13 = x10 - dy3;
  int y13 = y10 + dx3;

  int x14 = x13 + (dx3 - dy3) / 2;
  int y14 = y13 + (dx3 + dy3) / 2;
  G_rgb(1, 0.8, 0.8);
  G_fill_triangle(x13, y13, x12, y12, x14, y14);

  G_rgb(0, 0, 0);
  G_line(x10, y10, x11, y11);
  G_line(x11, y11, x12, y12);
  G_line(x12, y12, x13, y13);
  G_line(x13, y13, x10, y10);
  double a1[4], b1[4];
  G_rgb(2.10, 0.24, 0.24); // brown
  a1[0] = x10;
  b1[0] = y10;
  a1[1] = x11;
  b1[1] = y11;
  a1[2] = x12;
  b1[2] = y12;
  a1[3] = x13;
  b1[3] = y13;
  double numab1 = 4;
  G_fill_polygon(a1, b1, numab1);

  double u1[2];
  double v1[2];
  u1[0] = 570;
  u1[1] = 80;
  v1[0] = 620;
  v1[1] = 80;
  double dx4;
  double dy4;
  double x101 = u1[0];
  double y101 = u1[1];
  double x111 = v1[0];
  double y111 = v1[1];
  dx4 = x111 - x101;
  dy4 = y111 - y101;

  int x121 = x111 - dy4;
  int y121 = y111 + dx4;

  int x131 = x101 - dy4;
  int y131 = y101 + dx4;
  G_rgb(0, 0, 0);
  G_line(x101, y101, x111, y111);
  G_line(x111, y111, x121, y121);
  G_line(x121, y121, x131, y131);
  G_line(x131, y131, x101, y101);
  double a2[4], b2[4];
  G_rgb(0.8, 0.8, 0); // brown
  a2[0] = x101;
  b2[0] = y101;
  a2[1] = x111;
  b2[1] = y111;
  a2[2] = x121;
  b2[2] = y121;
  a2[3] = x131;
  b2[3] = y131;
  double numab2 = 4;
  G_fill_polygon(a2, b2, numab2);

  double w[2], e[2], j[2];
  w[0] = 600;
  w[1] = 600;
  e[0] = 590;
  e[1] = 610;
  j[0] = 610;
  j[1] = 610;
  G_rgb(0, 0, 0);
  G_line(w[0], w[1], e[0], e[1]);
  G_line(w[0], w[1], j[0], j[1]);
  double w1[2], e1[2], j1[2];
  w1[0] = 700;
  w1[1] = 700;
  e1[0] = 690;
  e1[1] = 710;
  j1[0] = 710;
  j1[1] = 710;
  G_rgb(0, 0, 0);
  G_line(w1[0], w1[1], e1[0], e1[1]);
  G_line(w1[0], w1[1], j1[0], j1[1]);
  double w2[2], e2[2], j2[2];
  w2[0] = 500;
  w2[1] = 500;
  e2[0] = 490;
  e2[1] = 510;
  j2[0] = 510;
  j2[1] = 510;
  G_rgb(0, 0, 0);
  G_line(w2[0], w2[1], e2[0], e2[1]);
  G_line(w2[0], w2[1], j2[0], j2[1]);

  int x1 = 200;
  int y1 = 80;
  int x2 = 280;
  int y2 = 80;

  drawTree(x1, y1, x2, y2, 10);

  int key;
  key = G_wait_key();
  G_save_to_bmp_file("demo52.bmp");
  return 0;
}