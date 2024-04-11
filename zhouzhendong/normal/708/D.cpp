#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=105,M=105,INF=1e9;
namespace flows{
	const int N=105,M=105*(1+3)*2,INF=1e9;
	int n,S,T;
	int flow,cost;
	struct edge{
		int x,y,cap,cost,nxt;
		edge(){}
		edge(int _x,int _y,int _cap,int _cost,int _nxt){
			x=_x,y=_y,cap=_cap,cost=_cost,nxt=_nxt;
		}
	}e[M];
	int fst[N],ec;
	void init(int _n,int _S,int _T){
		clr(fst),ec=1;
		flow=cost=0;
		n=_n,S=_S,T=_T;
	}
	void add(int x,int y,int cap,int cost){
		e[++ec]=edge(x,y,cap,cost,fst[x]),fst[x]=ec;
		e[++ec]=edge(y,x,0,-cost,fst[y]),fst[y]=ec;
	}
	int dis[N],vis[N];
	bool spfa(){
		static int q[N*N*2];
		int head=0,tail=0;
		For(i,1,n)
			dis[i]=INF;
		clr(vis);
		q[++tail]=S,vis[S]=1,dis[S]=0;
		while (head<tail){
			int x=q[++head];
			vis[x]=0;
			for (int i=fst[x];i;i=e[i].nxt)
				if (e[i].cap){
					int y=e[i].y;
					if (dis[y]>dis[x]+e[i].cost){
						dis[y]=dis[x]+e[i].cost;
						if (!vis[y])
							q[++tail]=y,vis[y]=1;
					}
				}
		}
		clr(vis);
		return dis[T]<INF;
	}
	int dfs(int x,int lim){
		if (x==T||!lim)
			return lim;
		vis[x]=1;
		int rem=lim;
		for (int i=fst[x];i;i=e[i].nxt){
			int y=e[i].y;
			if (!vis[y]&&e[i].cap&&dis[x]+e[i].cost==dis[y]){
				int d=dfs(y,min(rem,e[i].cap));
				rem-=d;
				e[i].cap-=d;
				e[i^1].cap+=d;
				if (!rem)
					break;
			}
		}
		vis[x]=0;
		return lim-rem;
	}
	void Solve(){
		while (spfa()){
			int d=dfs(S,INF);
			flow+=d;
			cost+=d*dis[T];
		}
	}
}
int n,m;
int in[N];
int ans=0;
int main(){
	n=read(),m=read();
	int S=n+1,T=S+1;
	flows::init(T,S,T);
	For(i,1,m){
		int x=read(),y=read(),cost=read(),flow=read();
		in[x]-=flow;
		in[y]+=flow;
		if (flow<=cost){
			flows::add(y,x,flow,1);
			flows::add(x,y,cost-flow,1);
			flows::add(x,y,INF,2);
		}
		else {
			ans+=flow-cost;
			flows::add(y,x,flow-cost,0);
			flows::add(y,x,cost,1);
			flows::add(x,y,INF,2);
		}
	}
	flows::add(n,1,INF,0);
	For(i,1,n){
		if (in[i]>0)
			flows::add(S,i,in[i],0);
		else if (in[i]<0)
			flows::add(i,T,-in[i],0);
	}
	flows::Solve();
	ans+=flows::cost;
	cout<<ans<<endl;
	return 0;
}