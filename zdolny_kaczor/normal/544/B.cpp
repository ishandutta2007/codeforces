# include <cstdio>
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  if ((n*n+1)/2<k)
      printf("NO\n");
  else
  {
      printf("YES\n");
      for (int i=0; i<n; ++i)
      {
          for (int l=0; l<n; ++l)
              if (k && (i+l)%2==0)
              {
                  printf("L");
                  k--;
              }
              else
                  printf("S");
          printf("\n");
      }
  }
}