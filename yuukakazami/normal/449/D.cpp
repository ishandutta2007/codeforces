#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MOD = int(1e9) + 7;
int cnt[1 << 20] = { };
int pw2[1 << 20];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	pw2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw2[i] = pw2[i - 1] * 2 % MOD;
	}
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 1 << 20; ++j) {
			if (j >> i & 1)
				cnt[j - (1 << i)] += cnt[j];
		}
	}
	int ans = pw2[n];
	for (int i = 1; i < (1 << 20); ++i) {
		int tot = 0;
		for (int j = 0; j < 20; ++j) {
			if (i >> j & 1)
				++tot;
		}
		if (tot % 2 == 1)
			ans += MOD - pw2[cnt[i]];
		else
			ans += pw2[cnt[i]];
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << endl;
	return 0;
}