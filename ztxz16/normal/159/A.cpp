#include <stdio.h>
#include <stdlib.h>

int n,d,i,j,tot,ans,a[2005],b[2005],t[2005],hash[2005][2005];
char name[2005][105],str1[105],str2[105];

int bj(char a[],char b[]);
void copy(char a[],char b[]);

int main()
{
    scanf("%d %d\n",&n,&d);
    for(i=1;i<=n;i++)
    {
       scanf("%s %s %d\n",str1+1,str2+1,&t[i]);
       for(j=1;j<=tot;j++)
          if (bj(str1,name[j])==1)
          {
             a[i]=j;
             break;
          }
       if (j>tot)
       {
          tot++;
          copy(name[tot],str1);
          a[i]=tot;
       }
       for(j=1;j<=tot;j++)
          if (bj(str2,name[j])==1)
          {
             b[i]=j;
             break;
          }
       if (j>tot)
       {
          tot++;
          copy(name[tot],str2);
          b[i]=tot;
       }
    }
    for(i=1;i<n;i++)
    {
       for(j=i+1;j<=n;j++)
       {
          if (t[j]>t[i]+d) break;
          if (t[i]==t[j]) continue;
          if (a[i]==b[j] && a[j]==b[i])
             hash[a[i]][b[i]]=hash[b[i]][a[i]]=1;
       }
    }
    for(i=1;i<tot;i++)
       for(j=i+1;j<=tot;j++)
          if (hash[i][j]==1) ans++;
    printf("%d\n",ans);
    for(i=1;i<tot;i++)
       for(j=i+1;j<=tot;j++)
          if (hash[i][j]==1) printf("%s %s\n",name[i]+1,name[j]+1);
    return 0;
}

int bj(char a[],char b[])
{
    int i;
    for(i=1;a[i]!=0;i++)
       if (a[i]!=b[i]) return 0;
    if (b[i]==0) return 1;
    return 0;
}

void copy(char a[],char b[])
{
     int i;
     for(i=1;b[i]!=0;i++)
        a[i]=b[i];
     a[i]=0;
     return;
}