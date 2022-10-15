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
const int N=1e6+7;
int n, m, Q, dep[N], d[N];
int s_dfn, dfn[N], lg[N<<1], st[21][N<<1];
vector<int>G[N];
inline void bfs() {
	fill(d+1, d+n+1, -1); queue<int>q;
	for (int i=1; i<=n; i++) if ((int)G[i].size()==1) d[i]=0, q.push(i);
	while (!q.empty()) {
		int x=q.front(); q.pop();
		for (int y:G[x]) if (!~d[y]) d[y]=d[x]+1, q.push(y);
	}
}
void dfs(int x, int fa) {
	dfn[x]=++s_dfn, st[0][s_dfn]=x, dep[x]=dep[fa]+1;
	for (int y:G[x]) if (y^fa) dfs(y, x), st[0][++s_dfn]=x;
}
inline int Min(int x, int y) {return dep[x]<dep[y]?x:y;}
inline void init_st() {
	lg[0]=-1; for (int i=1; i<=s_dfn; i++) lg[i]=lg[i>>1]+1;
	for (int j=1; j<=lg[s_dfn]; j++)
		for (int i=1; i+(1<<j)-1<=s_dfn; i++)
			st[j][i]=Min(st[j-1][i], st[j-1][i+(1<<(j-1))]);
}
inline int LCA(int x, int y) {
	x=dfn[x], y=dfn[y]; if (x>y) swap(x, y);
	int k=lg[y-x+1]; return Min(st[k][x], st[k][y-(1<<k)+1]);
}
inline int dist(int x, int y) {return dep[x]+dep[y]-dep[LCA(x, y)]*2;}
struct node {
	int d, x, y;
	node(int _d=-1, int _x=-1, int _y=-1) :d(_d), x(_x), y(_y) {}
	bool operator <(const node &q) const { return d<q.d; }
	friend node operator +(const node &q, const node &p) {
		if (!~q.d) return p; if (!~p.d) return q; node t=max(q, p);
		for (int a:{q.x, q.y}) for (int b:{p.x, p.y}) ckmax(t, node(dist(a, b), a, b));
		return t;
	}
	node& operator +=(const node &q) {return *this=*this+q;}
} t[N], suf[N];
inline bool check(int ans, int i, int x) {
	int j=max(0, ans-i-x); if (j>m) return false;
	for (int a:{t[i].x, t[i].y})
		for (int b:{suf[j].x, suf[j].y})
			if (dist(a, b)>=ans) return true;
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=2, x; i<=n; i++) x=read(), G[x].push_back(i), G[i].push_back(x);
	bfs(), dfs(1, 0), init_st();
	for (int i=1; i<=n; i++) t[d[i]]+=node(0, i, i);
	m=*max_element(d+1, d+n+1), suf[m]=t[m];
	for (int i=m-1; ~i; i--) suf[i]=t[i]+suf[i+1];
	Q=read();
	while (Q--) {
		int x=read(), ans=0;
		for (int i=0; i<=m; i++) while (check(ans+1, i, x)) ans++;
		printf("%d ", ans);
	}
	return 0;
}