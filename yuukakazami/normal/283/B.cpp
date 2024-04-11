#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = int(2e5 + 10);
const int LOG = 30;
typedef long long int64;

int n;
int a[MAX_N];
int nxt[MAX_N][LOG]; //at -1 or 0 is an terminal
int64 step[MAX_N][LOG];

int main() {
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 2; i <= n; ++i) {
		int x = i, y = 0;
		y += a[x], x += a[x];
		if (x <= 1 || x > n) {
			nxt[i][0] = x == 1 ? 1 : -1;
			step[i][0] = y;
			continue;
		}
		y += a[x], x -= a[x];
		if (x <= 1 || x > n) {
			nxt[i][0] = x == 1 ? 1 : -1;
			step[i][0] = y;
			continue;
		}
		nxt[i][0] = x;
		step[i][0] = y;
	}

	for (int lg = 1; lg < LOG; ++lg) {
		for (int i = 2; i <= n; ++i) {
			int at = nxt[i][lg - 1];
			if (at == -1 || at == 1) {
				nxt[i][lg] = at;
				step[i][lg] = step[i][lg - 1];
			} else {
				nxt[i][lg] = nxt[at][lg - 1];
				step[i][lg] = step[i][lg - 1] + step[at][lg - 1];
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		int x = 1, y = 0;
		a[1] = i;

		y += a[x], x += a[x];
		if (x <= 0 || x > n) {
			cout << y << endl;
			continue;
		}
		y += a[x], x -= a[x];
		if (x <= 0 || x > n) {
			cout << y << endl;
			continue;
		}
		if (x == 1) {
			cout << -1 << endl;
			continue;
		}
		int at = nxt[x][LOG - 1];
		if (at >= 1 && at <= n) {
			cout << -1 << endl;
			continue;
		}
		cout << y + step[x][LOG - 1] << endl;
	}
	return 0;
}