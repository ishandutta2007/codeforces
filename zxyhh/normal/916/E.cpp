#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define maxn 100005
#define lb(x) (x&-x)
using namespace std;
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll x){ if (x>=10) write(x/10),putchar(x%10+'0'); else putchar(x+'0'); }
inline void wrt(ll x,int p){if (x<0) putchar('-'),x=-x; write(x); if (p) putchar(p);}
inline int max(int A,int B){return A>B?A:B;}
int hd[maxn],to[maxn<<1],nx[maxn<<1],cnt;
inline void add(int u,int v){to[++cnt]=v,nx[cnt]=hd[u],hd[u]=cnt;}
int dfn[maxn],sz[maxn],dep[maxn],f[19][maxn],n,m,id,rt;
int val[maxn];
ll tr1[maxn],tr2[maxn];
inline void update(int x,int y)
{
    for(int i=x;i<=n;i+=lb(i)) tr1[i]+=y,tr2[i]+=1ll*x*y;
}
inline ll query(int x)
{
    ll ans=0;
    for(int i=x;i;i-=lb(i)) ans+=1ll*(x+1)*tr1[i]-tr2[i];
    return ans;
}
void dfs(int u)
{
    rep(i,1,18) f[i][u]=f[i-1][f[i-1][u]];
    dep[u]=dep[f[0][u]]+1,dfn[u]=++id,sz[u]=1;
    update(id,val[u]),update(id+1,-val[u]);
    cross(i,u)
        if (to[i]!=f[0][u]) 
            f[0][to[i]]=u,dfs(to[i]),sz[u]+=sz[to[i]];
}
inline int lca_(int u,int v)
{
    if (dep[u]<dep[v]) swap(u,v);
    drp(i,18,0)
        if (dep[f[i][u]]>=dep[v]) u=f[i][u];
    if (u==v) return u;
    drp(i,18,0)
        if (f[i][u]!=f[i][v]) u=f[i][u],v=f[i][v];
    return f[0][u];
}
inline int LCA(int u,int v)
{
    int lca1=lca_(v,rt),lca2=lca_(u,rt),lca3=lca_(u,v);
    int ans=dep[lca1]>dep[lca2]?lca1:lca2;
    ans=dep[ans]>dep[lca3]?ans:lca3;
    return ans;
}
inline int Gtson(int x)
{
    int ans=rt;
    drp(i,18,0)
        if (dep[f[i][ans]]>dep[x]) ans=f[i][ans];
    return ans;
}
inline void xg(int x,int v)
{
    if (x==rt) update(1,v);
    else if (lca_(x,rt)==x){
        int sn=Gtson(x);
        update(1,v);
        update(dfn[sn],-v);
        update(dfn[sn]+sz[sn],v);
    }
    else update(dfn[x],v),update(dfn[x]+sz[x],-v);
}
inline ll Que(int x)
{
    ll ans;
    if (x==rt) ans=query(n);
    else if (lca_(x,rt)==x){
        int sn=Gtson(x);
        ans=query(n);
        ans-=query(dfn[sn]+sz[sn]-1)-query(dfn[sn]-1);
    }
    else ans=query(dfn[x]+sz[x]-1)-query(dfn[x]-1);
    return ans;
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    n=rd(),m=rd();
    rep(i,1,n) val[i]=rd();
    rep(i,1,n-1){
        int x=rd(),y=rd();
        add(x,y),add(y,x);
    }
    dfs(1);
    rep(i,1,m) {
        int op=rd();
        if (op==1) rt=rd();
        else if (op==2) {
            int x=rd(),y=rd(),v=rd(),lca=LCA(x,y);
            xg(lca,v);
        }
        else wrt(Que(rd()),'\n');
    }
}