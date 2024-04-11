#include <bits/stdc++.h>
using namespace std;
int n, a[500005]; 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	long long ans = accumulate(a + 1, a + n + 1, 0ll);
	int prev = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int l = 1, r; l <= n; l = r + 1) {
		int val = a[l], cnt = 1;
		for (r = l; r < n && a[r + 1] == a[l]; ++r, ++cnt);
		int num = min(prev - 2 * int(pq.size()), cnt);
		vector<int> v(num, val);
		int rest = min(prev, cnt) - num;
		for (int t = 1; t <= rest; t += 2) {
			int cur = pq.top();
			pq.pop();
			if (cur < val) {
				v.emplace_back(val);
				if (t != rest) v.emplace_back(val);
			} else {
				v.emplace_back(cur);
				if (t != rest && val * 2 - cur > 0) v.emplace_back(val * 2 - cur);
			}
		}
		prev += cnt;
		for (auto x : v)
			pq.emplace(x);
	}	
	while (!pq.empty())
		ans -= pq.top(), pq.pop();
	printf("%lld\n", ans);
	return 0;
}