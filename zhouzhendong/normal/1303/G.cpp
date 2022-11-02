#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
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
const int N=150005;
const LL Q_Tag=-1.02e18;
struct Line{
	LL k,b;
	mutable function <const Line *()> nxt;
	bool operator < (const Line &x) const {
		if (x.b!=Q_Tag)
			return k!=x.k?k<x.k:b<x.b;
		const Line *s=nxt();
		if (!s)
			return 0;
		return b-(*s).b<((*s).k-k)*x.k;
	}
};
struct DynamicHull:public multiset <Line>{
	int useless(iterator y){
		iterator z=next(y);
		if (y==begin()){
			if (z==end())
				return 0;
			return (*y).k==(*z).k&&(*y).b<=(*z).b;
		}
		iterator x=prev(y);
		if (z==end())
			return (*y).k==(*x).k&&(*y).b<=(*x).b;
		return ((*x).b-(*y).b)*((*z).k-(*y).k)
			 >=((*y).b-(*z).b)*((*y).k-(*x).k);
	}
	void insert_line(LL k,LL b){
		iterator x=insert({k,b});
		x->nxt=[=]{return next(x)==end()?0:&*next(x);};
		if (useless(x)){
			erase(x);
			return;
		}
		while (next(x)!=end()&&useless(next(x)))
			erase(next(x));
		while (x!=begin()&&useless(prev(x)))
			erase(prev(x));
	}
	LL calc(LL x){
		Line L=*lower_bound({x,Q_Tag});
		return L.k*x+L.b;
	}
};
int n;
LL a[N];
vector <int> e[N];
DynamicHull hull;
int vis[N],sz[N],mx[N];
int rt,sz_all;
void dfs1(int x,int pre=0){
	sz[x]=1,mx[x]=0;
	for (auto y : e[x])
		if (!vis[y]&&y!=pre){
			dfs1(y,x);
			sz[x]+=sz[y];
			mx[x]=max(mx[x],sz[y]);
		}
	mx[x]=max(mx[x],sz_all-sz[x]);
	if (!rt||mx[x]<mx[rt])
		rt=x;
}
LL ans=0;
void dfs2(int x,int pre,LL d,LL s,LL ss){
	d++,s+=a[x],ss+=d*a[x];
	ans=max(ans,hull.calc(s)+ss);
	for (auto y : e[x])
		if (!vis[y]&&y!=pre)
			dfs2(y,x,d,s,ss);
}
void dfs3(int x,int pre,LL d,LL s,LL ss){
	d++,s+=a[x],ss+=s;
	hull.insert_line(d,ss);
	ans=max(ans,ss+a[rt]*(d+1));
	for (auto y : e[x])
		if (!vis[y]&&y!=pre)
			dfs3(y,x,d,s,ss);
}
void Solve(int x,int Size){
	rt=0,sz_all=Size,dfs1(x),x=rt,vis[x]=1;
	ans=max(ans,a[x]);
	For(_,0,1){
		hull.clear();
		hull.insert_line(0,0);
		for (auto y : e[x])
			if (!vis[y]){
				dfs2(y,x,1,a[x],a[x]);
				dfs3(y,x,0,0,0);
			}
		reverse(e[x].begin(),e[x].end());
	}
	for (auto y : e[x])
		if (!vis[y])
			Solve(y,sz[y]>sz[x]?Size-sz[x]:sz[y]);
}
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n)
		a[i]=read();
	Solve(1,n);
	cout<<ans<<endl;
	return 0;
}