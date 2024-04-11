#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 205;

int n, m, x[N], y[N], f[N][N];

ll s[N][N], g[N][N], lim;

ll calc_(int a, int b, int c) {
	return 1ll*(x[b] - x[a])*(y[c] - y[a]) - 1ll*(x[c] - x[a])*(y[b] - y[a]);
}

void dfs_(int l, int r) {
	if (~f[l][r]) {
		return;
	}
	
	if (s[l][r] < lim) {
		f[l][r] = 0;
		g[l][r] = s[l][r];
		return;
	}
	
	f[l][r] = 1, g[l][r] = 0;
	
	for (int i = l + 1; i < r; i++) {
		dfs_(l, i), dfs_(i, r);
		
		int val = f[l][i] + f[i][r];
		ll sum = s[l][r] - s[l][i] - s[i][r] + g[l][i] + g[i][r];
		
		if (sum >= lim) {
			sum = 0;
			val++;
		}
		
		if (val > f[l][r]) {
			f[l][r] = val;
			g[l][r] = sum;
		} else if (val == f[l][r]) {
			g[l][r] = max(g[l][r], sum);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = i + 2; j <= n; j++) {
			s[i][j] = s[i][j - 1] + calc_(i, j - 1, j);
		}
	}
	
	ll l = 1, r = s[1][n];
	
	while (l < r) {
		lim = (l + r + 1)>>1;
		memset(f, -1, sizeof(f));
		dfs_(1, n);
		
		if (f[1][n] <= m) {
			r = lim - 1;
		} else {
			l = lim;
		}
	}
	
	printf("%lld\n", l);
	return 0;
}