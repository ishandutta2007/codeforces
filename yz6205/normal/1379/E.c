#include <stdio.h>
#include <stdlib.h>

void no_answer() __attribute__ ((noreturn));

void no_answer() 
{
  puts("NO");
  exit(0);
}

#define N 100005
int fa[N];

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  if (n % 2 ==0) no_answer();

  int limit = (n - 3) / 2;
  if (limit < 0) limit = 0;

  if (k > limit) no_answer();

  if ((n & (n+1)) && k ==0) no_answer();
  if (!(n & (n+1)) && k == 1) no_answer();
  if (n == 9 && k == 2) no_answer();

  puts("YES");

  int base = 2 * (k - 1);
  if (base < 0) base = 0;
  for (int i=1; i<base; i += 2)
  {
    fa[i] = i - 2;
    fa[i + 1] = i;
  }
  fa[base + 1] = base - 1;
  for (int i=base+2; i<=n; ++i) 
  {
    fa[i] = base + (i - base) / 2;
  }

  if (!((n - base) & (n - base + 1)) && k)
  {
    fa[n] = 2;
    fa[n - 1] = 2;
  }

  if (fa[1] < 0)
    fa[1] = 0;
  
  for (int i=1; i<=n; ++i)
    printf("%d%c", fa[i], " \n"[i == n]);

  return 0;
}