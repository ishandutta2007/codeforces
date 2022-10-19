#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 0; i < 30; ++i) {
			int cnt = 0;
			for (int j = 1; j <= n; ++j)
				cnt += (a[j] >> i & 1);
			ans = __gcd(ans, cnt); 
		}
		if (!ans) {
			for (int i = 1; i <= n; ++i)
				printf("%d ", i);
		} else {
			for (int i = 1; i <= ans; ++i)
				if (ans % i == 0) printf("%d ", i);
			puts("");
		}
	}
	return 0;
}