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
const int N=5005*2,P=1000,V=5000;
int n,m;
int a[N];
int p[P],pc=0;
vi val[N];
void prework(){
	static int vis[N];
	int n=V;
	For(i,2,n){
		if (!vis[i]){
			p[pc++]=i;
			for (int j=i*2;j<=n;j+=i)
				vis[j]=1;
		}
	}
}
vi gao(int x){
	vi res;
	for (int i=0;i<pc&&p[i]<=x;i++)
		while (x%p[i]==0)
			res.pb(i),x/=p[i];
	return res;
}
vi LCA(vi x,vi y){
	vi res(pc,0);
	Fod(i,pc-1,0)
		if (x[i]==y[i])
			res[i]=x[i];
		else {
			res[i]=min(x[i],y[i]);
			break;
		}
	return res;
}
vi e[N];
LL sz[N],dep[N];
LL getsum(vi x){
	LL res=0;
	for (auto i : x)
		res+=i;
	return res;
}
LL mxs[N],tsz;
int rt=0;
void dfs(int x,int pre){
	mxs[x]=0;
	for (auto y : e[x])
		if (y!=pre){
			dfs(y,x);
			sz[x]+=sz[y];
			ckmax(mxs[x],sz[y]);
		}
	ckmax(mxs[x],tsz-sz[x]);
	if (!rt||mxs[rt]>mxs[x])
		rt=x;
}
LL ans=0;
LL absl(LL x){
	return x<0?-x:x;
}
void solve(int x,int pre,LL d){
	ans+=d*a[x];
	for (auto y : e[x])
		if (y!=pre)
			solve(y,x,d+absl(dep[x]-dep[y]));
}
int main(){
	n=read(),tsz=n;
	while (n--)
		a[max(read(),1LL)]++;
	prework();
	n=V;
	val[0].resize(pc);
	For(i,1,n){
		val[i]=val[i-1];
		vi v=gao(i);
		for (auto j : v)
			val[i][j]++;
		dep[i]=getsum(val[i]);
		sz[i]=a[i];
	}
	m=n;
	int st[N],top=0;
	For(i,1,n){
		if (top>0){
			vi lca=LCA(val[st[top]],val[i]);
			LL d=getsum(lca);
			if (d!=dep[st[top]]){
				while (top>1&&dep[st[top-1]]>=d){
					e[st[top-1]].pb(st[top]);
					e[st[top]].pb(st[top-1]);
					top--;
				}
				if (dep[st[top]]!=d){
					val[++m]=lca,dep[m]=d;
					e[m].pb(st[top]);
					e[st[top]].pb(m);
					st[top]=m;
				}
			}
		}
		st[++top]=i;
	}
	while (top>1){
		e[st[top]].pb(st[top-1]);
		e[st[top-1]].pb(st[top]);
		top--;
	}
//	For(i,1,m){
//		outtag();
//		outval(i);
//		outarr(val[i],0,(int)val[i].size()-1);
//		outarr(e[i],0,(int)e[i].size()-1);
//	}
	dfs(1,0);
	solve(rt,0,0);
//	outval(rt);
	cout<<ans<<endl;
	return 0;
}