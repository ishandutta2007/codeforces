#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
    char a[105];
   int i,j,k,l,s,m,n;
    scanf("%s",&a);
    l=strlen(a);
    bool b=false,b1=false,b2=false;
    if (l<5)
     {cout<<"Too weak"<<endl;
     return 0;}
    for (i=0;i<l;i++)
     {j=int(a[i]);
     if (j>=65&&j<=90)
      b=true;
    if (j>=97&&j<=122)
     b1=true;
    if (j>=48&&j<=57)
     b2=true;
    }
if (b==true&&b1==true&&b2==true)
 cout<<"Correct";
 else cout<<"Too weak";
}