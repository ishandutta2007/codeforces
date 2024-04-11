#include <bits/stdc++.h>

const int kN = 3e5 + 5;
const int kT = 1e3 + 5;
const int kM = 10;

int a[kN][kM], bud[kT], n, m, t, x = 1, y = 1;

bool Check(int mid) {
	memset(bud, 0, sizeof(bud));
	for(int i = 1; i <= n; ++i) {
		int tmp = 0;
		for(int j = 0; j < m; ++j)
			if(a[i][j] >= mid) tmp |= (1 << j);
		bud[tmp] = i;
	}
	for(int i = 0; i <= t; ++i)
		for(int j = i; j <= t; ++j)
			if((i | j) == t - 1 && bud[i] && bud[j]) {
				x = bud[i], y = bud[j]; return true;
			}
	return false;
}

int main() {
	int l = 0, r = 1e9;
	scanf("%d%d", &n, &m); t = 1 << m;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(Check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d %d", x, y);
	return 0;
}