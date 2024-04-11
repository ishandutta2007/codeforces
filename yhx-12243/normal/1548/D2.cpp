#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 6054;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	friend std::istream & operator >> (std::istream &in, vec2 &B) {return in >> B.x >> B.y;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline int operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
	inline int gcd() const {return abs(std::__gcd(x, y));}
	inline int pack() const {return (x & 3) | (y & 3) << 2 | (gcd() & 3) << 4;}
} p[N];

int n;
int c[64][64], e[64];

inline void init() {
	int u, v, d, S; vec2 a, b;
	for (u = 0; u < 64; ++u) {
		a = vec2(u & 3, u >> 2 & 3);
		for (v = 0; v < 64; ++v) {
			b = vec2(v & 3, v >> 2 & 3);
			S = (a ^ b) & 3, d = (a - b).gcd();
			if ((S | d) & 1) continue;
			if ((d + (u >> 4) + (v >> 4) - S) & 3) continue;
			c[u][v] = (u & 16 ? 3 : 1);
		}
	}
}


int main() {
	int i, j, u, v; long long ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	init(); cin >> n;
	for (i = 0; i < n; ++i) cin >> p[i];
	for (i = 0; i < n; ++i) {
		memset(e, 0, sizeof e);
		for (j = 0; j < n; ++j) if (j != i) ++e[(p[j] - p[i]).pack()];
		for (u = 0; u < 64; ++u) if (e[u]) for (v = u; v < 64; ++v) if (e[v] && c[u][v])
			ans += (u == v ? e[u] * (e[u] - 1) / 2 : e[u] * e[v]) * c[u][v];
	}
	cout << ans / 3 << '\n';
	return 0;
}