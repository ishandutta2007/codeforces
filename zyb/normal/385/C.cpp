#include<iostream>
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
    int a[1000005];
    long long f[10000005];
    int b[10000005];
    bool c[10000005];
    long long ans=0;
    int maxn,l,r,j,k,i,s,m,n;
int main()
{
scanf("%d",&n);
memset(b,0,sizeof(b));
maxn=0;
memset(c,false,sizeof(c));
memset(f,0,sizeof(f));
for (i=1;i<=n;i++)
 {scanf("%d",&a[i]);
 b[a[i]]++;
if (a[i]>maxn)
 maxn=a[i];
}
f[1]=0;
for (i=2;i<=maxn;i++)
        if (!c[i])
            for (j=2;i*j<=maxn;j++)
                c[i*j]=1;
for (i=2;i<=maxn;i++)
 {if (!c[i])
  for (j=1;i*j<=maxn;j++)
        f[i]+=b[j*i];
  f[i]+=f[i-1];
}      
scanf("%d",&m);
for (i=1;i<=m;i++)
{scanf("%d%d",&l,&r);
if (l>maxn)
 printf("%d\n",0);
 else {
if (r>maxn)
 r=maxn;
 ans=f[r]-f[l-1];
  printf("%I64d\n",ans);
}
}
}