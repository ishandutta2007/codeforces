#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=5e5+7;
int n, m, cnt, ans[N], deg[N];
bool vis[N], flg[N], is[N];
vector<int>G[N];
inline void clear() {
	for (int i=1; i<=n; i++) G[i].clear(), vis[i]=flg[i]=is[i]=false, deg[i]=0;
	cnt=0;	
}
inline void out() {
	if (cnt==n) {puts("No"); return;}
	printf("Yes\n%d\n", n-cnt);
	for (int i=1; i<=cnt; i++) vis[ans[i]]=true;
	for (int i=1; i<=n; i++) if (!vis[i]) printf("%d ", i); putchar(10);
}
inline void bfs() {
	queue<int>q; static int pre[N], bel[N];
	memset(pre+1, 0, n<<2), memset(bel+1, 0, n<<2);
	for (int i=1; i<=n; i++) if (deg[i]==1) bel[i]=i, q.push(i);
	while (!q.empty()) {
		int x=q.front(); q.pop();
		for (int y:G[x]) {
			if (bel[y]==bel[x]) continue;
			if (!bel[y]) pre[y]=x, bel[y]=bel[x], q.push(y);
			else {	
				while (x) ans[++cnt]=x, x=pre[x];
				while (y) ans[++cnt]=y, y=pre[y];
				return out();
			}
		}
	}
	assert(0);
}
int pre[N], dep[N];
void dfs(int x, int fa) {
	flg[x]=true, dep[x]=dep[fa]+1;;
	for (int y:G[x]) {
		if (y==fa || deg[y]==1) continue;
		if (!flg[y]) pre[y]=x, dfs(y, x);
	}
}
void dfs1(int x, int fa) {
	for (int y:G[x]) {
		if (y==fa || deg[y]==1) continue;
		ans[++cnt]=y;
		if (!is[y]) dfs1(y, x);
		return;
	}
}
void dfs2(int x, int fa) {
	flg[x]=true;
	for (int y:G[x])
		if (y!=fa && deg[y]==2) dfs2(y, x);
}
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=m; i++) {
		int x=read(), y=read();
		G[x].push_back(y), G[y].push_back(x), deg[x]++, deg[y]++;
	}
	for (int i=1; i<=n; i++) deg[i]%=3;
	for (int i=1; i<=n; i++) if (!deg[i]) return ans[++cnt]=i, out();
	if (count(deg+1, deg+n+1, 1)>=2) return bfs();
	for (int i=1; i<=n; i++)
		if (!flg[i] && deg[i]==2) dfs(i, 0);
	int Min=n+1;
	for (int x=1; x<=n; x++)
		if (deg[x]==2)
			for (int y:G[x])
				if (deg[y]==2 && dep[y]-dep[x]>1) Min=min(Min, dep[y]-dep[x]+1);
	for (int x=1; x<=n; x++)
		if (deg[x]==2)
			for (int y:G[x])
				if (deg[y]==2 && dep[y]-dep[x]+1==Min) {
					while (y^x) ans[++cnt]=y, y=pre[y];
					return ans[++cnt]=x, out();
				}
	fill(flg+1, flg+n+1, false), ans[++cnt]=find(deg+1, deg+n+1, 1)-deg;
	for (int x:G[ans[1]]) is[x]=true;
	int tot=0;
	for (int i=1; i<=n; i++)
		if (!flg[i] && is[i]) {
			ans[++cnt]=i, dfs1(i, 0), dfs2(i, 0);
			if (++tot==2) break;
		}
	assert(tot==2), out();
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work(), clear();
	return 0;
}