#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int V=110,E=450;
struct graph{
	struct edge{int to,next;ll w;int f;}e[E<<1];
	int h[V],xb,n;
	inline void addedge(int x,int y,ll w,int f){
		e[++xb]=(edge){y,h[x],w,f};h[x]=xb;
		e[++xb]=(edge){x,h[y],-w,0};h[y]=xb;
	}
	inline pair<int,ll>mcmf(int S,int T){
		static int q[V],mi[V],lv[V],le[V];static bool inq[V];static ll d[V];
		int t,w,ans1=0,u,i;ll ans2=0;
		for(;;){
			memset(inq+1,0,n);inq[S]=1;
			for(i=1;i<=n;++i)d[i]=1ll<<60;d[S]=0;
			t=0;w=1;q[1]=S;mi[S]=1<<30;
			for(;t!=w;){
				inq[u=q[t=t==n?1:t+1]]=0;
				for(int i=h[u];i;i=e[i].next)if(e[i].f && d[e[i].to]>d[u]+e[i].w){
					d[e[i].to]=d[u]+e[i].w;
					mi[e[i].to]=min(mi[u],e[i].f);
					lv[e[i].to]=u;le[e[i].to]=i;
					if(!inq[e[i].to])inq[q[w=w==n?1:w+1]=e[i].to]=1;
				}
			}
			if(d[T]==1ll<<60)return make_pair(ans1,ans2);
			ans1+=mi[T];
			for(u=T;u!=S;u=lv[u]){
				ans2+=mi[T]*e[le[u]].w;
				e[le[u]].f-=mi[T];
				e[le[u]^1].f+=mi[T];
			}
		}
	}
}g;
int n,m,i,u,v,c,f,flow[V];
ll ans;
int main(){
	scanf("%d%d",&n,&m);
	g.xb=1;g.n=n+2;
	for(i=1;i<=m;++i){
		scanf("%d%d%d%d",&u,&v,&c,&f);
		flow[u]+=f;flow[v]-=f;
		if(f>c)ans+=f-c,g.addedge(u,v,2,1<<30),g.addedge(v,u,0,f-c),g.addedge(v,u,1,c);
			else g.addedge(u,v,1,c-f),g.addedge(u,v,2,1<<30),g.addedge(v,u,1,f);
	}
	g.addedge(n,1,0,1<<30);
	for(i=1;i<=n;++i){
		if(flow[i]>0)g.addedge(i,g.n,0,flow[i]);
		if(flow[i]<0)g.addedge(g.n-1,i,0,-flow[i]);
	}
	ans+=g.mcmf(g.n-1,g.n).second;
	printf("%lld\n",ans);
	return 0;
}