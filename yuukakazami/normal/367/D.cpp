#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = int(1e5) + 10;
int n, m, d;
int belong[MAX_N];

bool cant[1 << 20];

int cnt[20];

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < m; ++i) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; ++j) {
			int x;
			scanf("%d", &x);
			--x, belong[x] = i;
		}
	}

	int mask = 0;
	for (int i = 0; i < d; ++i) {
		cnt[belong[i]]++;
	}

	for (int i = 0; i < m; ++i) {
		if (cnt[i] > 0)
			mask |= 1 << i;
	}

	cant[mask] = true;

	for (int i = d; i < n; ++i) {
		if (!--cnt[belong[i - d]])
			mask ^= 1 << belong[i - d];
		if (!cnt[belong[i]]++)
			mask ^= 1 << belong[i];
		cant[mask] = true;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < (1 << m); ++j)
			if (j >> i & 1) {
				cant[j] = cant[j] || cant[j - (1 << i)];
			}
	}

	int ans = 0;
	for (int i = 0; i < (1 << m); ++i) {
		if (!cant[i]) {
			int tot = 0;
			for (int j = 0; j < m; ++j) {
				if (i >> j & 1)
					tot++;
			}
			ans = max(ans, tot);
		}
	}

	cout << m - ans << endl;
}