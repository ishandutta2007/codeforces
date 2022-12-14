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

const int N = 1e5 + 10;

int first[N], cur = 1;
struct Edge {
	int nxt , to;
	Edge(int nxt = 0 , int to = 0) : nxt(nxt) , to(to) {} 
}	e[N << 1];
void con(int x, int y) {e[++cur] = Edge(first[x], y), first[x] = cur;}

int T, n;
int l[N], r[N];
ll dp[N][2];

void dfs(int x, int fa) {
	dp[x][0] = dp[x][1] = 0;
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to; if (v == fa) continue; dfs(v, x);
		dp[x][0] += max(dp[v][0] + abs(l[x] - l[v]), dp[v][1] + abs(l[x] - r[v]));
		dp[x][1] += max(dp[v][0] + abs(r[x] - l[v]), dp[v][1] + abs(r[x] - r[v]));
	}
}

int main() {
	for (read(T); T; T--) {
		read(n), cur = 1;
		for (int i = 1; i <= n; i++)
			read(l[i]), read(r[i]);
		for (int i = 1; i <= n; i++)
			first[i] = 0;
		for (int i = 1; i < n; i++) {
			int u, v; read(u), read(v);
			con(u, v), con(v, u);
		}
		dfs(1, 0);
		print(max(dp[1][0], dp[1][1]), '\n');
	}
	return 0;
}