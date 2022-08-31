#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
#define gcd std::__gcd
using std::cin;
using std::cout;

typedef long long ll;
const int N = 6016;
typedef std::bitset <N> bitset;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	friend std::istream & operator >> (std::istream &in, vec2 &B) {return in >> B.x >> B.y;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
} p[N];

int n, bl[4];
bitset G[N];

inline ll C3(int x) {return x * (x - 1ll) * (x - 2ll) / 6;}

int main() {
	int i, j, d, c0, c1; ll u = 0, v = 0; vec2 t;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> p[i];
		++bl[ (p[i].x & 2) | (p[i].y >> 1 & 1) ];
	}
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j) {
			t = p[i] - p[j], d = gcd(t.x, t.y);
			if (d & 2) G[i].set(j), G[j].set(i);
		}
	for (i = 0; i < n; ++i)
		c1 = G[i].count(), c0 = n - 1 - c1,
		u += c0 * (c0 - 1ll) / 2, v += (ll)c0 * c1;

	ll _000, _011;
	_000 = C3(bl[0]) + C3(bl[1]) + C3(bl[2]) + C3(bl[3]),
	_011 = 3 * _000 - u + v / 2;
	cout << _000 + _011 << '\n';
	return 0;
}