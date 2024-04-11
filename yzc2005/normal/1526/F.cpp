#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int rng(int l, int r) {
	return l + rnd() % (r - l + 1);
}
int n, p[100005];
int query(int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << "\n";
	int x;
	cin >> x;
	return x;
}
vector<int> pos[100005];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		pos[i].clear();
	int a, b, c;
	while (true) {
		a = rng(1, n), b = rng(1, n), c = rng(1, n);
		while (a == b || b == c || a == c)
			a = rng(1, n), b = rng(1, n), c = rng(1, n);
		int x = query(a, b, c);
		if (x <= (n - 4) / 6) break;
	}
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == a || i == b) continue;
		int x = query(a, b, i);
		pos[x].emplace_back(i);		
		mx = max(mx, x);
	}	
	int p1 = pos[mx][0], p2 = pos[mx - 1][0];
	if (pos[mx - 1].size() > 1u) {
		int x = query(p1, p2, a), y = query(p1, pos[mx - 1][1], a);
		if (x > y) p2 = pos[mx - 1][1];
	}
	p[p1] = 1, p[p2] = 2;
	for (int i = 1; i <= n; ++i) {
		if (i == p1 || i == p2) continue;
		int x = query(i, p1, p2);
		p[i] = x + 2;
	}
	if (p[1] > p[2]) {
		for (int i = 1; i <= n; ++i)
			p[i] = n - p[i] + 1;
	}
	cout << "!";
	for (int i = 1; i <= n; ++i)
		cout << " " << p[i];
	cout << "\n";
	int _____________________________;
	cin >> _____________________________;
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}