#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 200054;

int n, m, q, ans;
int a[N];

inline void add(int u, int v) {
	if (u > v) std::swap(u, v);
	if (++a[u] == 1) --ans;
}

inline void del(int u, int v) {
	if (u > v) std::swap(u, v);
	if (!--a[u]) ++ans;
}

int main() {
	int i, op, u, v;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m, ans = n;
	for (i = 0; i < m; ++i) cin >> u >> v, add(u, v);
	for (cin >> q; q; --q)
		switch (cin >> op, op) {
			case 1: cin >> u >> v, add(u, v); break;
			case 2: cin >> u >> v, del(u, v); break;
			case 3: cout << ans << '\n';
		}
	return 0;
}