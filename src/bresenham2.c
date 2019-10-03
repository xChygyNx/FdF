
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  s_delta
{
    int length_x;
    int length_y;
    int length;
    int dx;
    int dy;
}               t_delta;

void draw_along_x(t_delta delta, int x, int y)
{
      int d;

      d = -delta.length_x;
      ++delta.length;
      while (delta.length--)
      {
            printf("[%d,%d]\n", x, y);
            x += delta.dx;
            d += 2 * delta.length_y;
            if (d > 0)
            {
                  d -= 2 * delta.length_x;
                  y += delta.dy;
            }
      }
}

void draw_along_y(t_delta delta, int x, int y)
{
      int d;

      d = -delta.length_y;
      ++delta.length;
      while (delta.length--)
      {
            printf("[%d,%d]\n", x, y);
            y += delta.dy;
            d += 2 * delta.length_x;
            if (d > 0)
            {
                  d -= 2 * delta.length_y;
                  x += delta.dx;
            }
      }
}

void draw_line(int x1, int y1, int x2, int y2)
{
      t_delta delta;

      delta.dx = (x2 - x1 >= 0 ? 1 : -1);
      delta.dy = (y2 - y1 >= 0 ? 1 : -1);
      delta.length_x = abs(x2 - x1);
      delta.length_y = abs(y2 - y1);
      delta.length = delta.length_x > delta.length_y ? delta.length_x : delta.length_y;

      if (delta.length == 0)
            printf("[%d,%d]\n", x1, y1);
      else
      {
            if (delta.length_y <= delta.length_x)
                  draw_along_x(delta, x1, y1);
            else
                  draw_along_y(delta, x1, y1);
      }
}

int     main(void)
{
    draw_line(30, 30, 3, 15);
    return (0);
}