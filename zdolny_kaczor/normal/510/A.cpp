# include <cstdio>
int main ()
{
int n, m;
scanf ("%d%d", &n, &m);
for (int i=0; i<n; ++i)
{
for (int k=0; k<m; ++k)
if (i%2==0 || (i%4==1 && k==m-1) || (i%4==3 && k==0))
  putchar ('#');
else
  putchar ('.');
putchar ('\n');
}
}