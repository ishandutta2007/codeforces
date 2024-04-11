#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int mm=0,i,j,k,l,s,m,n;
    char a[1005],b[1005];
    int c[30],d[30];
    cin.getline(a,1005,'\n');
    cin.getline(b,1005,'\n');
    l=strlen(a);
    k=strlen(b);
    for (i=1;i<=26;i++)
     c[i]=d[i]=0;
    for (i=0;i<l;i++)
     {m=int(a[i])-96;
     c[m]++;}
    for (i=0;i<k;i++)
     {m=int(b[i]-96);
     d[m]++;}
     s=0;
    for (i=1;i<=26;i++)
     {
            if (d[i]!=0)
             if (c[i]==0)
              {cout<<"-1";
              return 0;}
              else s+=min(c[i],d[i]);
            }
    cout<<s;
    }