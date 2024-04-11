#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n, m;
const int MAX_N = 1000, MAX_M = 5000 + 10, INF = ~0U >> 2;
int a[MAX_M], b[MAX_M];
int d[MAX_N];
bool vL[MAX_N], vR[MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
		--a[i], --b[i];
	}

	fill(d, d + n, INF);
	d[0] = 0;
	vL[0] = true;
	vR[n - 1] = true;
	for (int it = 0; it < n; ++it) {
		bool updated = false;
		for (int i = 0; i < m; ++i) {
			int a = ::a[i], b = ::b[i];
			if (vL[a] && !vL[b])
				vL[b] = true, updated = true;
			if (vR[b] && !vR[a])
				vR[a] = true, updated = true;
		}
		if (!updated) {
			break;
		}
	}
	bool ok = false;
	for (int it = 0; it < n; ++it) {
		bool updated = false;
		for (int i = 0; i < m; ++i) {
			int a = ::a[i], b = ::b[i];
			if (vL[a] && vR[a] && vL[b] && vR[b]) {
				if (d[a] + 2 < d[b]) {
					d[b] = d[a] + 2;
					updated = true;
				}
				if (d[a] + 1 > d[b]) {
					d[a] = d[b] - 1;
					updated = true;
				}
			}
		}
		if (!updated) {
			ok = true;
			break;
		}
	}

	if (ok) {
		cout << "Yes" << endl;
		for (int i = 0; i < m; ++i) {
			int x = d[b[i]] - d[a[i]];
			if (x < 1 || x > 2)
				x = 1;
			cout << x << endl;
		}
	} else {
		cout << "No" << endl;
	}
	return 0;
}