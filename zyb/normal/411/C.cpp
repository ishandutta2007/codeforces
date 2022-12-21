#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a[5],b[5],i,j,k,l,s,m,n,s1,l1;
    for (i=1;i<=4;i++)
    scanf("%d%d",&a[i],&b[i]);
    s=0;
    l=0;
    if (b[3]>a[1]&&a[4]>b[2])
     s++;
    if (b[4]>a[1]&&a[3]>b[2])
     s++;
     if (a[1]>b[3]&&b[2]>a[4])
      l++;
     if (a[1]>b[4]&&b[2]>a[3])
      l++;
    if (l==2)
     {cout<<"Team 1";
     return 0;
    }
    s1=l1=0;
    if (b[3]>a[2]&&a[4]>b[1])
     s1++;
    if (b[4]>a[2]&&a[3]>b[1])
     s1++;
     if (a[2]>b[3]&&b[1]>a[4])
      l1++;
     if (a[2]>b[4]&&b[1]>a[3])
      l1++;
    if (l1==2)
     {cout<<"Team 1";
     return 0;
    }
    if (s>0&&s1>0)
     {cout<<"Team 2";
     return 0;
    }
    cout<<"Draw";
}