#include<iostream>
#include<stdio.h>
using namespace std;
long long i,j,k,l,s,m,n,x,y;
    long long a[100005],b[100005],c[100005],d[100005],e[100005],f[100005];
inline void up(long long o,long long p)
{
    while (o<=n)
    {b[o]+=p;
    o=o+(o&(-o));
    }
}
void insert(long long x,long long v){
    for (;x<=n;x+=x&-x) b[x]+=v;
}
long long sum(long long x){
    long long s=0;
    for (;x;x-=x&-x) s+=b[x];
    return s;
}
int main()
{
    
    scanf("%I64d%d%d",&n,&m,&k);
    for (i=1;i<=n;i++)
    scanf("%I64d",&a[i]);
    for (i=1;i<=m;i++)
    scanf("%I64d%d%d",&c[i],&d[i],&e[i]);
    for (i=1;i<=k;i++)
    {
        scanf("%I64d%d",&x,&y);
        f[x]++;
        f[y+1]--;
    }
    for (i=1;i<=m;i++)
    {
    s+=f[i];
    insert(c[i],e[i]*s);
    insert(d[i]+1,-e[i]*s);
    }
    s=0;
    for (i=1;i<=n;i++)
    {printf("%I64d ",a[i]+sum(i));
}
}