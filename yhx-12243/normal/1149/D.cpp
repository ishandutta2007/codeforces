#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::vector <int> vector;
const int N = 81, M = 405, N2 = 131154;

int V, Ei, C, a, b;
int p[N], size[N];
int repr[N], bel[N];
int f[N2][N];
bool used[N2][N];
vector e[N], E[N];
std::queue <int> q, Q;

inline bool down(int &x, const int y) {return x > y ? x = y, 1 : 0;}
inline int F(int x) {return f[x >> 8][x & 255];}
inline int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

inline bool test(int x, int y, bool un = false) {
	if ((x = ancestor(x)) == (y = ancestor(y))) return true;
	return un && (size[x] < size[y] ? (p[x] = y, size[y] += size[x]) : (p[y] = x, size[x] += size[y]), false);
}

int main() {
	int i, j, u, v, w, x, S, ret;
	scanf("%d%d%d%d", &V, &Ei, &a, &b);
	std::iota(p, p + (V + 1), 0), std::fill(size, size + (V + 1), 1);
	for (i = 0; i < Ei; ++i)
		if (scanf("%d%d%d", &u, &v, &w), w == a) e[u].EB(v), e[v].EB(u), test(u, v, true);
		else if (w == b) E[u].EB(v), E[v].EB(u);
		else throw "error !";
	for (i = 1; i <= V; ++i) if (p[i] == i) size[i] > 3 ? repr[ bel[i] = C++ ] = i : (bel[i] = -1);
	for (i = 1; i <= V; ++i) bel[i] = bel[ancestor(i)], E[i].erase(std::remove_if(E[i].begin(), E[i].end(), [i] (const int x) {return test(i, x);}), E[i].end());
	i = (~bel[1] ? 1 << bel[1] : 0), q.push(i << 8 | 1);
	memset(f, 63, sizeof f), f[i][1] = 0;
	for (; !(q.empty() && Q.empty()); ) {
		if ( Q.empty() || (!q.empty() && F(q.front()) <= F(Q.front())) ) S = q.front(), q.pop();
		else S = Q.front(), Q.pop();
		if (used[ i = S >> 8 ][ x = S & 255 ]) continue;
		used[i][x] = true;
		for (int y : e[x]) if (down(f[i][y], f[i][x] + a)) q.emplace(i << 8 | y);
		for (int y : E[x])
			if (!(~bel[y] && i >> bel[y] & 1)) {
				j = (~bel[y] ? i | 1 << bel[y] : i);
				if (down(f[j][y], f[i][x] + b)) Q.emplace(j << 8 | y);
			}
	}
	for (v = 1; v <= V; ++v) {
		for (ret = INT_MAX, i = 0; i < 1 << C; ++i) down(ret, f[i][v]);
		printf("%d%c", ret, v == V ? 10 : 32);
	}
	return 0;
}