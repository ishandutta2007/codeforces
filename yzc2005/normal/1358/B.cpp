#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n, a[N];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int ans = 0;
		for(int i = n; i; --i) if(a[i] <= i) {
			ans = i;
			break;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}