# include <cstdio>
int a [310];
int main ( )
{
  int n, k;
  scanf ("%d%d", &n, &k);
  int low=30000, high=0;
  for (int i=0; i <n;++i)
  {
    scanf("%d", a+i);
    if (a [i]> high) high=a [i];
    if ( a [i]<low) low=a [i];
    
  }
  if (low+k <high)
    printf ("NO\n");
  else
  {
    printf("YES\n");
    for (int i=0; i <n; ++i)
    {
      for (int x=0; x <a [i]; ++x)
        printf ("%d ", 1+x% k);
      putchar (10);
    }
  }
}