#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, k, b[N], s[N], c[N];
vector<int> a[N];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]), ++s[b[i]];
	for(int i = 1; i <= k; ++i) scanf("%d", &c[i]);
	int ans = 0;
	for(int i = k; i; --i) {
		s[i] += s[i + 1];
		ans = max(ans, (int)ceil(s[i] * 1.0 / c[i]));
	}
	printf("%d\n", ans);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; ++i) a[i % ans].push_back(b[i]);
	for(int i = 0; i < ans; ++i) {
		printf("%d ", a[i].size());
		for(auto v : a[i]) printf("%d ", v);
		puts("");
	}
}