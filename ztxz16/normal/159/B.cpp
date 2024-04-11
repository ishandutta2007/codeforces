#include <stdio.h>
#include <stdlib.h>

int n,m,i,j,ans1,ans2,x,y,a,b;
int S1[1005],S2[1005],s1[1005][1005],s2[1005][1005];

int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
       scanf("%d %d",&y,&x);
       S1[x]++;
       s1[x][y]++;
    }
    for(i=1;i<=m;i++)
    {
       scanf("%d %d",&b,&a);
       S2[a]++;
       s2[a][b]++;
    }
    for(i=1;i<=1000;i++)
    {
       if (S1[i]<S2[i]) ans1+=S1[i];
       else ans1+=S2[i];
       for(j=1;j<=1000;j++)
       {
          if (s1[i][j]<s2[i][j]) ans2+=s1[i][j];
             else ans2+=s2[i][j];
       }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}