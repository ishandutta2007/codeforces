#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n, p[2100], id[2100];
int query(int i, int j) {
	cout << "? " << i << " " << j << "\n";
	int x;
	cin >> x;
	return x;
}
int rng(int l, int r) {
	return l + rnd() % (r - l + 1); 
}
int get(int x) {
	int res = 2047;
	for (int tt = 0; tt < 20; ++tt) {
		int y = rng(1, n);
		do y = rng(1, n);
			while (y == x);
		res &= query(x, y);
	}
	return res;
}
int main() {
	cin >> n;
	iota(id + 1, id + n + 1, 1);
	shuffle(id + 1, id + n + 1, rnd);
	memset(p, -1, sizeof p);
	int cur = id[1];
	p[cur] = get(cur);
	for (int o = 2; o <= n; ++o) {
		if (query(cur, id[o]) == p[cur]) 
			cur = id[o], p[cur] = get(cur);
		if (p[cur] == 0) break;
	}
	for (int i = 1; i <= n; ++i)
		if (p[i] == -1) p[i] = query(cur, i);
	cout << "! ";
	for (int i = 1; i <= n; ++i)
		cout << p[i] << " \n"[i == n];
	return 0;
}