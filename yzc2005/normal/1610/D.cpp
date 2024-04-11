#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int n, a[200005];
int main() {
	cin >> n;
	vector<int> b;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] & 1) {
			continue;
		}
		b.emplace_back(__builtin_ctz(a[i]));
	}
	int ans = 0;
	for (int i = 1; i <= 30; ++i) {
		vector<int> f{1, 0};
		for (auto x : b) {
			if (x < i) {
				continue;
			}	
			vector<int> g = f;
			if (x == i) {
				for (int i = 0; i < 2; ++i) {
					g[i ^ 1] = (g[i ^ 1] + f[i]) % P; 
				}
			} else {
				for (int i = 0; i < 2; ++i) {
					g[i] = (g[i] + f[i]) % P;
				}
			}
			f = g;
		}
		ans = (ans + f[1]) % P;
	}
	int all = 1;
	for (int t = 0; t < n; ++t) {
		all = all * 2 % P;
	}
	printf("%d\n", (all - 1 - ans + P) % P);
	return 0;
}