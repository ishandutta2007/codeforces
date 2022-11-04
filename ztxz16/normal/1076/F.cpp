#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000005;
int n, k;
int xx[N], yy[N];
int f[N][2];

void dp(int i, int now, int nxt, int x, int y) {
	if (f[i][now] <= k) {
		if (x >= y) {
			long long more = (long long)(y - 1) * (k - 1) + k - 1 - f[i][now];
			if (more + y >= x) {
				f[i + 1][nxt] = 1;
			}
			
			long long sur = (long long)x - (long long)(y - 1) * k - (k - f[i][now]);
			if (sur <= 0) {
				f[i + 1][now] = 1;
			} else if (sur <= k) {
				f[i + 1][now] = min(f[i + 1][now], (int)sur);
			}
		} else {
			long long cost = x * k;
			if (cost >= y) {
				f[i + 1][nxt] = 1;
				f[i + 1][now] = 1;
			} else if (y - cost <= k) {
				f[i + 1][nxt] = min(f[i + 1][nxt], (int)(y - cost));
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &xx[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &yy[i]);
	}
	
	f[0][0] = f[0][1] = 0;
	for (int i = 0; i < n; i++) {
		f[i + 1][0] = f[i + 1][1] = 1e9;
		int x = xx[i + 1], y = yy[i + 1];
		dp(i, 0, 1, x, y);
		dp(i, 1, 0, y, x);
	}
	
	if (f[n][0] <= k || f[n][1] <= k) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}