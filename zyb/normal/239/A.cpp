#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int i,j,k,l,s=0,m,n,y;
    scanf("%d%d%d",&y,&k,&n);
    j=1;
    if (y>n)
     {printf("%d",-1);
     return 0;
    }
    while (j*k<y)
     j++;
    for (i=j*k-y;i<=n-y;i+=k)
     {if(i!=0)
     {
            if ((i+y)%k==0)
      printf("%d ",i);
      s++;
    }
}
if (s==0)
 printf("%d",-1);
}