#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX_N = 20;
int a[1 << MAX_N], n, m;
int flip[MAX_N + 1];

typedef long long int64;
int64 sum[MAX_N + 1][2]; //orig,rev

void rec(int l, int r, int level) { //[l,r]
	if (l + 1 == r) {
		return;
	}
	int m = (l + r) >> 1;
	rec(l, m, level - 1);
	rec(m, r, level - 1);
	int64 cnt = 0;
	//orig
	for (int i = m; i < r; ++i) {
		cnt += lower_bound(a + l, a + m, a[i]) - (a + l);
	}
	sum[level][1] += cnt;
	cnt = 0;
	for (int i = l; i < m; ++i) {
		cnt += lower_bound(a + m, a + r, a[i]) - (a + m);
	}
	sum[level][0] += cnt;
	inplace_merge(a + l, a + m, a + r);
}

int main() {
	cin >> n;
	for (int i = 0; i < (1 << n); ++i) {
		scanf("%d", a + i);
	}
	rec(0, (1 << n), n);
//	for (int i = 0; i <= n; ++i) {
//		cout << sum[i][0] << " " << sum[i][1] << endl;
//	}
	cin >> m;
	while (m--) {
		int q;
		scanf("%d", &q);
		while (q >= 0) {
			flip[q] ^= 1;
			--q;
		}
		int64 ans = 0;
		for (int i = n; i >= 0; --i) {
			ans += sum[i][flip[i]];
		}
		cout << ans << endl;
	}
}