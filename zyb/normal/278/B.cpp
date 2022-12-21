#include<iostream>
#include<stdio.h>
#include<cstring>
#include<map>
using namespace std;
map<string,int>mm;
map<char,int>m1;
int main()
{char c[3],b[35][35],z,y;
int i,j,k,l,s,m,n;
scanf("%d",&n);
for (i=1;i<=n;i++)
scanf("%s",&b[i]);
s=0;
for (i=1;i<=n;i++)
 for (j=0;j<strlen(b[i]);j++)
  {
  m1[b[i][j]]=1;
}
int s1=0;
for (i=1;i<=n;i++)
 for (j=0;j<strlen(b[i])-1;j++)
  {c[0]=b[i][j];
  c[1]=b[i][j+1];
  mm[c]=1;
  
}
for (i=1;i<=26;i++)
 {z=char(i+96);
 if (m1[z]!=1)
   {cout<<z;
   return 0;
}
}
for (i=1;i<=26;i++)
 for (k=1;k<=26;k++)
 {c[0]=char(i+96);
 c[1]=char(k+96);
 
if (mm[c]!=1)
 {cout<<c[0]<<c[1];
return 0;
}
}
}