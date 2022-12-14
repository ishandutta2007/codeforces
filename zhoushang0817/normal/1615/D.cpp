#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

struct E {int x, y, z;} in[N];
int first[N], cur;
struct Edge {int nxt, to, w, id;} e[N << 1];
void con(int x, int y, int id) {
	e[++cur] = (Edge){first[x], y, in[id].z, id};
	first[x] = cur;
}

int T, n, m, fa[N << 1], used[N << 1], ans[N << 1];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void Con(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	fa[fa[x]] = fa[y];
}

void dfs1(int x, int fa) {
	for (int i = first[x]; i; i = e[i].nxt) {
		int to = e[i].to; if (to == fa) continue;
		int w = e[i].w;
		if (w != -1) {
			w = __builtin_popcount(w);
			if (w & 1) Con(x, to + n), Con(x + n, to);
			else Con(x, to), Con(x + n, to + n);
		}
		dfs1(to, x);
	}
}

void dfs2(int x, int fa) {
	for (int i = first[x]; i; i = e[i].nxt) {
		int to = e[i].to; if (to == fa) continue;
		int w = e[i].w;
		if (w == -1) {
			if (used[find(to)]) in[e[i].id].z = ans[x], ans[to] = 0;
			else if (used[find(to + n)]) in[e[i].id].z = ans[x] ^ 1, ans[to] = 1;
			else in[e[i].id].z = ans[x], ans[to] = 0, used[find(to)] = 1;
		}
		else {
			w = (__builtin_popcount(w)) & 1;
			ans[to] = ans[x] ^ w;
		}
		dfs2(to, x);
	}
}

int main() {
	for (read(T); T; T--) {
		read(n), read(m), cur = 0;
		for (int i = 1; i <= n; i++) first[i] = 0;
		for (int i = 1; i < n; i++) {
			read(in[i].x), read(in[i].y), read(in[i].z);
			con(in[i].x, in[i].y, i);
			con(in[i].y, in[i].x, i);
		}
		for (int i = 1; i <= n * 2; i++) fa[i] = i;
		dfs1(1, 0); int flag = 0;
		for (int i = 1; i <= m; i++) {
			int x, y, z; read(x), read(y), read(z);
			if (flag) continue;
			if (z == 1) {
				if (find(x + n) == find(y + n)) flag = 1;
				else Con(x, y + n), Con(y, x + n);
			}
			else {
				if (find(x) == find(y + n)) flag = 1;
				else Con(x, y), Con(x + n, y + n);
			}
		}
		if (flag) puts("NO");
		else {
			puts("YES");
			for (int i = 1; i <= n * 2; i++) used[i] = ans[i] = 0;
			used[find(1)] = 1, dfs2(1, 0);
			for (int i = 1; i < n; i++) {
				print(in[i].x, ' ');
				print(in[i].y, ' ');
				print(in[i].z, '\n');
			}
		}
	}
	return 0;
}