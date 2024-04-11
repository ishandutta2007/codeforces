#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long int64;
int64 comb[60][60];

int main() {
	for (int i = 0; i < 60; ++i) {
		for (int j = 0; j <= i; ++j) {
			comb[i][j] = (!i || !j) ? 1 : comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
	int64 n, t;
	cin >> n >> t;
	if ((t & (t - 1)) != 0) {
		cout << 0 << endl;
		return 0;
	}
	int pw = 0;
	while ((1LL << pw) != t)
		++pw;
	++pw;

	//2..n+1
	int ls[60], L = 0;
	n += 2;
	//<n
	while (n > 0) {
		ls[L++] = n % 2;
		n /= 2;
	}
	reverse(ls, ls + L);
	int cnt = 0;
	int64 ans = 0;
	for (int i = 0; i < L; ++i) {
		if (ls[i] > 0) {
			if (pw >= cnt)
				ans += comb[L - 1 - i][pw - cnt];
		}
		cnt += ls[i];
	}
	//skip 1
	if (pw == 1)
		--ans;
	cout << ans << endl;
	return 0;
}