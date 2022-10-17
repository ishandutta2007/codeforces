#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n; 
pair<int, int> a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].first);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].second);
	sort(a + 1, a + n + 1);
	priority_queue<int> s;
	long long sum = 0, ans = 0;
	for (int i = 1, ptr = 1; !s.empty() || ptr <= n; ++i) {
		if (s.empty()) i = max(i, a[ptr].first);
		while (ptr <= n && a[ptr].first == i) 
			s.push(a[ptr].second), sum += a[ptr++].second; 
		sum -= s.top();
		s.pop();
		ans += sum; 
	}
	printf("%lld\n", ans);
	return 0;
}