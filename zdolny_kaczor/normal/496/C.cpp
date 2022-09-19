# include <cstdio>
const int MN=104;
char tab [MN][MN];
bool diff [MN];
int main ()
{
  int n, m;
  scanf ("%d%d", &n, &m);
  for (int i=0; i<n; ++i)
    scanf ("%s", tab[i]);
  int res=0;
  for (int i=0; i<m; i++)
  {
    bool OK=true;
    for (int k=0; k<n-1; ++k)
      if (!diff[k] && tab [k][i]>tab [k+1][i])
      {
        OK=false;
        break;
      }
    if (OK)
    {
      for (int k=0; k<n-1; ++k)
        if (tab [k][i]<tab [k+1][i])
          diff [k]=true;
    }
    else
      res++;
  }
  printf ("%d\n", res);
}