#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, lim = 400, M = N*lim;

int n, a[N], b[M*2 + N], ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = -lim; i <= lim; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, ++b[M + a[j] - j*i]);
		}
		
		for (int j = 1; j <= n; j++) {
			b[M + a[j] - j*i] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= lim && i + j <= n; j++) {
			int d = a[i + j] - a[i];
			
			if (d%j) {
				continue;
			}
			
			d /= j;
			b[d + N]++;
			ans = max(ans, b[d + N] + 1);
		}
		
		for (int j = 1; j <= lim && i + j - 1 <= n; j++) {
			int d = a[i + j] - a[i];
			
			if (d%j) {
				continue;
			}
			
			d /= j;
			b[d + N] = 0;
		}
	}
	
	printf("%d\n", n - ans);
}