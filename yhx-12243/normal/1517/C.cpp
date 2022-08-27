#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 540;

int n;
int a[N];
int d[N][N];

int main() {
	int i, j, k, r, c;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= n; ++i) {
		r = c = i;
		for (k = 0; k < a[i]; ++k) {
			d[r][c] = a[i];
			if (c > 1 && !d[r][c - 1]) --c;
			else ++r;
		}
	}
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= i; ++j) cout << d[i][j] << (j == i ? '\n' : ' ');
	return 0;
}