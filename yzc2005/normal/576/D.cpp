#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 155;
const int inf = 0x3f3f3f3f;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(rg int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) return a, 0;
typedef pair<int, int> P;
typedef long long ll;
template <class T> inline void read(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}
template <class T> inline void addmod(T &a, T b) {a = (a + b) % mod;}

int n, m, d[N]; 

struct edge {
	int u, v, w;
	inline bool operator < (const edge &e1) const {return w < e1.w;}
}e[N];

#define bt bitset<N>
struct mat {
	bt a[N];
	inline friend bt operator * (bt x, mat y) {
		bt z;
		fu(i, 1, n) z[i] = (x & y.a[i]).any();
		return z;
	} 
	inline friend mat operator * (mat x, mat y) {
		mat z;
		fu(i, 1, n)
			fu(j, 1, n)
				if(x.a[i][j]) z.a[i] |= y.a[j];
		return z;
	}
} g;

inline void quickpow(mat a, int b, bt &z) {
	while(b) {
		if(b & 1) z = z * a;
		a = a * a, b >>= 1;
	}
}

int main() {
	read(n), read(m);
	fu(i, 1, m) read(e[i].u), read(e[i].v), read(e[i].w);
	sort(e + 1, e + m + 1);
	int ans = inf; bt v; v[1] = 1;
	fu(i, 1, m) {
		if(e[i].w >= ans) break;
		int b = e[i].w - e[i - 1].w;
		quickpow(g, b, v);
		g.a[e[i].v][e[i].u] = 1;
		queue<int> q;
		fu(u, 1, n) {
			if(v[u]) q.push(u), d[u] = 0;
			else d[u] = inf;
		}
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if(u == n) break;
			fu(v, 1, n) if(g.a[v][u] && d[v] > d[u] + 1) d[v] = d[u] + 1, q.push(v); 
		}
		ckmin(ans, e[i].w + d[n]);
	}
	finish(printf(ans == inf ? "Impossible" : "%d", ans));
	return 0;
}