#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l, int r) {
	return l + rnd() % (r - l + 1);
}
const int N = 1e5 + 5;
int n, m, a[N];
unordered_set<int> s, t;
int norm(int x) {
	if (x >= m) x -= m;
	if (x < 0) x += m;
	return x;
}
void check(int x, int y) {
	int d = norm(y - x);
	bool v1 = s.count(norm(x - d));
	bool v2 = s.count(norm(y + d));
	for (int t = 0; t < n - 2; ++t) {
		if (v1) {
			x = norm(x - d);			
			v1 = s.count(norm(x - d));
		} else if (v2) {
			y = norm(y + d);
			v2 = s.count(norm(y + d));
		} else {
			return;
		}
	}
	cout << x << " " << d << "\n";
	exit(0);
}
void check(int d) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (!s.count(norm(a[i] - d))) ++cnt;
	if (cnt > 1) return;
	for (int i = 1; i <= n; ++i)	
		if (!s.count(norm(a[i] - d))) cout << a[i] << " " << d << "\n", exit(0);
}
int main() {
	cin >> m >> n;
	double st = clock();
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		s.insert(a[i]);
	if (n == 1 || n == m) {
		cout << a[1] << " 1" << "\n";
		return 0;
	}
	if (n == m - 1) {
		for (int i = 0; i < m; ++i)
			if (!s.count(i)) cout << norm(i + 1) << " 1" << "\n", exit(0);		
	}
	if (m - n <= 1000) {
		vector<int> b;
		for (int i = 0; i < m; ++i)
			if (!s.count(i)) b.emplace_back(i), t.insert(i);
		shuffle(b.begin(), b.end(), rnd);
		int l = int(b.size());
		for (int t1 = 0; t1 < 2; ++t1) {
			shuffle(b.begin() + 1, b.end(), rnd);
			for (int j = 1; j < l; ++j) {
				int x = b[0], y = b[j];
				int d = norm(y - x);
				bool v1 = t.count(norm(x - d));
				bool v2 = t.count(norm(y + d));
				int t2 = 0;
				while (t2 < l - 2) {
					if (v1) {
						x = norm(x - d);			
						v1 = t.count(norm(x - d));
					} else if (v2) {
						y = norm(y + d);
						v2 = t.count(norm(y + d));
					} else {
						break;
					}
					++t2;
				}
				if (t2 == l - 2) check(d);
			}
			swap(b[0], b[1]);
		} 
	} else {
		shuffle(a + 1, a + n + 1, rnd);
		for (int t = 0; t < 2 && clock() - st < 2000; ++t) {
			shuffle(a + 2, a + n + 1, rnd);
			for (int i = 2; i <= n && clock() - st < 2000; ++i)
				check(a[1], a[i]);
			swap(a[1], a[rng(2, n)]);
		}
	}
	cout << "-1" << "\n";
	return 0;
}