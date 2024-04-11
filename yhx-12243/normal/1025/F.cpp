#include <bits/stdc++.h>

typedef long long ll;
const int N = 2054;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%d%d", &x, &y); return this;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator * (const vec2 &B) const {return (ll)x * B.x + (ll)y * B.y;}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
	inline ll norm2() const {return (ll)x * x + (ll)y * y;}
	inline bool operator < (const vec2 &B) const {return (y < 0) ^ (B.y < 0) ? (B.y < 0) : (*this ^ B) > 0 || (!(*this ^ B) && x > 0 && B.x < 0);}
} p[N], q[N];

inline bool geStraight(const vec2 A, const vec2 B) {return (A ^ B) < 0 || (!(A ^ B) && A * B < 0);}

int n;

inline ll C2(int n) {return n * (n - 1ll) / 2;}

int main() {
	int i, j, k, m; ll ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) p[i].read();
	for (i = 0; i < n; ++i) {
		for (m = j = 0; j < n; ++j)
			if (j != i) q[m++] = p[j] - p[i];
		std::sort(q, q + m);
		for (k = j = 0; j < m && (q[j].y > 0 || (!q[j].y && q[j].x > 0)); ++j) {
			for (; k < m && !geStraight(q[j], q[k]); ++k);
			ans += C2(k - j - 1) * C2(m - k + j);
		}
	}
	printf("%lld\n", ans);
	return 0;
}