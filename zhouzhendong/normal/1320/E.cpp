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
const int N=200005;
int n;
vi e[N];
int fa[N][20],d[N],I[N],O[N];
void dfs(int x,int pre,int dep){
	static int Time=0;
	I[x]=++Time,d[x]=dep,fa[x][0]=pre;
	For(i,1,19)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (auto y : e[x])
		if (y!=pre)
			dfs(y,x,dep+1);
	O[x]=Time;
}
int lca(int x,int y){
	if (d[x]<d[y])
		swap(x,y);
	Fod(i,19,0)
		if (d[x]-(1<<i)>=d[y])
			x=fa[x][i];
	if (x==y)
		return x;
	Fod(i,19,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){
	return d[x]+d[y]-d[lca(x,y)]*2;
}
int k,m;
vi ve[N];
void pve(int x,int y){
//	int z=dis(x,y);
//	ve[x].pb(mp(y,z));
//	ve[y].pb(mp(x,z));
	ve[x].pb(y),ve[y].pb(x);
}
int res[N];
struct P{
	int x,v;
	LL t;
	P(){}
	P(int _x,int _v,LL _t){
		x=_x,v=_v,t=_t;
	}
	friend bool operator < (P a,P b){
		return a.t>b.t;
	}
};
void Solve(){
	k=read(),m=read();
	vi v(k+1),s(k+1),u(m),id(1,1);
	For(i,1,k)
		v[i]=read(),s[i]=read(),id.pb(v[i]);
	For(i,0,m-1)
		u[i]=read(),id.pb(u[i]);
	sort(id.begin(),id.end());
	id.resize(unique(id.begin(),id.end())-id.begin());
	sort(id.begin(),id.end(),[&](int a,int b)->bool{return I[a]<I[b];});
	static int st[N];
	int top=0;
	vi tid=id;
	for (auto i : id){
		ve[i].clear();
		if (top>0){
			int f=lca(i,st[top]);
			while (d[st[top]]>d[f]){
				if (d[st[top-1]]>=d[f])
					pve(st[top],st[top-1]),top--;
				else {
					tid.pb(f),ve[f].clear();
					pve(st[top],f),st[top]=f;
				}
			}
		}
		st[++top]=i;
	}
	while (top>1)
		pve(st[top],st[top-1]),top--;
	for (auto i : tid)
		res[i]=0;
	priority_queue <P> Q;
	For(i,1,k)
		Q.push(P(v[i],i,i));
	while (!Q.empty()){
		P p=Q.top();
		Q.pop();
		if (res[p.x])
			continue;
		res[p.x]=p.v;
		for (auto y : ve[p.x])
			if (!res[y])
				Q.push(P(y,p.v,(LL)((dis(v[p.v],y)+s[p.v]-1)/s[p.v])*k+p.v));
	}
	For(i,0,m-1)
		printf("%d ",res[u[i]]);
	puts("");
}
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0,0);
	int q=read();
	while (q--)
		Solve();
	return 0;
}