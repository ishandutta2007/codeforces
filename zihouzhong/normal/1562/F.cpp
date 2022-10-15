#include <bits/stdc++.h>
using namespace std;

const int maxn = 200015;
int T, n, id[maxn];
bool pr[maxn];
long long a[maxn];
mt19937 rnd(time(0));

int main() {
	ios::sync_with_stdio(0);
	fill(pr + 2, pr + maxn, 1);
	for (int i = 2; i < maxn; i++) if (pr[i]) {
		for (int j = i + i; j < maxn; j += i) pr[j] = 0;
	}
	cin >> T;
	auto ask = [&](int i, int j) {
		cout << "? " << i << " " << j << endl;
		long long x; cin >> x;
		return x;
	};
	while (T--) {
		cin >> n;
		fill(a + 1, a + n + 1, 0);
		if (1LL * n * (n - 1) / 2 <= n + 5000) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					long long x = ask(i, j);
					a[i] = __gcd(x, a[i]), a[j] = __gcd(x, a[j]);
				}
			}
			if (n == 3 && a[1] % 2 == 0 && a[2] % 2 == 0 && a[3] % 2 == 0) {
				*max_element(a + 1, a + n + 1) /= 2;
			}
		} else {
			iota(id + 1, id + n + 1, 1);
			shuffle(id + 1, id + n + 1, rnd);
			int pos = 0;
			for (int i = 1; i <= min(200, n); i++) {
				int x = id[i];
				for (int j = 1; j <= 10; j++) {
					int y = rnd() % n + 1;
					while (x == y) y = rnd() % n + 1;
					a[x] = __gcd(a[x], ask(x, y));
				}
				if (pr[a[x]] && (!pos || a[x] > a[pos])) pos = x;
			}
			for (int i = 1; i <= n; i++) {
				if (i ^ pos) a[i] = ask(i, pos) / a[pos];
			}
		}
		cout << "!" << endl;
		for (int i = 1; i <= n; i++) cout << " " << a[i];
		cout << endl;
	}
	return 0;
}