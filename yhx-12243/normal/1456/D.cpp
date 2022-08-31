#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 5054;

struct cake {
	int t, x;
	friend std::istream & operator >> (std::istream &in, cake &B) {return in >> B.t >> B.x;}
} a[N];

int n, m = 0;
bool f[N][N];
int r1[N], r2[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int mindist(int l, int r, int x) {return x < l ? l - x : x < r ? 0 : x - r;}

int main() {
	int i, j, k, l, r, d, t_max;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		if (abs(a[i].x) > a[i].t) return cout << "NO\n", 0;
	}
	memset(r1, -1, sizeof r1), memset(r2, -1, sizeof r2), *r1 = 0;
	for (i = 0; i < n; ++i) {
		d = a[i + 1].t - a[i].t;

		if (abs(a[i + 1].x - a[i].x) <= d)
			for (j = i + 2; j <= n; ++j) if (f[i][j]) f[i + 1][j] = true;

		if (f[i][i + 1]) up(r2[i + 1], d);

		if (r1[i] >= 0) {
			l = a[i].x - r1[i], r = a[i].x + r1[i];
			if (a[i + 1].x < l - d) ;
			else if (a[i + 1].x < l) up(r1[i + 1], a[i + 1].x - (l - d));
			else if (a[i + 1].x < r) up(r1[i + 1], d);
			else if (a[i + 1].x <= r + d) up(r1[i + 1], (r + d) - a[i + 1].x);
			for (k = i + 2; k <= n; ++k) {
				t_max = a[i + 1].t - abs(a[i + 1].x - a[k].x);
				if (mindist(l, r, a[k].x) <= t_max - a[i].t) f[i + 1][k] = true;
			}
		}
		if (r2[i] >= 0) {
			l = a[i - 1].x - r2[i], r = a[i - 1].x + r2[i];
			if (a[i + 1].x < l - d) ;
			else if (a[i + 1].x < l) up(r1[i + 1], a[i + 1].x - (l - d));
			else if (a[i + 1].x < r) up(r1[i + 1], d);
			else if (a[i + 1].x <= r + d) up(r1[i + 1], (r + d) - a[i + 1].x);
			for (k = i + 2; k <= n; ++k) {
				t_max = a[i + 1].t - abs(a[i + 1].x - a[k].x);
				if (mindist(l, r, a[k].x) <= t_max - a[i].t) f[i + 1][k] = true;
			}
		}
	}
	cout << (f[n - 1][n] || r1[i] >= 0 || r2[i] >= 0 ? "YES\n" : "NO\n");
	return 0;
}