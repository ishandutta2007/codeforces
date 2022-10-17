#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, x, a[N];
void solve() {
	scanf("%d%d", &n, &x);
	multiset<int> s; 
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), s.insert(a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	while (!s.empty()) {
		int v = *s.begin(), tmp = min((long long) 2e9, 1ll * v * x);
		s.erase(s.begin());
		if (s.count(tmp)) {
			s.erase(s.find(tmp));
			continue;
		}
		++ans;
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) 
		solve(); 
	return 0;
}