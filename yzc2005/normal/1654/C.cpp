#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
void solve() {
	scanf("%d", &n);
	long long sum = 0;
	multiset<int> s;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), sum += a[i], s.insert(a[i]);
	priority_queue<long long> pq;
	pq.push(sum);
	int ans = 0, cnt = 0;
	while (cnt <= n - 1 && !pq.empty()) {
		long long x = pq.top();
		pq.pop();
		if (s.count(x)) {
			++ans;
			s.erase(s.find(x));
		} else {
			pq.push(x / 2);
			pq.push((x + 1) / 2);
			++cnt;
		}
	}
	puts((cnt == n - 1 && ans == n) ? "YES" : "NO");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}