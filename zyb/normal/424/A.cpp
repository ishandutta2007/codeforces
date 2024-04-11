#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{int i,j,k,l,s,m,n;
scanf("%d",&l);
    char c[10005];
cin>>c;

s=0;
m=0;
for (i=0;i<l;i++)
 if (c[i]=='x')
  s++;
  else m++;
n=l/2;
if (s>n)
 {s=s-n;
 printf("%d\n",s);
 for (i=0;i<l;i++)
  if (s>0)
 {  if (c[i]=='x')
    {printf("X");
    s--;
}
else cout<<c[i];
}
else cout<<c[i];
}
else if (m>n)
 {m=m-n;
 printf("%d\n",m);
 for (i=0;i<l;i++)
  if (m>0)
 {  if (c[i]=='X')
    {printf("x");
    m--;
}
else cout<<c[i];
}
else cout<<c[i];
}
else {printf("%d\n",0);
    for (i=0;i<l;i++)
      cout<<c[i];
    }
    }