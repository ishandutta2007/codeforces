#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005,M=N*2;
struct graph{
	struct edge{int to,next;ll f;}e[M*3];
	int h[N],ecnt,n,d[N],S,T,cur[N];
	inline void addedge(int x,int y,ll f){
		e[++ecnt]=(edge){y,h[x],f};h[x]=ecnt;
		e[++ecnt]=(edge){x,h[y],0};h[y]=ecnt;
	}
	bool bfs(){
		static int q[N];int t=0,w=1,i,u;
		q[1]=S;memset(d+1,0,n<<2);d[S]=1;
		for(;t<w;)for(i=h[u=q[++t]];i;i=e[i].next)if(e[i].f && !d[e[i].to])d[q[++w]=e[i].to]=d[u]+1;
		return d[T];
	}
	ll dfs(int x,ll f){
		if(x==T)return f;
		int&i=cur[x];ll t,ans=0;
		for(;i;i=e[i].next)if(e[i].f && d[e[i].to]==d[x]+1 && (t=dfs(e[i].to,min(f,e[i].f))))
			{e[i].f-=t;e[i^1].f+=t;ans+=t;f-=t;if(!f)break;}
		return ans;
	}
	ll dinic(){ll ans=0;for(;bfs();)memcpy(cur+1,h+1,n<<2),ans+=dfs(S,1ll<<60);return ans;}
}g;
int n,m,u[M],v[M],a[M],c[M],i;ll b[M],d[M];
int main(){
	scanf("%d%d",&n,&m);for(i=1;i<=m;++i)scanf("%d%d%d%lld%d%lld",u+i,v+i,a+i,b+i,c+i,d+i),b[i]<<=27,d[i]<<=27;
	auto calc=[&](int x){
		static ll lo[M],hi[M],ind[N];ll tot=0;
		g.n=n+2;g.ecnt=1;memset(g.h+1,0,g.n<<2);g.S=g.n-1;g.T=g.n;memset(ind+1,0,n<<3);
		for(i=1;i<=m;++i)lo[i]=1ll*x*a[i]+b[i],hi[i]=1ll*x*c[i]+d[i],ind[v[i]]+=lo[i],ind[u[i]]-=lo[i],
			g.addedge(u[i],v[i],hi[i]-lo[i]);
		for(i=1;i<=n;++i)if(ind[i]>0)tot+=ind[i],g.addedge(g.S,i,ind[i]);else g.addedge(i,g.T,-ind[i]);
		return g.dinic()-tot;
	};
	auto find1=[&](){
		int L=0,R=1<<27,M;
		for(;L<R;){M=L+R>>1;if(calc(M)>calc(M+1))R=M;else L=M+1;}
		return L;
	};
	auto find2=[&](int bd){
		int L=0,R=bd,M;
		for(;L<R;){M=L+R>>1;if(calc(M)==0)R=M;else L=M+1;}
		return L;
	};
	int z=find1();
	printf("%.8f\n",calc(z)==0?(z-find2(z)+1)*1.0/(1<<27):0);
	return 0;
}