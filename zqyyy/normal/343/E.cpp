#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=207, M=1007, inf=0x3f3f3f3f;
struct edge {int x, y, w;} e[M];
namespace flow {
	struct Edge {int to, nxt, f;} e[M<<2];
	int n, s, t, s_e, head[N], cur[N], dep[N];
	inline void add_e(int x, int y, int f) {
		e[++s_e]={y, head[x], f}, head[x]=s_e;
		e[++s_e]={x, head[y], 0}, head[y]=s_e;
	}
	inline void init(int _n, int _s, int _t) {
		n=_n, s=_s, t=_t, s_e=1, fill(head+1, head+n+1, 0);
	}
	inline bool bfs() {
		queue<int>q; fill(dep+1, dep+n+1, 0), dep[s]=1, q.push(s);
		while (!q.empty()) {
			int x=q.front(); q.pop();
			for (int i=head[x], y; i; i=e[i].nxt)
				if (e[i].f && !dep[y=e[i].to]) dep[y]=dep[x]+1, q.push(y);
		}
		return dep[t];
	}
	int dfs(int x, int lim) {
		if (x==t) return lim; int flow=0;
		for (int &i=cur[x], y; i; i=e[i].nxt)
			if (e[i].f && dep[y=e[i].to]==dep[x]+1) {
				int f=dfs(y, min(e[i].f, lim-flow));
				e[i].f-=f, e[i^1].f+=f, flow+=f;
				if (flow==lim) return flow;
			}
		return dep[x]=0, flow;
	}
	inline int dinic() {
		int flow=0;
		while (bfs()) memcpy(cur+1, head+1, n<<2), flow+=dfs(s, inf);
		return flow;
	}
}
int n, m;
namespace Tree {
	struct Edge {int to, nxt, w;}e[N<<1];
	int s_e=1, head[N];
	inline void add_e(int x, int y, int w) {
		e[++s_e]={y, head[x], w}, head[x]=s_e;
		e[++s_e]={x, head[y], w}, head[y]=s_e;
	}
	int ans;
	bool flg[N];
	void dfs(int x, int fa, int &p) {
		for (int i=head[x]; i; i=e[i].nxt) {
			int y=e[i].to; if(y==fa || flg[i>>1]) continue;
			if (e[p].w>e[i].w) p=i; dfs(y, x, p);
		}
	}
	void solve(int x) {
		int p=0; dfs(x, 0, p);
		if (!p) {printf("%d ", x); return;}
		flg[p>>1]=true, solve(e[p].to), solve(e[p^1].to);
	}
	inline void Solve() {
		for (int i=2; i<=s_e; i+=2) ans+=e[i].w;
		printf("%d\n", ans), e[0].w=inf, solve(1);
	}
}
mt19937 RAND(random_device{}());
inline int rnd(int l, int r) {
	return uniform_int_distribution<>(l, r)(RAND);
}
void build(const vector<int> &vec) {
	int x, y, sz=vec.size(); if (sz==1) return;
	do x=rnd(0, sz-1), y=rnd(0, sz-1); while(x==y);
	x=vec[x], y=vec[y], flow::init(n, x, y);
	for (int i=1; i<=m; i++) flow::add_e(e[i].x, e[i].y, e[i].w), flow::add_e(e[i].y, e[i].x, e[i].w);
	Tree::add_e(x, y, flow::dinic()); vector<int>l, r;
	for (int x:vec) (flow::dep[x]?l:r).push_back(x);
	build(l), build(r);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), m=read();
	for (int i=1; i<=m; i++) e[i].x=read(), e[i].y=read(), e[i].w=read();
	vector<int>tmp(n); iota(tmp.begin(), tmp.end(), 1), build(tmp), Tree::Solve();
	return 0;
}