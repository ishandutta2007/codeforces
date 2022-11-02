#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, a[N], b[N];

int main() {
	int T;
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		
		bool ok = 1;
		
		for (int i = 1; i <= n; i++) {
			if (b[i] - a[i] < 0 || b[i] - a[i] > 1) {
				ok = 0;
			}
		}
		
		printf("%s\n", ok ? "YES" : "NO");
	}
}