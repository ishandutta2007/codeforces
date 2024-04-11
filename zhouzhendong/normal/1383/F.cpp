#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
const int N=10005,M=N*2,INF=1e8;
struct Edge{
	int x,y,cap,nxt;
}e[M];
int cnt=1;
int cur[N],dis[N],fst[N];
int q[N],head,tail;
int las[N],eid[N];
struct Graph{
	int n,s,t,flow;
	int cap[M];
	void init(int _n,int _s,int _t){
		n=_n,s=_s,t=_t;
		cnt=1,flow=0;
	}
	void AddEdge(int x,int y,int _cap){
		e[++cnt]={x,y,0,fst[x]},cap[cnt]=_cap,fst[x]=cnt;
		e[++cnt]={y,x,0,fst[y]},cap[cnt]=0,fst[y]=cnt;
	}
	int bfs(){
		For(i,1,n)
			dis[i]=INF;
		dis[t]=0;
		head=1,tail=0;
		q[++tail]=t;
		while (head<=tail){
			int x=q[head++];
			for (int i=fst[x];i;i=e[i].nxt)
				if (cap[i^1]&&dis[e[i].y]==INF){
					dis[e[i].y]=dis[x]+1;
					q[++tail]=e[i].y;
				}
		}
		return dis[s]!=INF;
	}
	int bfs2(){
		For(i,1,n)
			dis[i]=INF;
		dis[t]=0;
		head=1,tail=0;
		q[++tail]=t;
		while (head<=tail){
			int x=q[head++];
			for (int i=fst[x];i;i=e[i].nxt)
				if (cap[i^1]&&dis[e[i].y]==INF){
					dis[e[i].y]=dis[x]+1;
					las[e[i].y]=x;
					eid[e[i].y]=i^1;
					q[++tail]=e[i].y;
					if (e[i].y==s)
						return 1;
				}
		}
		return dis[s]!=INF;
	}
	int dfs(int x,int lim){
		if (!lim||x==t)
			return lim;
		int rem=lim;
		for (int &i=cur[x];i;i=e[i].nxt)
			if (cap[i]&&dis[x]==dis[e[i].y]+1){
				int d=dfs(e[i].y,min(cap[i],rem));
				rem-=d;
				cap[i]-=d,cap[i^1]+=d;
				if (!rem)
					break;
			}
		return lim-rem;
	}
	int Dinic(){
		while (bfs()){
			For(i,1,n)
				cur[i]=fst[i];
			flow+=dfs(s,INF);
		}
		return flow;
	}
	int Anti_Hack(){
		while (bfs2()){
			int mx=1e5;
			for (int i=s;i!=t;i=las[i])
				ckmin(mx,cap[eid[i]]);
			for (int i=s;i!=t;i=las[i])
				cap[eid[i]]-=mx,cap[eid[i]^1]+=mx;
			flow+=mx;
		}
		return flow;
	}
}g;
const int K=10;
int n,m,k,Q;
int lg[1<<K],cost[1<<K];
vi id;
int bakg[K][M];
void dfs(int t,int s){
	if (t==k){
		//can't choose set s
		cost[s]=g.flow;
		return;
	}
	dfs(t+1,s);
	For(i,2,cnt)
		bakg[t][i]=g.cap[i];
	int fl=g.flow;
	g.cap[(id[t]+1)*2]=25;
	g.Anti_Hack();
	dfs(t+1,s|1<<t);
	For(i,2,cnt)
		g.cap[i]=bakg[t][i];
	g.flow=fl;
}
int sum[1<<K];
int main(){
	n=read(),m=read(),k=read(),Q=read();
	g.init(n,1,n);
	For(i,0,m-1){
		int x=read(),y=read(),cap=read();
		g.AddEdge(x,y,cap);
	}
	id.resize(k);
	iota(id.begin(),id.end(),0);
	srand(time(0));
	random_shuffle(id.begin(),id.end());
	g.Dinic();
	dfs(0,0);
	For(i,2,(1<<k)-1)
		lg[i]=lg[i>>1]+1;
	while (Q--){
		vi w(k);
		For(i,0,k-1)
			w[i]=read();
		int ans=INF;
		For(i,1,(1<<k)-1)
			sum[i]=sum[i-(1<<lg[i])]+w[id[lg[i]]];
		For(i,0,(1<<k)-1)
			ckmin(ans,sum[i]+cost[((1<<k)-1)^i]);
		printf("%d\n",ans);
	}
	return 0;
}