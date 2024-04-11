#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, a[N];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		sort(a + 1, a + n + 1);
		printf("%d\n", a[n] + a[n - 1]);
	}
}