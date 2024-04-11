#include<bits/stdc++.h>
using namespace std;
const int N=2e5+99,M=5e5+99;
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
};
int n,m,i,r,b,x[N],y[N],xxb,yxb,ctx[N],cty[N],limx[N],limy[N];
char rr,bb;
unordered_map<int,int>mpx,mpy;
struct Graph{
graph g;
int n,S,T,fl[N],xb,id[N],ide[M];
struct edge{int fr,to,l,r;}e[M];
inline void add(int a,int b,int c,int d){
	if(c>d){cout<<-1<<endl;exit(0);}
	e[++xb]=(edge){a,b,c,d};fl[a]+=c;fl[b]-=c;
}
inline int work(){
	int i,ass=0;
	g.n=n+2;g.xb=1;
	for(i=1;i<=n;++i){
		if(fl[i]>0)g.addedge(i,g.n,fl[i]),id[i]=g.xb-1;
		if(fl[i]<0)g.addedge(g.n-1,i,-fl[i]),id[i]=g.xb-1;
	}
	for(i=1;i<=xb;++i)if(e[i].l<e[i].r)g.addedge(e[i].fr,e[i].to,e[i].r-e[i].l),ide[i]=g.xb-1;
	g.dinic(g.n-1,g.n);
	for(i=1;i<=n;++i)if(id[i] && g.e[id[i]].f){cout<<-1<<endl;exit(0);}
	g.dinic(n,n-1);
	for(int i=1;i<=::n;++i)ass+=!g.e[ide[i]].f;
	return ass;
}
inline void out(){for(int i=1;i<=::n;++i)cout<<(g.e[ide[i]].f?rr:bb);}
}g;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>r>>b;rr='r';bb='b';if(r>b)swap(r,b),swap(rr,bb);
	for(i=1;i<=n;++i){
		cin>>x[i]>>y[i];
		if(!mpx[x[i]])mpx[x[i]]=++xxb;
		if(!mpy[y[i]])mpy[y[i]]=++yxb;
		++ctx[mpx[x[i]]];
		++cty[mpy[y[i]]];
	}
	g.n=xxb+yxb+2;g.S=g.n-1;g.T=g.n;
	for(i=1;i<=n;++i)g.add(mpx[x[i]],mpy[y[i]]+xxb,0,1);
	for(i=1;i<=xxb;++i)limx[i]=ctx[i];
	for(i=1;i<=yxb;++i)limy[i]=cty[i];
	for(;m--;){
		int t,l,d;
		cin>>t>>l>>d;
		if(t==1 && mpx.count(l))l=mpx[l],limx[l]=min(limx[l],d);
		if(t==2 && mpy.count(l))l=mpy[l],limy[l]=min(limy[l],d);
	}
	for(i=1;i<=xxb;++i)g.add(g.n-1,i,ctx[i]-limx[i]+1>>1,ctx[i]+limx[i]>>1);
	for(i=1;i<=yxb;++i)g.add(i+xxb,g.n,cty[i]-limy[i]+1>>1,cty[i]+limy[i]>>1);
	g.add(g.n,g.n-1,0,n);
	long long ans=g.work();
	ans=1ll*ans*b+1ll*(n-ans)*r;
	cout<<ans<<'\n';
	g.out();
	cout<<endl;
	return 0;
}