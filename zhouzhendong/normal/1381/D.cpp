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
#define outv(x) cerr<<#x" = "<<x<<"   "
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
	if (x>y)
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
const int N=100005;
int n,a,b,lenab;
vi e[N];
int sz[N],fa[N][20],dep[N];
void dfs(int x,int pre,int d){
	dep[x]=d,sz[x]=1,fa[x][0]=pre;
	For(i,1,19)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (auto y : e[x])
		if (y!=pre){
			dfs(y,x,d+1);
			sz[x]+=sz[y];
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y])
		swap(x,y);
	Fod(i,19,0)
		if (dep[x]-(1<<i)>=dep[y])
			x=fa[x][i];
	if (x==y)
		return x;
	Fod(i,19,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int mxlen[N];
int isgood[N];
void dp0(int x,int pre){
	mxlen[x]=dep[x];
	for (auto y : e[x])
		if (y!=pre){
			dp0(y,x);
			ckmax(mxlen[x],mxlen[y]);
		}
}
void dp1(int x,int pre,int uplen){
	vi val;
	for (auto y : e[x])
		if (y!=pre)
			val.pb(mxlen[y]);
	sort(val.begin(),val.end(),greater <int>());
	if (val.size()>=3&&val[2]-dep[x]>=lenab)
		isgood[x]=1;
	else if (val.size()>=2&&val[1]-dep[x]>=lenab&&uplen>=lenab)
		isgood[x]=1;
	val.pb(-1);
	for (auto y : e[x])
		if (y!=pre)
			dp1(y,x,max(uplen,val[mxlen[y]==val[0]]-dep[x])+1);
}
int leaf[N];
void getleaf(int x,int pre){
	leaf[x]=x;
	for (auto y : e[x])
		if (y!=pre){
			getleaf(y,x);
			if (dep[leaf[y]]>dep[leaf[x]])
				leaf[x]=leaf[y];
		}
}
void solve(){
	n=read(),a=read(),b=read();
	For(i,1,n)
		e[i].clear();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0,0);
	lenab=dep[a]+dep[b]-dep[LCA(a,b)]*2;
	dp0(1,0);
	For(i,1,n)
		isgood[i]=0;
	dp1(1,0,0);
	int rt=0;
	For(i,1,n)
		if (isgood[i]){
			rt=i;
			break;
		}
	if (!rt)
		return (void)puts("NO");
	dfs(rt,0,0);
	getleaf(rt,0);
	int c=n+5;
	if (LCA(a,b)==a||LCA(a,b)==b)
		return (void)puts("YES");
	while (c--){
		int c=leaf[b],lca=LCA(a,b),disbc=dep[c]-dep[b];
		if (dep[c]-dep[lca]>=lenab)
			return (void)puts("YES");
		Fod(i,19,0)
			if (disbc>>i&1)
				a=fa[a][i];
		b=c;
		swap(a,b);
	}
	puts("NO");
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}