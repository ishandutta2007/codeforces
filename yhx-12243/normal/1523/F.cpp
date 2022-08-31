#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef unsigned __int128 u128;
const int N = 16, M = 108, N2 = 16400, INF = 0x3f3f3f3f;
const u128 one = 1;

struct vec2 {
	int x, y;
	vec2 () {}
	vec2 (int x0, int y0) : x(x0), y(y0) {}
	friend std::istream & operator >> (std::istream &in, vec2 &B) {return in >> B.x >> B.y;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline int norm1() const {return abs(x) + abs(y);}
} p[N];

typedef std::pair <vec2, int> piv;

int n, m, ALL;
piv task[M];
int disp[N][N2];
int dist[M][N2];
int f[M][N2];
int g[M][N2];
// f[i][j] : ans = i, set = j, min time

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

int main() {
	int i, j, k, l, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m, ALL = ~(-1 << n);
	for (i = 0; i < n; ++i) cin >> p[i];
	for (i = 0; i < m; ++i) cin >> task[i].first >> task[i].second;
	std::sort(task, task + m, [] (const piv &A, const piv &B) {return A.second < B.second;});
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) disp[i][1 << j] = (p[i] - p[j]).norm1();
		disp[i][0] = INF;
		for (j = 3; j <= ALL; ++j) down(disp[i][j] = disp[i][j & -j], disp[i][j & (j - 1)]);
	}
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) dist[i][1 << j] = (task[i].first - p[j]).norm1();
		dist[i][0] = INF;
		for (j = 3; j <= ALL; ++j) down(dist[i][j] = dist[i][j & -j], dist[i][j & (j - 1)]);
	}
	memset(f, 63, sizeof f), memset(g, -1, sizeof g);
	for (i = 0; i < n; ++i) f[0][1 << i] = 0;
	for (j = 0; j < m; ++j) g[j][0] = 1;
	for (i = 0; i <= m; ++i)
		for (j = 0; j <= ALL; ++j) {
			if (f[i][j] < INF) {
				up(ans, i);
				for (k = 0; k < n; ++k)
					if (!(j >> k & 1))
						down(f[i][j | 1 << k], f[i][j] + disp[k][j]);
				for (k = 0; k < m; ++k)
					if (f[i][j] + dist[k][j] <= task[k].second)
						up(g[k][j], i + 1);
			}
			for (l = 0; l < m; ++l)
				if (g[l][j] == i) {
					up(ans, i);
					for (k = 0; k < n; ++k)
						if (!(j >> k & 1))
							down(f[i][j | 1 << k], task[l].second + min((p[k] - task[l].first).norm1(), disp[k][j]));
					for (k = l + 1; k < m; ++k)
						if (task[l].second + min((task[k].first - task[l].first).norm1(), dist[k][j]) <= task[k].second)
							up(g[k][j], i + 1);
				}
		}
	cout << ans << '\n';
	return 0;
}