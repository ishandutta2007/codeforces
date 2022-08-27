#include <bits/stdc++.h>
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
const int N = 354;
typedef std::bitset <N> bitset;

struct vec2 {
	int x, y;
	vec2 (int _x = 0, int _y = 0) : x(_x), y(_y) {}
	vec2 * read() {return scanf("%d%d", &x, &y), this;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
} p[N];

int n;
ll C3, C4, C5, ALL;
bitset e[N][N];

int main() {
	int i, j, k, t;
	scanf("%d", &n), ALL = n * (n - 1ll) / 2 * (n - 2ll) / 3 * (n - 3ll) / 4 * (n - 4ll) / 5;
	for (i = 0; i < n; ++i) p[i].read();
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			for (k = j + 1; k < n; ++k)
				cross(p[i], p[j], p[k]) >= 0
					? (e[j][k].set(i), e[k][i].set(j), e[i][j].set(k))
					: (e[k][j].set(i), e[i][k].set(j), e[j][i].set(k));
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			for (k = j + 1; k < n; ++k)
				t = (e[i][j].test(k) ? e[i][j] & e[j][k] & e[k][i] : e[i][k] & e[k][j] & e[j][i]).count(),
				C3 += t * (t - 1ll) / 2, C4 += t;
	C4 = C4 * (n - 4) / 2 - C3 * 2, C5 = ALL - C3 - C4;
	printf("%lld\n", C5);
//	fprintf(stderr, "C3 = %lld, C4 = %lld, C5 = %lld\n", C3, C4, C5);
	return 0;
}