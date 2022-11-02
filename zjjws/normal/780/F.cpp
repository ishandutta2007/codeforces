#include <stdio.h>
#include <string.h>
#include <bitset>
#define LL long long
using namespace std;
const int N=5e2+3;
int n,m;
inline LL max(LL x,LL y){return x>y?x:y;}
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

struct gyq
{
    bitset<N>a[N];
};
gyq f[66];
gyq g[66];
inline gyq operator *(gyq &x,gyq &y)
{
    gyq z;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(x.a[i][j])z.a[i]|=y.a[j];
    return z;
}
bitset<N>s;
bitset<N>sl;
int main()
{
    int i,j,k;
    n=rin();m=rin();
    for(i=1;i<=m;i++)
    {
        int x,y,z;
        x=rin();y=rin();z=rin();
        if(z==0)f[0].a[x][y]=true;
        else g[0].a[x][y]=true;
    }
    for(i=1;i<=60;i++)f[i]=f[i-1]*g[i-1],g[i]=g[i-1]*f[i-1];
    for(j=1;j<=n;j++)if(f[60].a[1][j]){puts("-1");return 0;}
    s[1]=1;
    bool now=false;
    LL ans=0;
    for(i=59;i>=0;i--)
    {
        bool if_true=false;
        sl.reset();
        for(j=1;j<=n;j++)
        {
            if(!s[j])continue;
            for(k=1;k<=n;k++)
            {
                if(!now&&f[i].a[j][k])break;
                if(now&&g[i].a[j][k])break;
            }
            if(k<=n)
            {
                if_true=true;
                if(!now)sl|=f[i].a[j];
                else sl|=g[i].a[j];
            }
        }
        if(if_true)now=!now,ans+=(1LL<<i),s=sl;
    }
    if(ans>1e18)ans=-1;
    printf("%lld\n",ans);
    return 0;
}