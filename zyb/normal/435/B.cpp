#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int s1,i,j,k,l,s,m,n;
int a[5005];
char c;
c=getchar();
n=0;
while (c!=' ')
{
   n++;
        a[n]=int(c)-48;
             c=getchar();
}
scanf("%d",&k);
 m=1;
 while (k>0&&m<=n)
  {s=m;
  j=m+1;
  s1=a[m];
        for (i=j;i<=m+k&&i<=n;i++)
         if (a[i]>s1)
          {s1=a[i];
          s=i;
        }
    for (i=s;i>=m+1;i--)
     a[i]=a[i-1];
    a[m]=s1;
    k=k-(s-m);
    m++;
}
for (i=1;i<=n;i++)
 printf("%d",a[i]);
}