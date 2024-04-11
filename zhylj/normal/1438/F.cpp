#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ull kMod = 998244353;

ui s = time(0);
ui Rand() { s ^= 0xa72b3e1f; s = (ull)s * s % kMod; return s; }

int n, h;

#ifndef ONLINE_JUDGE
int p[kN];
std::vector <int> E[kN];
void Add(int u, int v) { E[u].push_back(v); E[v].push_back(u); }
void Init() {
	for(int i = 1; i <= n; ++i) rd(p[i]);
	for(int i = 2; i <= n; ++i) {
		Add(p[i], p[i / 2]);
	}
}
int fa[kN], d[kN];
void Dfs(int u) {
	//std::cout << u << std::endl;
	d[u] = d[fa[u]] + 1;
	for(auto v : E[u]) if(v != fa[u]) {
		fa[v] = u; Dfs(v);
	}
}
int Query(int u, int v, int w) {
	memset(d, 0, sizeof(d));
	memset(fa, 0, sizeof(fa));
	Dfs(w);
	//std::cout << u << " " << v << " " << w << " ";
	while(u != v) {
		if(d[u] < d[v]) std::swap(u, v);
		u = fa[u];
	}
	//std::cout << "?" << std::endl;
	//std::cout << u << std::endl;
	return u;
}
#endif
#ifdef ONLINE_JUDGE
void Init() {  }
int Query(int u, int v, int w) {
	printf("? %d %d %d\n", u, v, w);
	fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}
#endif

int buc[kN], idx[kN];
int Solve() {
	for(int i = 1; i <= n; ++i) idx[i] = i;
	for(int i = 1; i <= 422; ++i) {
		int u = Rand() % n + 1, v = Rand() % n + 1, w = Rand() % n + 1;
		while(v == u) v = Rand() % n + 1;
		while(w == v || w == u) w = Rand() % n + 1;
		++buc[Query(u, v, w)];
	}
	std::sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {
		return buc[x] > buc[y];
	});
	memset(buc, 0, sizeof(buc));
	int x = idx[1], y = idx[2];
//	std::cout << x << " " << y << std::endl;
	for(int i = 1; i <= n; ++i) if(i != x && i != y) {
		if(Query(x, y, i) == i) return i;
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		//printf("%u\n", s);
		rd(h); n = (1 << h) - 1;
		Init();
		printf("! %d\n", Solve());
	} return 0;
}