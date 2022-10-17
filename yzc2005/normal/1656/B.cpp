#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], k;
void solve() {
	scanf("%d%d", &n, &k);
	map<int, int> mp;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		if (mp.count(a[i] + k) || mp.count(a[i] - k)) 
		return void(puts("YES"));
		mp[a[i]] = 1;
	}
	puts("NO");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}