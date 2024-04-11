#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
const int N = 51;
int n, m, f[N + 3][N + 3], g[N + 3][N + 3], inv[N + 3];
int main() {
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= N; ++i)
		inv[i] = 1ull * inv[P % i] * (P - P / i) % P;
	f[0][1] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int x = 0; x < i; ++x) {
			int y = i - 1 - x;
			for (int fx = 1; fx <= N; ++fx) {
				int vx = f[x][fx];
				if (!vx) continue;
				for (int fy = 1; fy <= N; ++fy) {
					int vy = f[y][fy];
					if (!vy) continue;
					int f = min(fx, fy);
					g[i][f] = (g[i][f] + 1ull * vx * vy) % P;
				}
			}
		}
		for (int gf = 1; gf <= N; ++gf) {
			if (!g[i][gf]) continue;
			for (int x = N; x >= i; --x) {
				for (int y = N; y >= gf; --y) {
					int cnt = g[i][gf], val = 1, ce = i, cf = gf;
					for (int j = 1; ce <= x && cf <= y; ++j, ce += i, cf += gf) {
						val = 1ull * val * cnt % P * inv[j] % P;
						if (f[x - ce][y - cf]) f[x][y] = (f[x][y] + 1ull * f[x - ce][y - cf] * val) % P;
						cnt = (cnt + 1) % P;
					}
				}
			}
		}
	}
	cin >> n >> m;
	cout << f[n][m] << "\n";
	return 0;
}