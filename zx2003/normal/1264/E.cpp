#include<bits/stdc++.h>
using namespace std;
const int V=5005,E=50005,N=55;
struct graph{
	struct edge{int to,next,w,f;}e[E<<1];
	int h[V],xb,n;
	inline void addedge(int x,int y,int w,int f){
		e[++xb]=(edge){y,h[x],w,f};h[x]=xb;
		e[++xb]=(edge){x,h[y],-w,0};h[y]=xb;
	}
	inline pair<int,int>mcmf(int S,int T){
		static int d[V],q[V],mi[V],lv[V],le[V];static bool inq[V];
		int t,w,ans1=0,ans2=0,u,i;
		for(;;){
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
			if(d[T]==1<<30)return make_pair(ans1,ans2);
			ans1+=mi[T];
			for(u=T;u!=S;u=lv[u]){
				ans2+=mi[T]*e[le[u]].w;
				e[le[u]].f-=mi[T];
				e[le[u]^1].f+=mi[T];
			}
		}
	}
}g;
int n,m,i,j,u,v,ind[N],outd[N],f[N],id[N][N],b[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)f[i]=i*(i-1)/2+(n-1-i)*(n-2-i)/2;//,printf("%d\n",f[i]);
	for(i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		++outd[u];++ind[v];b[u][v]=1;
	}
	g.n=2+n;g.xb=1;
	for(i=1;i<n;++i)for(j=i+1;j<=n;++j)if(!b[i][j] && !b[j][i]){
		++g.n;
		g.addedge(1,g.n,0,1);
		g.addedge(g.n,i+2,0,1);
		id[i][j]=g.xb-1;
		g.addedge(g.n,j+2,0,1);
	}
	for(i=1;i<=n;++i)for(j=1;j<=n-1-ind[i]-outd[i];++j)
		g.addedge(i+2,2,f[ind[i]+j]-f[ind[i]+j-1],1);
	g.mcmf(1,2);
	for(i=1;i<n;++i)for(j=i+1;j<=n;++j)if(id[i][j]){if(!g.e[id[i][j]].f)b[j][i]=1;else b[i][j]=1;}
	for(i=1;i<=n;++i,puts(""))for(j=1;j<=n;++j)printf("%d",b[i][j]);
	return 0;
}