#include<bits/stdc++.h>
using namespace std;
inline int min(const int&a,const int&b){return a<b?a:b;}
const int N=55,M=2600,Q=1e5+5;
struct graph{
	struct edge{int to,next,w,f;}e[M<<1];
	int h[N],xb,n;
	inline void addedge(int x,int y,int w,int f){
		e[++xb]=(edge){y,h[x],w,f};h[x]=xb;
		e[++xb]=(edge){x,h[y],-w,0};h[y]=xb;
	}
	inline int aug(int S,int T){
		static int d[N],q[N],mi[N],lv[N],le[N];static bool inq[N];
		int t,w,u,i;
		memset(inq+1,0,n);inq[S]=1;
		for(i=1;i<=n;++i)d[i]=1<<30;d[S]=0;
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
		if(d[T]==1<<30)return -1;
		for(u=T;u!=S;u=lv[u]){
			e[le[u]].f-=mi[T];
			e[le[u]^1].f+=mi[T];
		}
		return d[T];
	}
}g;
int n,m,u,v,w,i,q,qu[Q];
double ans[Q];
int main(){
	scanf("%d%d",&n,&m);g.n=n;g.xb=1;
	for(i=1;i<=m;++i){
		cin>>u>>v>>w;
		g.addedge(u,v,w,1);
	}
	cin>>q;for(i=1;i<=q;++i)cin>>qu[i],ans[i]=1ll<<60;
	int tot=0,f=0;
	for(;;){
		w=g.aug(1,n);if(w==-1)break;
		tot+=w;++f;for(i=1;i<=q;++i)ans[i]=min(ans[i],(qu[i]+tot)*1.0/f);
	}
	for(i=1;i<=q;++i)printf("%.8f\n",ans[i]);
	return 0;
}