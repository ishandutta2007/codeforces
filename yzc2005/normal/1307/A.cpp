#include <bits/stdc++.h>
using namespace std;

int t, n, d, ans, x;

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d", &n, &d);
		scanf("%d", &ans);
		for(int i = 1; i < n; ++i) {
			scanf("%d", &x);
			if(x * i < d) ans += x, d -= x * i;
			else {
				ans += d / i;
				for(int j = i + 1; j < n; ++j) scanf("%d", &x);
				break;
			}  
		}
		printf("%d\n", ans);
	}
}