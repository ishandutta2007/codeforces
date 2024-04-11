#include<iostream>
#include<stdio.h>
using namespace std;
long long i,j,k,l,s,m,n;
long long p,q;
long long a[2000005];
    bool bb=true;

int main()
{
    scanf("%d%d",&n,&m);
    a[0]=2;
    p=2;
    q=2;
     if (n>m+1||m>2*n+2||(m==0&&n==0))
      {cout<<"-1";
      return 0;}
    if (n-m>=2)
     {cout<<"-1";
     return 0;}
     while (n>=0&&m>=0)
     {
     
     if (n==m&&q!=0)
      {for (i=1;i<=n;i++)
       printf("%d%d",0,1);
       return 0;
       }
       if (n*2==m&&q!=1)
        {for (i=1;i<=n;i++)
         printf("%d%d%d",1,1,0);
         return 0;}
        if (n==m+1&&q!=0)
         {printf("%d",0);
         for (i=1;i<=m;i++)
          printf("%d%d",1,0);
          return 0;
          }
         if (n+1==m&&(p!=1||q!=1))
          {printf("%d",1);
          for (i=1;i<=n;i++)
           printf("%d%d",0,1);
           return 0;
           }
           if (n>0&&m>0)
          printf("%d%d%d",1,1,0);
          else
          
		  	if (n<=0)
          {
		  for (i=1;i<=m;i++)
          printf("%d",1);
          return 0;
      		}
          else
          {
		  if (m<=0)
          printf("%d",0);
          return 0;
      		}
          m-=2;
          n--;
           }
}