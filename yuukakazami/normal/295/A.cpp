#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;
typedef long long int64;

int64 a[MAX_N], add[MAX_N];
int n, m, k;

int l[MAX_N], r[MAX_N], d[MAX_N];
int64 cnt[MAX_N] = { };

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i] >> d[i];
		--l[i], --r[i];
	}
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		cnt[x]++;
		cnt[y + 1]--;
	}

	for (int i = 0; i < m; ++i) {
		cnt[i + 1] += cnt[i];
	}

	for (int i = 0; i < m; ++i) {
		add[l[i]] += 1LL * d[i] * cnt[i];
		add[r[i] + 1] -= 1LL * d[i] * cnt[i];
	}

	for (int i = 0; i < n; ++i) {
		add[i + 1] += add[i];
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i] + add[i] << " ";
	}

	cout << endl;
	return 0;
}