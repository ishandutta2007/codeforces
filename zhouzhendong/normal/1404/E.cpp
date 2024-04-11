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
typedef unsigned long long ull;
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
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
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
//int md(LL x){
//	return (x%mod+mod)%mod;
//}
const int maxn=205;
int n,m;
char s[maxn][maxn];
namespace flow{
	const int N=maxn*maxn*2,M=N*4*2,INF=1e9;
	struct Edge{
		int x,y,cap,nxt;
	}e[M];
	int n,S,T,cnt;
	int fst[N],cur[N],dis[N];
	void init(int _n){
		n=_n,cnt=1;
		clr(fst);
	}
	void addedge(int x,int y,int cap){
		e[++cnt]={x,y,cap,fst[x]},fst[x]=cnt;
		e[++cnt]={y,x,0,fst[y]},fst[y]=cnt;
	}
	void init(){
		For(i,1,n)
			cur[i]=fst[i];
	}
	int bfs(){
		static int vis[N];
		clr(vis);
		dis[S]=0,vis[S]=1;
		queue <int> q;
		q.push(S);
		while (!q.empty()){
			int x=q.front();
			q.pop();
			for (int i=fst[x];i;i=e[i].nxt){
				int y=e[i].y;
				if (e[i].cap&&!vis[y]){
					vis[y]=1;
					dis[y]=dis[x]+1;
					q.push(y);
				}
			}
		}
		return vis[T];
	}
	int dfs(int x,int lim){
		if (x==T||!lim)
			return lim;
		int now=0;
		for (int &i=cur[x];i;i=e[i].nxt){
			int y=e[i].y;
			if (dis[y]==dis[x]+1&&e[i].cap){
				int d=dfs(y,min(e[i].cap,lim-now));
				now+=d;
				e[i].cap-=d,e[i^1].cap+=d;
				if (now==lim)
					break;
			}
		}
		return now;
	}
	int calc(int _S,int _T){
		S=_S,T=_T;
		int res=0;
		while (bfs()){
			init();
			res+=dfs(S,INF);
		}
		return res;
	}
}
int main(){
	n=read(),m=read();
	For(i,1,n)
		scanf("%s",s[i]+1);
	int S=n*m*2+1,T=S+1;
	flow::init(T);
	auto gid=[&](int i,int j,int k){
		return (i-1)*m+j+k*n*m;
	};
	auto check=[&](int i,int j){
		return 1<=i&&i<=n&&1<=j&&j<=m&&s[i][j]!='.';
	};
	int cnte=0,cnt=0;
	For(i,1,n)
		For(j,1,m){
			if (check(i,j))
				cnt++;
			else
				continue;
			if (check(i,j)&&check(i,j+1))
				flow::addedge(S,gid(i,j,0),1),cnte++;
			if (check(i,j)&&check(i+1,j))
				flow::addedge(gid(i,j,1),T,1),cnte++;
			if (i>=1&&j>=1)
				flow::addedge(gid(i,j,0),gid(i,j,1),1);
			if (i>=2&&j>=1)
				flow::addedge(gid(i,j,0),gid(i-1,j,1),1);
			if (i>=1&&j>=2)
				flow::addedge(gid(i,j-1,0),gid(i,j,1),1);
			if (i>=2&&j>=2)
				flow::addedge(gid(i,j-1,0),gid(i-1,j,1),1);
		}
	int res=flow::calc(S,T);
//	outval(cnt);outval(cnte);outval(res);
	cout<<cnt-(cnte-res)<<endl;
	return 0;
}