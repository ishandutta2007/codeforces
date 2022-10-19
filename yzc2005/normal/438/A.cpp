#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, a[1005];
long long ans;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	while(m--) cin >> u >> v, ans += min(a[u], a[v]);
	cout << ans;
}