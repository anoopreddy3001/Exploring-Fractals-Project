#include "FPToolkit.c"
int main() {
  int swidth, sheight, x, y,i;
  swidth = 400;
  sheight = 400;
  G_init_graphics(swidth, sheight);
  G_rgb(1, 1, 1);
  G_clear();
  for (i = 0; i < 1; i+=0.01) 
  {
    
    G_rgb(0, 0, 0);
    G_point(x,y);
  }
  int key;
  key = G_wait_key();
  G_save_to_bmp_file("demo6.bmp");
  return 0;
}