#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <bitset>
using namespace std;

int n, m;
long long ans;
const int MOD = int(1e9) + 7;
int cnt[121];

void rec(int i, bitset<120> by, long long w) {
	if (i > m / 2) {
		ans += w;
		return;
	}
	rec(i + 1, by, w);
	if (cnt[i] && !by[i])
		rec(i + 1, by | by >> i | by << (m - i) | by >> (m - i) | by << i, w * cnt[i] % MOD);
}

int main() {
	cin >> n >> m;
	int nF;
	cin >> nF;
	for (int i = 0; i < nF; ++i) {
		int x;
		cin >> x;
		x %= m;
		cnt[min(m - x, x)]++;
	}
	rec(0, bitset<120>(1), 1);
	cout << ans % MOD << endl;
	return 0;
}