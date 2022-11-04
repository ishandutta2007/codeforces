#include <stdio.h>
#include <stdlib.h>

int min,max,mm,n,i,j,a[105],b[105],sel[105];
char c;

void check1();
void check2();

int main()
{
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
       scanf("%c",&c),a[i]=c-48;
    for(i=1;i<=n;i++)
       scanf("%c",&c),b[i]=c-48;
    check1();
    check2();
    printf("NO\n");
    return 0;
}

void check1()
{
     int i;
     for(i=1;i<=n;i++)
        sel[i]=0;
     for(i=1;i<=n;i++)
     {
        min=16161616;
        for(j=1;j<=n;j++)
        {
           if (sel[j]==1) continue;
           if (b[j]<=a[i] || b[j]>=min) continue;
           min=b[j],mm=j;
        }
        if (min==16161616) return;
        sel[mm]=1;
     }
     printf("YES\n");
     exit(0);
     return;
}

void check2()
{
     int i;
     for(i=1;i<=n;i++)
        sel[i]=0;
     for(i=1;i<=n;i++)
     {
        max=0-16161616;
        for(j=1;j<=n;j++)
        {
           if (sel[j]==1) continue;
           if (b[j]>=a[i] || b[j]<=max) continue;
           max=b[j],mm=j;
        }
        if (max==0-16161616) return;
        sel[mm]=1;
     }
     printf("YES\n");
     exit(0);
     return;
}