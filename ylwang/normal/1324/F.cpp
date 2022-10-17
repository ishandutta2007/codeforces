#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define Set(a) memset(a,0,sizeof(a))
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
typedef long long ll;
typedef unsigned long long ull;
template<typename T> inline T rd(T& x)
{
    T f=1;x=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(T)(c-'0');
    x*=f;
    return x;
}
ll rd(){ll x;rd(x);return x;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int inf=1<<30;

const int N=200005;
int col[N],dp[N],dp2[N];
int head[N],to[N<<1],nxt[N<<1],tot=0;void add(int u,int v){to[++tot]=v;nxt[tot]=head[u];head[u]=tot;}
void dfs1(int u,int f)
{
    dp[u]=col[u];
    for(ri i=head[u];i;i=nxt[i]) if(to[i]!=f) {dfs1(to[i],u);dp[u]+=max(0,dp[to[i]]);}
}
void dfs2(int u,int f)
{
    if(u!=1) dp2[u]=max(dp2[f]-max(0,dp[u]),0)+dp[u];
    for(ri i=head[u];i;i=nxt[i]) if(to[i]!=f) dfs2(to[i],u);
}
int main()
{
    int n=rd();
    F(i,1,n) col[i]=2*rd()-1;
    F(i,1,n-1) {int u,v;rd(u);rd(v);add(u,v);add(v,u);}
    dfs1(1,0);dp2[1]=dp[1];dfs2(1,0);
    F(i,1,n) printf("%d ",dp2[i]);
    return 0;
}