#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    char c[5],d;
    int r,i,j,k,l,s,m,n;
    scanf("%d",&n);
     s=-2000000000;
     r=2000000000;
     for (i=1;i<=n;i++)
       {cin>>c;
       scanf("%d",&m);
       cin>>d;
       if (d=='Y')
       {
       l=strlen(c);
       if (l==1)
        {if (c[0]=='>')
         s=max(s,m+1);
         else r=min(r,m-1);
        }
        else {if (c[0]=='>')
               s=max(s,m);
         else r=min(r,m);
        }
    if (s>r)
     {cout<<"Impossible";
     return 0;
    }
}
else {
       l=strlen(c);
       if (l==1)
        {if (c[0]=='>')
         r=min(r,m);
         else s=max(s,m);
        }
        else {if (c[0]=='>')
               r=min(r,m-1);
         else s=max(s,m+1);
        }
    if (s>r)
     {cout<<"Impossible";
     return 0;
    }
}
    }
printf("%d",s);
}