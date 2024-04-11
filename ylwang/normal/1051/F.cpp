#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long 
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 100005;
int n, m;
struct Edge {
	int u, v, w, nxt;
}e[MAXN << 1];
int lst[MAXN], tot = 0;
inline void  addedge(int u, int v, int w) {
	e[++tot] = (Edge) {u, v, w, lst[u]};
	lst[u] = tot;
}
int fa[MAXN][21], sum[MAXN][21], dep[MAXN], vis[MAXN], E[MAXN], flag[MAXN], id[MAXN], cnt;
void dfs1(int u, int Fa, int w) {
	fa[u][0] = Fa, dep[u] = dep[Fa] + 1, vis[u] = 1, sum[u][0] = w;
	for(int i = 1; (1 << i) <= dep[u]; i++) sum[u][i] = sum[fa[u][i-1]][i-1] + sum[u][i-1], fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(vis[v]) {
			if(v != Fa) {
//				E[i] = 1; 
//				DEBUG;
//				cout << u << ' ' << v << endl; 
				
				if(!flag[v]) id[++cnt] = v, flag[v] = 1;
				if(!flag[u]) id[++cnt] = u, flag[u] = 1;
//				For(i, 1, cnt) cout << id[i] << ' ';
//				cout << endl << endl;
			}
			
			continue;
		}
		dfs1(v, u, e[i].w);
	}
}
int lcaval(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int ans = 0;
	for(int i = 20; i >= 0; i--)
		if(dep[u] - (1 << i) >= dep[v])
			ans += sum[u][i], u = fa[u][i];
	if(u == v) return ans;
	for(int i = 20; i >= 0; i--)
		if(fa[u][i] != fa[v][i])
			ans += sum[u][i], ans += sum[v][i], u = fa[u][i], v = fa[v][i];
	return ans + sum[u][0] + sum[v][0];
}
int dis[45][MAXN];
queue < int > q; bool used[MAXN];
void spfa(int s, int id) {
	For(i, 1, n) dis[id][i] = (1ll << 62);
	dis[id][s] = 0; q.push(s); used[s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop(); used[u] = 0;
		for(int i = lst[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(dis[id][v] > dis[id][u] + e[i].w) {
				dis[id][v] = dis[id][u] + e[i].w; 
				if(!used[v]) {
					used[v] = 1;
					q.push(v);
				}
			} 
		}
	}
}
signed main()
{
	cin >> n >> m;
	For(i, 1, m) {
		int u = read(), v = read(), w = read();
		addedge(u, v, w); addedge(v, u, w);
	}
	dfs1(1, 0, 0);
//	For(i, 1, m) {
//		if(E[i]) {
//			int u = e[i].u, v = e[i].v;
//			if(!flag[v]) id[++cnt] = v, flag[v] = 1;
//			if(!flag[u]) id[++cnt] = u, flag[u] = 1;
//		}
//	}
//	DEBUG;
//	For(i, 1, cnt) cout << id[i] << endl;
//	cout << cnt << endl;
	For(i, 1, cnt) {
		int s = id[i];
		spfa(s, i);
//		For(j, 1, n) {
//			cout << dis[i][j] << endl;
//		}
	}
	int Q = reaD();
	while(Q--) {
		int x = read(), y = read();
		int ans = lcaval(x, y);
		For(i, 1, cnt) {
			ckmin(ans, dis[i][x] + dis[i][y]);
		}
		printf("%lld\n", ans);
	}
    return 0;
}