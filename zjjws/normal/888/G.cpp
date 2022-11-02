#include <bits/stdc++.h>
#define LL unsigned long long
#define uint unsigned int
using namespace std;
const int N=2e5+3;
const int DEP=31;
struct milk
{
    int to[2];
    int x;
}t[(N<<5)+3];
int n;
int nam;
LL ans=0;
inline void make_tree(int now,int dep,uint x)
{
    if(dep<0)
    {
        t[now].x=x;
        return;
    }
    bool y=(x&(1LL<<dep));
    if(t[now].to[y]==0)t[now].to[y]=++nam;
    make_tree(t[now].to[y],dep-1,x);
    return;
}
inline LL work(int x,int y,int dep,LL s)
{
    if(dep<0)return s;
    LL ans=0x3f3f3f3f3f3f3f3f3f;
    if(t[x].to[0]>0&&t[y].to[0]>0)ans=min(ans,work(t[x].to[0],t[y].to[0],dep-1,s));
    if(t[x].to[1]>0&&t[y].to[1]>0)ans=min(ans,work(t[x].to[1],t[y].to[1],dep-1,s));
    if(ans==0x3f3f3f3f3f3f3f3f)
    {
        if(t[x].to[0]>0&&t[y].to[1]>0)ans=min(ans,work(t[x].to[0],t[y].to[1],dep-1,(s|(1LL<<dep))));
        if(t[x].to[1]>0&&t[y].to[0]>0)ans=min(ans,work(t[x].to[1],t[y].to[0],dep-1,(s|(1LL<<dep))));
    }
    return ans;
}
inline void dfs(int x,int dep)
{
    if(t[x].to[0]>0&&t[x].to[1]>0)ans+=work(t[x].to[0],t[x].to[1],dep-1,(1LL<<dep));
    if(t[x].to[0]>0)dfs(t[x].to[0],dep-1);
    if(t[x].to[1]>0)dfs(t[x].to[1],dep-1);
    return;
}
int rin()
{
    int s=0;
    char c=getchar();
    bool bj=0;
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')c=getchar(),bj=true;
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
int main()
{
    int i,j;
    n=rin();
    for(i=1;i<=n;i++)
    {
        uint x=rin();
        make_tree(0,DEP,x);
    }
    dfs(0,DEP);
    printf("%lld\n",ans);
    return 0;
}