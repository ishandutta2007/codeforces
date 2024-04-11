#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 205;

int n, d[N][N], ans;

ll a[N];

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		
		if (!a[i]) {
			i--, n--;
			continue;
		}
		
		if (i >= 200) {
			puts("3");
			exit(0);
		}
	}
	
	memset(d, 0x3f, sizeof(d));
	ans = n + 1;
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		d[i][i] = 0;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i]&a[j]) {
				d[i][j] = min(d[i][j], 1);
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if ((a[k]&a[i]) && (a[k]&a[j])) {
					ans = min(ans, d[i][j] + 2);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	printf("%d\n", ans <= n ? ans : -1);
}