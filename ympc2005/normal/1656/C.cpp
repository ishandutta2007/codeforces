#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int T, n, a[N];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		int ans = 1;
		
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				for (int j = 1; j < n; j++) {
					if (a[j] + 1 == a[j + 1]) {
						ans = 0;
					}
				}
			}
		}
		
		printf("%s\n", ans ? "Yes" : "No");
	}
}