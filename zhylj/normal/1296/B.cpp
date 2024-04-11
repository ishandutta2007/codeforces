#include <bits/stdc++.h>

typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int s; ll ans = 0;
		scanf("%d", &s);
		while(s >= 10) {
			ans += s - s % 10;
			s = s / 10 + s % 10;
		}
		printf("%lld\n", ans + s);
	}
	return 0;
}