#include<bits/stdc++.h>
using namespace std;
const int N=2e5+99,M=61e4;
inline int min(const int&a,const int&b){return a<b?a:b;}
struct graph{
	struct edge{int to,next,f;}e[M<<1];
	int h[N],cur[N],xb;
	inline void addedge(int x,int y,int z){
		e[++xb]=(edge){y,h[x],z};h[x]=xb;
		e[++xb]=(edge){x,h[y],0};h[y]=xb;
	}
	int S,T,d[N],n;
	inline bool bfs(){
		static int q[N];int t=0,w=1;q[1]=S;
		memset(d+1,0,n<<2);d[S]=1;
		for(;t<w;){
			int u=q[++t];
			for(int i=h[u];i;i=e[i].next)if(e[i].f && !d[e[i].to])
				d[e[i].to]=d[u]+1,q[++w]=e[i].to;
		}
		return d[T];
	}
	int dfs(int x,int f){
		if(x==T)return f;
		int ans=0,&i=cur[x],t;
		for(;i;i=e[i].next)if(e[i].f && d[e[i].to]==d[x]+1){
			if(t=dfs(e[i].to,min(f,e[i].f))){
				ans+=t,e[i].f-=t;e[i^1].f+=t;f-=t;
				if(!f)break;
			}
		}
		return ans;
	}
	inline int dinic(int s,int t){
		int ans=0;S=s;T=t;
		for(;bfs();ans+=dfs(s,1<<30))memcpy(cur+1,h+1,n<<2);
		return ans;
	}
}g;
int n,i,j,L,u1[N],v1[N],a[N],mi[9]={0,9,99,999,9999,99999,999999},s,fa[N];
char c[19];
inline int I(){scanf("%s",c);return strlen(c);}
vector<int>v[29];
inline int getl(int x){return x?getl(x/10)+1:0;}
void dfs(int x){
	int l=getl(x);
	vector<int>t=v[l];v[l].clear();
	for(int y:t)fa[y]=x,dfs(y);
}
int main(){
	scanf("%d",&n);
	for(L=1;mi[L]<n;++L);
	g.n=n-1+L+2;g.xb=1;
	for(i=1;i<=n;++i)s^=i;
	for(i=1;i<=L;++i)g.addedge(g.n-2-L+i,g.n,min(mi[i],n)-mi[i-1]);
	for(i=1;i<n;++i){
		u1[i]=I(),v1[i]=I();
		g.addedge(g.n-1,i,1);g.addedge(i,g.n-2-L+u1[i],1);g.addedge(i,g.n-2-L+v1[i],1);
	}
	if(g.dinic(g.n-1,g.n)<n-1){puts("-1");return 0;}
	for(i=1;i<n;++i){
		for(j=g.h[i];g.e[j].f;j=g.e[j].next);
		int x=g.e[j].to-(g.n-2-L);
		s^=a[i]=++mi[x-1];
		v[u1[i]^v1[i]^x].push_back(a[i]);
	}
	dfs(s);
	for(i=1,j=0;i<=n;++i)j+=!fa[i];
	if(j>1){puts("-1");return 0;}
	for(i=1;i<=n;++i)if(fa[i])printf("%d %d\n",i,fa[i]);
	return 0;
}