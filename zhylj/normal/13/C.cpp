#include <bits/stdc++.h>

typedef long long ll;

std::priority_queue<int> h;

int main() {
	ll ans = 0;
	int n; scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x); h.push(x);
		if(x != h.top()) { ans += h.top() - x; h.push(x); h.pop(); }
	}
	printf("%lld", ans);
	return 0;
}