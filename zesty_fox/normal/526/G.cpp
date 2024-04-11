#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010,INF=0x3f3f3f3f;

int n,q;
vector<pii> e[N];

struct Tree{
    int rt;
    ll dis[N],maxd[N];
    int dep[N],son[N],fa[N][21],tofa[N];
    void dfs1(int x,int fat){
        fa[x][0]=fat,dep[x]=dep[fat]+1;
        for(int i=1;i<=__lg(dep[x]);i++) fa[x][i]=fa[fa[x][i-1]][i-1];

        maxd[x]=dis[x];
        for(auto tmp:e[x]){
            int y=tmp.fi,w=tmp.se;
            if(y==fat) continue;
            dis[y]=dis[x]+w,tofa[y]=w;
            dfs1(y,x);
            maxd[x]=max(maxd[x],maxd[y]);
            if(maxd[y]>maxd[son[x]]) son[x]=y;
        }
    }
    
    int tp[N],bot[N],ls[N],lcnt;
    ll cont[N];
    void dfs2(int x,int nowtp){
        tp[x]=nowtp,bot[nowtp]=x;
        cont[x]=dis[x]-dis[fa[tp[x]][0]];
        if(son[x]) dfs2(son[x],nowtp);
        for(auto tmp:e[x]){
            int y=tmp.fi;
            if(y==fa[x][0]||y==son[x]) continue;
            dfs2(y,y);
        }
        bot[x]=bot[nowtp];
        if(bot[x]==x) ls[++lcnt]=x;
    }

    ll sum[N];
    int bl[N];
    void init(int _rt){
        rt=_rt;
        dfs1(rt,0),dfs2(rt,rt);
        sort(ls+1,ls+lcnt+1,[&](const int &x,const int &y){return cont[x]>cont[y];});
        for(int i=1;i<=lcnt;i++){
            int x=ls[i];
            sum[i]=sum[i-1]+cont[x];
            while(bot[x]==ls[i]) bl[x]=i,x=fa[x][0];
        }
    }

    ll query(int x,int k){
        if(2*k-1>=lcnt) return sum[lcnt];
        if(bl[x]<=2*k-1) return sum[2*k-1];

        ll ret1=sum[2*k-2];
        int x1=x;
        for(int i=__lg(dep[x]);i>=0;i--)
            if(bl[fa[x1][i]]>2*k-2) x1=fa[x1][i];
        x1=fa[x1][0];
        ret1+=maxd[x]-dis[x1];

        ll ret2=sum[2*k-1];
        x1=x;
        for(int i=__lg(dep[x]);i>=0;i--)
            if(bl[fa[x1][i]]>2*k-1) x1=fa[x1][i];
        x1=fa[x1][0];
        ret2+=maxd[x]-maxd[x1];
        return max(ret1,ret2);
    }
}t1,t2;

int dx,dy;
ll maxd;
void find_dia(int x,int fa,ll dis,int &to){
    if(dis>maxd) maxd=dis,to=x;
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        find_dia(y,x,dis+tmp.se,to);
    }
}

ll ans;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),q=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi(),w=rdi();
        e[x].pb(mp(y,w)),e[y].pb(mp(x,w));
    }
    maxd=-INF;find_dia(1,0,0,dx);
    maxd=-INF;find_dia(dx,0,0,dy);
    t1.init(dx),t2.init(dy);
    while(q--){
        int x=(rdi()+ans-1)%n+1,k=(rdi()+ans-1)%n+1;
        ans=max(t1.query(x,k),t2.query(x,k));
        printf("%lld\n",ans);
    }
    return 0;
}