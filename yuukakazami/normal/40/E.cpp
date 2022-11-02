#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <functional>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
int map[1001][1001];

int main() {
	int n, m, k, p;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int r, c, v;
		cin >> r >> c >> v;
		--r, --c;
		map[r][c] = v;
	}
	cin >> p;
	if (n % 2 != m % 2) {
		cout << 0 << endl;
		return 0;
	}
	if (n < m) {
		static int tmp[1001][1001];
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				tmp[c][r] = map[r][c];
			}
		}
		memcpy(map, tmp, sizeof map);
		swap(n, m);
	}
	//now n>=m
	//there must be a empty row
	for (int r = 0; r < n; ++r) {
		int by = accumulate(map[r], map[r] + m, 1, multiplies<int>());
		if (by == 1) {
			cout << 0 << endl;
			return 0;
		}
	}
	int emptyRowId = -1;
	for (int r = 0; r < n; ++r) {
		if (count(map[r], map[r] + m, 0) == m) {
			emptyRowId = r;
			break;
		}
	}

	int ans = 1;
	for (int r = 0; r < n; ++r) {
		if (r == emptyRowId)
			continue;
		int num = count(map[r], map[r] + m, 0);
		for (int k = 0; k < num - 1; ++k) {
			ans = ans * 2 % p;
		}
	}
	cout << ans << endl;
	return 0;
}