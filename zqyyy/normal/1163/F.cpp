#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
const ll INF=1e18;
struct Edge{int to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
    e[++s_e]={y,head[x],w},head[x]=s_e;
}
int n,m,Q,tot,pre[N],L[N],R[N],num[N];
int U[N],V[N],W[N];
ll dis[2][N];
bool is[N];
struct Segment_Tree{
    ll t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
    void build(int p,int l,int r){
	t[p]=INF;if(l==r)return;
	int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r);
    }
    void modify(int p,int l,int r,int L,int R,ll x){
	if(L>R)return;if(L<=l && r<=R){t[p]=min(t[p],x);return;}
	int mid=(l+r)>>1;
	if(L<=mid)modify(ls,l,mid,L,R,x);
	if(R>mid)modify(rs,mid+1,r,L,R,x);
    }
    ll query(int p,int l,int r,int x){
	ll res=t[p];if(l==r)return res;
	int mid=(l+r)>>1;
	if(x<=mid)res=min(res,query(ls,l,mid,x));
	else res=min(res,query(rs,mid+1,r,x));
	return res;
    }
}T;
inline void dijkstra(int s,ll *dis,int fl=0){
    static bool vis[N];
    fill(dis+1,dis+n+1,INF),fill(vis+1,vis+n+1,0);
    priority_queue<pair<ll,int> >q;q.push({dis[s]=0,s});
    while(!q.empty()){
	int x=q.top().second;q.pop();
	if(vis[x])continue;vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
	    int y=e[i].to;ll w=dis[x]+e[i].w;
	    if(dis[y]>w){
		dis[y]=w,pre[y]=(i+1)>>1;
		if(fl==1 && !is[y])L[y]=L[x];
		if(fl==2 && !is[y])R[y]=R[x];
		q.push({-w,y});
	    }
	}
    }
}
int main(){
    n=read(),m=read(),Q=read();
    for(int i=1;i<=m;i++){
	int x=read(),y=read(),w=read();
	add_e(x,y,w),add_e(y,x,w);
	U[i]=x,V[i]=y,W[i]=w;
    }
    dijkstra(n,dis[0]),is[1]=1,L[1]=R[1]=0;
    {
	int x=1;
	for(tot=1;x^n;tot++){
	    int id=pre[x];
	    num[id]=tot,x=x^U[id]^V[id];
	    is[x]=1,L[x]=R[x]=tot;
	}
	tot--;
    }
    dijkstra(1,dis[0],1),dijkstra(n,dis[1],2),T.build(1,1,tot);
    for(int i=1;i<=m;i++)
	if(!num[i]){
	    T.modify(1,1,tot,L[U[i]]+1,R[V[i]],dis[0][U[i]]+W[i]+dis[1][V[i]]);
	    T.modify(1,1,tot,L[V[i]]+1,R[U[i]],dis[1][U[i]]+W[i]+dis[0][V[i]]);
	}
    while(Q--){
	int id=read(),w=read();
	ll ans=0;
	if(num[id]){
	    ans=dis[0][n]-W[id]+w;
	    if(w>W[id])ans=min(ans,T.query(1,1,tot,num[id]));
	}else{
	    ans=dis[0][n];
	    if(w<W[id])
		ans=min({ans,dis[0][U[id]]+w+dis[1][V[id]],dis[1][U[id]]+w+dis[0][V[id]]});
	}
	printf("%lld\n",ans);
    }
    return 0;
}