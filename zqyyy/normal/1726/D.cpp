#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7;
int n, m;
bool ok, vis[N], flg[N];
pair<int, int> e[N];
vector<pair<int, int> >G[N];
void dfs(int x) {
	vis[x]=true;
	for (auto y:G[x]) if (!vis[y.fi]) flg[y.se]=true, dfs(y.fi);
}
void del(int x, int fa, int u) {
	for (auto t:G[x]) {
		int y=t.fi, id=t.se;
		if (!flg[id] || y==fa) continue;
		if (y==u) {ok=true, flg[id]=0; return;}
		del(y, x, u);
		if (ok) break;
	}
}
inline void out() {
	for (int i=1; i<=m; i++) printf("%d", flg[i]); puts("");
}
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=n; i++) G[i].clear(), vis[i]=false;
	for (int i=1; i<=m; i++) {
		int x=read(), y=read(); e[i]={x, y};
		G[x].push_back({y, i}), G[y].push_back({x, i}), flg[i]=0;
	}
	dfs(1);
	if (m<=n+1) return out();
	int tp=0, a[3];
	for (int i=1; i<=m; i++) if (!flg[i]) a[tp++]=i;
	int x=a[0], y=a[1], z=a[2];
	if (e[x].fi^e[x].se^e[y].fi^e[y].se^e[z].fi^e[z].se) return out();
	ok=0, del(e[x].fi, 0, e[x].se), flg[x]=1, out();
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}