#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;
int n;
const int MAX_N = 5000 + 10;
const int MAX_OUT = 200000 + 10;
pair<pair<int, int> ,int> a[MAX_OUT];

int main() {
	cin >> n;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int k, a, x, y, m;
		cin >> k >> a >> x >> y >> m;
		int p = -1, t = 0;
		for (int j = 0; j < k; ++j) {
			if (a < p) {
				++t;
			}
			if (cnt < MAX_OUT)
				::a[cnt++] = make_pair(make_pair(t, a), i + 1);
			p = a;
			a = (1LL * a * x + y) % m;
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
	if (cnt <= 200000) {
		sort(a, a + cnt);
		for (int i = 0; i < cnt; ++i) {
			printf("%d %d\n", a[i].first.second, a[i].second);
		}
	}
	return 0;
}