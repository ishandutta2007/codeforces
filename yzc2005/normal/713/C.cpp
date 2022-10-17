#include <bits/stdc++.h>
using namespace std;
int n, a[3005];
int main() {
	scanf("%d", &n);
	long long offset = 0;
	priority_queue<int> pq;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += n - i;
		offset += a[i];
		pq.emplace(a[i]);
		pq.emplace(a[i]);
		while ((int) pq.size() > i)
			pq.pop();
	}
	long long ans = 0;
	while (!pq.empty())
		ans -= pq.top(), pq.pop();
	ans += offset;
	printf("%lld\n", ans);
	return 0;
}