/* Convert an M9312 image to a memory image. */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int b0, b1, b2, b3;
  int word;

  for (;;) {
    b0 = getchar ();
    if (feof (stdin))
      exit (0);
    b1 = getchar ();
    b2 = getchar ();
    b3 = getchar ();
    if (feof (stdin)) {
      fprintf (stderr, "Bad input data.\n");
      exit (1);
    }

    if ((b0 & 0xF0) || (b1 & 0xF0) || (b2 & 0xF0) || (b3 & 0xF0)) {
      fprintf (stderr, "Bad input data.\n");
      exit (1);
    }

    word =  (b2 & 0x01);
    word |= (b0 & 0x0E);
    word |= b1 << 4;
    word |= (b0 & 0x01) << 8;
    word |= (b2 & 0x0E) << 8;
    word |= b3 << 12;
    word ^= 0x1C00;

    putchar (word & 0xFF);
    putchar (word >> 8);
  }
}
