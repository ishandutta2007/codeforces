#include <bits/stdc++.h>
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
const int N = 2054;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%d%d", &x, &y); return this;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
	inline bool operator < (const vec2 &B) const {return x < B.x || (x == B.x && y < B.y);}
} p[N];

int n;
int o[N];
char s[N];
bool used[N];

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) p[i].read();
	scanf("%s", s + 1);
	*o = std::min_element(p, p + n) - p, used[*o] = true;
	for (i = 1; i < n - 1; ++i) {
		vec2 &base = p[o[i - 1]]; int &ret = o[i]; ret = -1;
		for (j = 0; j < n; ++j) if (!used[j])
			if (!~ret || (s[i] == 76 ? cross(base, p[j], p[ret]) > 0 : cross(base, p[j], p[ret]) < 0)) ret = j;
		used[ret] = true;
	}
	o[n - 1] = std::find(used, used + n, false) - used;
	for (i = 0; i < n; ++i) printf("%d%c", o[i] + 1, i == n - 1 ? 10 : 32);
	return 0;
}