#include <stdio.h>

void bigMult(unsigned int n, unsigned char *a, unsigned char *b, unsigned char *c)
{
   unsigned long x;
   unsigned int i, k;

   x = 0;
   for (k = 0;k < n; k++)
   {
      for (i = 0; i <= k; i++)
	 x += ((unsigned long) b[i]) * c[k - i];
      a[k] = (unsigned char) x;
      x >>= 8;
   }
   for (;k < (unsigned int) 2 * n; k++)
   {
      for (i = k - n + 1; i < n; i++)
	 x += ((unsigned long) b[i]) * c[k - i];
      a[k] = (unsigned char) x;
      x >>= 8;
   }
}

void assignBigNum(unsigned int n, int x, unsigned char *p)
{
   int i;

   for (i = n - 1; i >= 0; i--)
   {
      p[i] = x % 10;
      x = x / 10;
   }
}

void printBigNum(unsigned int n, unsigned char *a)
{
   int i;

   for (i = n - 1; i > 0; i--)
      if (a[i] > 9)
      {
	 a[i-1] += a[i] / 10;
	 a[i] = a[i] % 10;
      }
   for (i = 0; i < n; i++)
      printf("%i ", a[i]);
   puts(" <---");
}

void main()
{
   unsigned int bigN;
   unsigned char a[256];
   unsigned char b[128];
   unsigned char c[128];
   int x, y;

   bigN = 8;
   printf("Please input x, y =");
   scanf("%i %i", &x, &y);
   assignBigNum(bigN, x, b);
   assignBigNum(bigN, y, c);
   printBigNum(bigN, b);
   printBigNum(bigN, c);
   puts("=====================================================");
   bigMult(bigN, a, b, c);
   printBigNum(2*bigN, a);
}
