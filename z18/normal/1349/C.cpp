#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define fi first
#define se second
using namespace std;

const int maxn = 1000;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
typedef pair<int, int> P;
int n, m, q, a[maxn + 3][maxn + 3], d[maxn + 3][maxn + 3];

int main() {
	scanf("%d %d %d", &n, &m, &q);
	rep(i, 1, n) rep(j, 1, m) scanf("%1d", &a[i][j]), a[i][j] ^= (i + j) & 1;
	memset(d, -1, sizeof(d));
	queue<P> Q;
	rep(i, 1, n) rep(j, 1, m) {
		rep(k, 0, 3) {
			int x = i + dx[k], y = j + dy[k];
			if (x >= 1 && x <= n && y >= 1 && y <= m && a[i][j] != a[x][y]) {
				d[i][j] = 0, Q.push(P(i, j));
			}
		}
	}
	while (!Q.empty()) {
		P x = Q.front(); Q.pop();
		rep(k, 0, 3) {
			int a = x.fi + dx[k], b = x.se + dy[k];
			if (a >= 1 && a <= n && b >= 1 && b <= m && d[a][b] == -1) {
				d[a][b] = d[x.fi][x.se] + 1;
				Q.push(P(a, b));
			}
		}
	}
	while (q --> 0) {
		int x, y; long long p;
		scanf("%d %d %I64d", &x, &y, &p);
		int res = 0;
		if (d[x][y] == -1 || p <= d[x][y]) {
			res = a[x][y];
		} else {
			res = a[x][y] ^ ((p - d[x][y]) & 1);
		}
		res ^= (x + y) & 1;
		printf("%d\n", res);
	}
	return 0;
}