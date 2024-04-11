#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 3054;

int n, K;
int len[N];
ll sum[N], a[N][N];
ll ans, f[14][N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

inline void update(int w, ll c, ll *f) {for (int i = K; i >= w; --i) up(f[i], f[i - w] + c);}

void solve(int L, int R, int d = 0) {
	int i, M = (L + R) / 2;
	if (L + 1 == R) {
		for (i = 0; i <= len[L]; ++i) up(ans, a[L][i] + f[d][K - i]);
		return;
	}
	memcpy(f[d + 1], f[d], (K + 1) << 3);
	for (i = M; i < R; ++i) update(len[i], sum[i], f[d + 1]);
	solve(L, M, d + 1);
	memcpy(f[d + 1], f[d], (K + 1) << 3);
	for (i = L; i < M; ++i) update(len[i], sum[i], f[d + 1]);
	solve(M, R, d + 1);
}

int main() {
	int i, j;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> K;
	for (i = 0; i < n; ++i) {
		cin >> len[i];
		for (j = 1; j <= len[i] && j <= K; ++j) cin >> a[i][j];
		for (; j <= len[i]; ++j) cin >> a[i][K + 1];
		down(len[i], K);
		for (j = 1; j <= len[i]; ++j) a[i][j] += a[i][j - 1];
		sum[i] = a[i][len[i]];
	}
	solve(0, n), cout << ans << '\n';
	return 0;
}