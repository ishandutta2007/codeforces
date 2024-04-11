#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;
const int N=505;
int n,a[N];
namespace FLOW{
	struct edge{
		int from,to,next,f,v;
	}e[N*10];
	int head[N*2],tot;
	void add(int x,int y,int f,int v){
		e[++tot]=(edge){x,y,head[x],f,v};
		head[x]=tot;
		e[++tot]=(edge){y,x,head[y],0,-v};
		head[y]=tot;
	}
	int dis[N*2],q[N*N],vis[N*2];
	int from[N*2],S,T,ans1,ans2;
	bool bfs(){
		For(i,1,T) dis[i]=-(1<<30),vis[i]=0;
		int h=0,t=1; q[1]=S; dis[S]=0;
		while (h!=t){
			int x=q[++h]; vis[x]=0;
			for (int i=head[x];i;i=e[i].next)
				if (dis[e[i].to]<dis[x]+e[i].v&&e[i].f){
					dis[e[i].to]=dis[x]+e[i].v;
					from[e[i].to]=i;
					if (!vis[e[i].to]){
						vis[e[i].to]=1;
						q[++t]=e[i].to;
					}
				}
		}
		return dis[T]!=-(1<<30); 
	}
	void del(){
		int flow=1<<30;
		for (int i=from[T];i;i=from[e[i].from])
			flow=min(flow,e[i].f);
		for (int i=from[T];i;i=from[e[i].from])
			e[i].f-=flow,e[i^1].f+=flow,ans2+=e[i].v*flow;
		ans1+=flow;
	}
	void work(){
		for (;bfs();del());
	}
};
struct Tree{
	vector<int> e[N];
	int rt,fa[N],Fa[N],lim[N];
	void init1(){
		For(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].PB(y); e[y].PB(x);
		}
	}
	void init2(){
		int Q; scanf("%d",&Q);
		while (Q--){
			int x,y;
			scanf("%d%d",&x,&y);
			lim[x]=y;
		}
	}
	void dfs(int x,int fa,int las){
		if (fa&&lim[x]){
			lim[las]-=lim[x];
			Fa[x]=las=x;
		}
		else Fa[x]=las;
		for (auto i:e[x])
			if (i!=fa) dfs(i,x,las);
	}
	void init3(){
		dfs(rt,0,rt);
	}
	bool check(){
		For(i,1,n) if (lim[i]<0) return 0;
		return 1;
	}
}T0,T1;
int main(){
	FLOW::tot=1;
	scanf("%d%d%d",&n,&T0.rt,&T1.rt);
	For(i,1,n) scanf("%d",&a[i]);
	T0.init1(); T1.init1();
	T0.init2(); T1.init2();
	if (T0.lim[T0.rt]!=T1.lim[T1.rt]) return puts("-1"),0;
	int sum=T0.lim[T0.rt];
	T0.init3(); T1.init3();
	if (!T0.check()||!T1.check()) return puts("-1"),0;
	FLOW::S=n*2+1; FLOW::T=FLOW::S+1;
	For(i,1,n){
		FLOW::add(FLOW::S,i,T0.lim[i],0);
		FLOW::add(i+n,FLOW::T,T1.lim[i],0);
		FLOW::add(T0.Fa[i],T1.Fa[i]+n,1,a[i]);
	}
	FLOW::work();
	printf("%d\n",FLOW::ans1!=sum?-1:FLOW::ans2); 
}