#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

const int N = 540;

int n, K;
bool lit[N];
int G[N][N], head[N][N];

inline bool down(int &x, const int y) {return x > y ? x = y, 1 : 0;}

int main() {
	int i, j, k, l, r, min, max, x, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> K;
	if (n & ~K & 1) return cout << "-1\n", 0;
	memset(G, 63, sizeof G);
	for (i = 0; i <= n; ++i) G[i][i] = 0;
	for (i = 0; i <= n; ++i) {
		min = abs(K - i),
		max = n - abs(K - (n - i));
		for (j = min; j <= max; ++j) if ((i ^ j ^ K ^ 1) & 1) G[i][j] = 1, head[i][j] = j;
	}
	for (k = 0; k <= n; ++k) for (i = 0; i <= n; ++i) for (j = 0; j <= n; ++j)
		if (down(G[i][j], G[i][k] + G[k][j])) head[i][j] = head[i][k];
	assert(G[0][n] <= n);
	for (i = 0; i != n; i = j) {
		j = head[i][n], l = (i - j + K) / 2, r = (j - i + K) / 2,
		cout << '?';
		for (k = 0; k < n; ++k)
			if (lit[k]) {
				if (l) --l, cout << ' ' << k + 1, lit[k] ^= 1;
			} else {
				if (r) --r, cout << ' ' << k + 1, lit[k] ^= 1;
			}
		cout << endl, cin >> x, ans ^= x;
	}
	cout << '!' << ' ' << ans << '\n';
	return 0;
}