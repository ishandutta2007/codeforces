#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=4e5+7, M=6e5+7, inf=0x3f3f3f3f;
int n1, n2, m, Q, u[N], v[N], id[N], cnt, a[N], link[N];
ll sum;
bool vis[N], is[N];
namespace flow {
	struct Edge {int to, nxt, f; } e[M<<1];
	int n, s, t, s_e, head[N], cur[N], dep[N];
	inline int add_e(int x, int y, int f) {
		e[++s_e]={y, head[x], f}, head[x]=s_e;
		e[++s_e]={x, head[y], 0}, head[y]=s_e;
		return s_e-1;
	}
	inline void init(int _n, int _s, int _t) {
		n=_n, s=_s, t=_t, s_e=1, fill(head+1, head+n+1, 0);
	}
	inline bool bfs() {
		for (int i=1; i<=n; i++) cur[i]=head[i], dep[i]=0;
		queue<int>q; q.push(s), dep[s]=1;
		while (!q.empty()){
			int x=q.front(); q.pop();
			for (int i=head[x], y; i; i=e[i].nxt)
				if (!dep[y=e[i].to] && e[i].f) dep[y]=dep[x]+1, q.push(y);
		}
		return dep[t];
	}
	int dfs(int x, int lim) {
		if (x==t) return lim; int flow=0;
		for (int &i=cur[x], y; i; i=e[i].nxt)
			if (dep[y=e[i].to]==dep[x]+1 && e[i].f) {
				int fl=dfs(y, min(e[i].f, lim-flow));
				e[i].f-=fl, e[i^1].f+=fl, flow+=fl;
				if (flow==lim) return lim;
			}
		return dep[x]=0, flow;
	}
	inline int dinic() {
		int flow=0;
		while (bfs()) flow+=dfs(s, inf);
		return flow;
	}
	void dfs(int x) {
		vis[x]=true;
		for (int i=head[x], y; i; i=e[i].nxt)
			if (e[i].f && (y=e[i].to)<=n1+n2 && !vis[y]) dfs(y);
	}
	inline void work() {
		for (int i=1; i<=m; i++) {
			if (e[id[i]].f) continue;
			is[i]=true, link[u[i]]=link[v[i]+n1]=i, sum+=i;
		}
		for (int i=1; i<=n1; i++) if (!link[i] && !vis[i]) dfs(i);
		for (int i=1; i<=n1; i++) if (!vis[i]) a[++cnt]=i;
		for (int i=n1+1; i<=n1+n2; i++) if (vis[i]) a[++cnt]=i;
		assert(count(is+1, is+m+1, true)==cnt);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n1=read(), n2=read(), m=read(), Q=read();
	int s=n1+n2+1, t=s+1; flow::init(t, s, t);
	for (int i=1; i<=m; i++) {
		int x=read(), y=read();
		id[i]=flow::add_e(x, y+n1, 1), u[i]=x, v[i]=y;
	}
	for (int i=1; i<=n1; i++) flow::add_e(s, i, 1);
	for (int i=n1+1; i<=n1+n2; i++) flow::add_e(i, t, 1);
	flow::dinic(), flow::work();
	while (Q--) {
		int opt=read();
		if (opt==1) {
			int x=a[cnt--]; is[link[x]]=false, sum-=link[x];
			cout<<"1\n"<<(x<=n1?x:-(x-n1))<<endl<<sum<<endl;
		} else {
			cout<<cnt<<'\n';
			for (int i=1; i<=m; i++) if (is[i]) cout<<i<<" ";
			cout<<endl;
		}
	}
	return 0;
}