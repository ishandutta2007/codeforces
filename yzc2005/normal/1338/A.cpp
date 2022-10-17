#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n, a[N];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d", &n);
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if(i == 1 || a[i] >= a[i - 1]) continue;
			int dif = a[i - 1] - a[i];
			for(int k = 30; ~k; --k) if(dif >> k & 1) ans = max(ans, k + 1);
			a[i] = a[i - 1];
		}
		printf("%d\n", ans);
	}
}