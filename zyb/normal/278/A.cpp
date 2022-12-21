#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int s1,i,j,k,l,s,m,n;
    int a[105];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
     scanf("%d",&a[i]);
    scanf("%d%d",&j,&k);
    l=j;
    s=0;
    while (l!=k)
     {s+=a[l];
            l++;
     if (l>n)
      l=l%n;
    }
s1=0;
l=j;
    while (l!=k)
    {
   
    l--;
    if (l==0)
     l+=n;
      s1+=a[l];
    }
    printf("%d",min(s,s1));
}