#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}	
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int ans = -1;
	vector<int> p;
	for (int msk = 0; msk < 1 << n; ++msk) {
		int res = 0;
		vector<int> coef(m);
		for (int i = 0; i < n; ++i) {
			if (msk >> i & 1) {
				res -= x[i];
				for (int j = 0; j < m; ++j) {
					if (s[i][j] == '1') {
						++coef[j];
					}
				}
			} else {
				res += x[i];
				for (int j = 0; j < m; ++j) {
					if (s[i][j] == '1') {
						--coef[j];
					}
				}
			}
		}
		vector<int> id(m), rev(m);
		iota(id.begin(), id.end(), 0);
		sort(id.begin(), id.end(), [&](int i, int j) {
			return coef[i] < coef[j];	
		});
		for (int i = 0; i < m; ++i) {
			res += coef[id[i]] * (i + 1);
			rev[id[i]] = i;
		}
		if (res > ans) {
			ans = res;
			p = rev;
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << p[i] + 1 << " \n"[i == m - 1];
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}