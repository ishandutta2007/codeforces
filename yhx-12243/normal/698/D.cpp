#include <bits/stdc++.h>
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
const int N = 1054;

struct vec2 {
	int x, y, id;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	vec2 * read() {return scanf("%d%d", &x, &y), this;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator * (const vec2 &B) const {return (ll)x * B.x + (ll)y * B.y;}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
	inline ll norm2() const {return (ll)x * x + (ll)y * y;}
	inline bool operator < (const vec2 &B) const {return y < 0 ^ B.y < 0 ? B.y < 0 : (*this ^ B) > 0 || !(*this ^ B) && (x < 0 ^ B.x < 0 ? B.x < 0 : norm2() < B.norm2());}
} a[7], m[N];

int n, K, all;
int perm[7], id[N];
int next[7][N];
int stamp = 0, used[N];

inline bool dfs(int w) {
	if (used[w] == stamp) return true;
	if (all >= K) return false;
	int v, cur = perm[all++];
	for (v = next[cur][w]; ~v && dfs(v); v = next[cur][v]);
	return used[w] = stamp, !~v;
}

int main() {
	int i, j, ans = 0;
	scanf("%d%d", &K, &n);
	for (i = 0; i < K; ++i) a[i].read();
	for (i = 0; i < n; ++i) m[i].read();
	memset(next, -1, sizeof next);
	std::iota(id, id + n, 0);
	for (i = 0; i < K; ++i) {
		std::sort(id, id + n, [i] (const int x, const int y) {return m[x] - a[i] < m[y] - a[i];});
		for (j = 1; j < n; ++j) if (!cross(a[i], m[ id[j-1] ], m[ id[j] ]) && dot(a[i], m[ id[j-1] ], m[ id[j] ]) > 0) next[i][id[j]] = id[j - 1];
	}
	for (i = 0; i < n; ++i) {
		std::iota(perm, perm + K, 0);
		do if (all = 0, ++stamp, dfs(i)) {++ans; break;} while (std::next_permutation(perm, perm + K));
	}
	printf("%d\n", ans);
	return 0;
}