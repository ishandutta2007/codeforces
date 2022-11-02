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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (y<x)
		x=y;
}
/*
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
*/
const int N=3005;
int n;
vi e[N];
int dis[N][N],sz[N][N],fa[N][N];
vector <pii> p[N];
void dfs(int x,int pre,int d,int rt){
	dis[rt][x]=d;
	sz[rt][x]=1;
	fa[rt][x]=pre;
	for (auto y : e[x])
		if (y!=pre)
			dfs(y,x,d+1,rt),sz[rt][x]+=sz[rt][y];
}
LL dp[N][N];
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n)
		dfs(i,0,0,i);
	For(i,1,n)
		For(j,1,n)
			p[dis[i][j]].pb(mp(i,j));
	LL res=0;
	For(i,1,n-1)
		for (auto pr : p[i]){
			int x=pr.fi,y=pr.se;
			dp[x][y]=max(dp[fa[y][x]][y],dp[x][fa[x][y]])+sz[y][x]*sz[x][y];
			ckmax(res,dp[x][y]);
		}
	cout<<res<<endl;
	return 0;
}