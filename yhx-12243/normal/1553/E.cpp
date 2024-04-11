#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 300054;

int n, m, k;
int p[N], q[N];
int a[N];
int tag, used[N];
std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

inline bool check(int sw) {
	int i, j, C = 0; ++tag;
	memcpy(q + 1, p + 1, n << 2), std::rotate(q + 1, q + (sw + 1), q + (n + 1));
	for (i = 1; i <= n; ++i) if (used[i] != tag) {
		for (j = i; used[j] != tag; j = q[j]) used[j] = tag;
		++C;
	}
	return C < n - m;
}

void work() {
	int i, w, x; k = 0;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) cin >> p[i];
	for (w = 0; w < 50; ++w)
		x = gen() % n + 1, a[k++] = (x - p[x] + n) % n;
	std::sort(a, a + k), k = std::unique(a, a + k) - a;
	cout << (k = std::remove_if(a, a + k, check) - a);
	for (i = 0; i < k; ++i) cout << ' ' << a[i];
	cout << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}