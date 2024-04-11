#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=2e5+3;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}

int n,m;

struct gyq
{
    int to,nxt;
}a[N];
int h[N];

int nam;
inline void add(int x,int y){a[++nam].to=y;a[nam].nxt=h[x];h[x]=nam;return;}

int dis[N];
int d[N];
int tail;

int f[2][N];
inline void work()
{
    n=rin();m=rin();
    nam=0;
    for(int i=1;i<=n;i++)h[i]=0,dis[i]=f[0][i]=f[1][i]=0x3f3f3f3f;
    for(int i=1;i<=m;i++)
    {
        int x=rin(),y=rin();
        add(x,y);
    }
    tail=0;d[++tail]=1;dis[1]=f[0][1]=f[1][1]=0;
    for(int head=1;head<=tail;)
    {
        int now=d[head++];
        for(int i=h[now];i;i=a[i].nxt)
        {
            if(dis[now]+1<dis[a[i].to])
            {
                dis[a[i].to]=dis[now]+1;
                d[++tail]=a[i].to;
            }
        }
    }
    for(int i=tail;i>=2;i--)
    {
        int now=d[i];
        f[0][now]=dis[now];
        for(int j=h[now];j;j=a[j].nxt)
        {
            int to=a[j].to;
            if(dis[to]>dis[now])f[0][now]=min(f[0][now],f[0][to]);
        }
    }
    // for(int i=1;i<=n;i++)printf("%d ",f[0][i]);printf("\n");
    for(int i=2;i<=tail;i++)
    {
        int now=d[i];
        for(int j=h[now];j;j=a[j].nxt)
        {
            int to=a[j].to;
            if(dis[to]<=dis[now])f[1][now]=min(f[1][now],f[0][to]);
        }
    }
    for(int i=tail;i>1;i--)
    {
        int now=d[i];
        f[0][now]=dis[now];
        for(int j=h[now];j;j=a[j].nxt)
        {
            int to=a[j].to;
            if(dis[to]>dis[now])f[1][now]=min(f[1][now],f[1][to]);
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",min(f[0][i],f[1][i]));printf("\n");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}