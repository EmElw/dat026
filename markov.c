#include <stdio.h>
#include <stdlib.h>

char x[5000000];

int main()
{int c, i, eqsofar, max, n = 0, k = 100;
 char *p, *nextp, *q;
 while ((c = getchar()) != EOF)
   x[n++] = c;
 x[n] = 0;
 p = x;
 srand(1);
 for (max = 2000; max > 0; max--) {
   eqsofar = 0;
   for (q = x; q < x + n - k + 1; q++) {
     for (i = 0; i < k && *(p+i) == *(q+i); i++)
       ;
     if (i == k)
       if (rand() % ++eqsofar == 0)
	 nextp = q;
   }
   c = *(nextp+k);
   if (c == 0)
     break;
   putchar(c);
   p = nextp+1;
 }
 return 0;
}