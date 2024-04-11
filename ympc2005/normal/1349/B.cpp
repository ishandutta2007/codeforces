#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int T, n, m, a[N];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d%d", &n, &m);
		int cnt = 0;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt += a[i] == m;
		}
		
		if (!cnt) {
			puts("no");
			continue;
		}
		
		if (n == 1) {
			puts("yes");
			continue;
		}
		
		bool ok = 0;
		
		for (int i = 1; i <= n; i++) {
			if (1 < i && a[i] >= m && a[i - 1] >= m) {
				ok = 1;
			}
			
			if (i + 2 <= n && a[i] >= m && a[i + 2] >= m) {
				ok = 1;
			}
		}
		
		printf("%s\n", ok ? "yes" : "no");
	}
}