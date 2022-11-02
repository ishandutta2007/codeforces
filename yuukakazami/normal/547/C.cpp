#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_VALUE = 500000 + 10;
const int MAX_N = 200000 + 10;

vector<int> ps[MAX_VALUE];

int cnt[MAX_VALUE], n, q;
int a[MAX_N];

int query(int x) {
	vector<int> p = ps[x];
	int cnt = p.size();

	int ans = 0;

	for (int i = 0; i < (1 << cnt); ++i) {
		int v = 1;
		int sign = 1;
		for (int k = 0; k < cnt; ++k) {
			if (i >> k & 1)
				v *= p[k], sign *= -1;
		}
		ans += sign * ::cnt[v];
	}

	return ans;
}

void add(int x, int w) {
	vector<int> p = ps[x];
	int cnt = p.size();

	for (int i = 0; i < (1 << cnt); ++i) {
		int v = 1;
		for (int k = 0; k < cnt; ++k) {
			if (i >> k & 1)
				v *= p[k];
		}
		::cnt[v] += w;
	}
}

int main() {
	for (int i = 2; i < MAX_VALUE; ++i) {
		if (ps[i].empty()) {
			for (int j = i; j < MAX_VALUE; j += i)
				ps[j].push_back(i);
		}
	}

	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	static bool on[MAX_N] = { };
	long long ans = 0;

	while (q--) {
		int i;
		scanf("%d", &i), --i;
		if (!on[i]) {
			ans += query(a[i]);
			add(a[i], 1);
			on[i] = true;
		} else {
			add(a[i], -1);
			ans -= query(a[i]);
			on[i] = false;
		}
		printf("%I64d\n", ans);
//		cout << ans << endl;
	}
}