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
int dfn[N],siz[N],fa[N],dep[N];
int head[N],to[N<<1],nxt[N<<1],tot=0;void add(int u,int v){to[++tot]=v;nxt[tot]=head[u];head[u]=tot;}
int tme=0;
void dfs(int u,int f)
{
    dep[u]=dep[f]+1;fa[u]=f;siz[u]=1;dfn[u]=++tme;
    for(ri i=head[u];i;i=nxt[i]) if(to[i]!=f) {dfs(to[i],u);siz[u]+=siz[to[i]];}
}
bool in(int x,int y)//is y in the subtree of x
{return dfn[x]<=dfn[y]&&dfn[y]<dfn[x]+siz[x];}
bool cmp(int x,int y){return dep[x]<dep[y];}
int tmp[N];
int main()
{
    int n=rd();int m=rd();
    F(i,1,n-1){int u=rd();int v=rd();add(u,v);add(v,u);}
    dfs(1,1);
    while(m--)
    {
        int k=rd();
        F(i,1,k) tmp[i]=fa[rd()];
        sort(tmp+1,tmp+k+1,cmp);
        bool flg=true;
        F(i,1,k-1) if(!in(tmp[i],tmp[i+1])) flg=false;
        puts(flg?"YES":"NO");
    }
    return 0;
}