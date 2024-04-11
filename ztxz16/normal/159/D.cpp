#include <stdio.h>
#include <stdlib.h>

char str[2005];
long long f[2005][2005];
long long s1[2005],snow,ans,i,j,n,len;

int main()
{
    gets(str+1);
    for(i=1;str[i]!=0;i++);
    n=i-1;
    for(i=n;i>=1;i--)
    {
       f[i][i]=1;
       if (i+1<=n)
       {
          if (str[i]==str[i+1]) f[i][i+1]=1;
          else f[i][i+1]=0;
       }
       for(j=i+2;j<=n;j++)
          if (str[i]==str[j] && f[i+1][j-1]==1) f[i][j]=1;
    }
    for(i=1;i<=n;i++)
    {
       s1[i]=s1[i-1];
       for(j=1;j<=i;j++)
          s1[i]+=f[j][i];
    }
    for(i=2;i<=n;i++)
    {
       snow=0;
       for(j=i;j<=n;j++)
          snow+=f[i][j];
       ans+=(snow*s1[i-1]);
    }
    printf("%I64d\n",ans);
    return 0;
}