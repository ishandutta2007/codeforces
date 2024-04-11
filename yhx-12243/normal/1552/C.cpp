#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 254;

int n, m, K;
pr a[N];
int b[N];
bool w[N];

inline bool I(const pr &A, const pr &B) {
	if (A.first < B.first && B.second < A.second) return false;
	if (B.first < A.first && A.second < B.second) return false;
	return A.first < B.second && B.first < A.second;
}

void work() {
	int i, j, u, v, ans = 0;
	cin >> n >> K, m = 0;
	memset(w, false, sizeof w);
	for (i = 0; i < K; ++i) cin >> u >> v, a[i] = std::minmax(u, v), w[u] = w[v] = true;
	for (i = 1; i <= 2 * n; ++i) if (!w[i]) b[m++] = i;
	for (i = 0, j = m / 2; j < m; ++i, ++j) a[K + i] = std::minmax(b[i], b[j]);
	for (i = 0; i < n; ++i) for (j = i + 1; j < n; ++j) ans += I(a[i], a[j]);
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}