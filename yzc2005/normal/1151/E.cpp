#include <bits/stdc++.h>
using namespace std;

int n, a[100005], cnt[100005];
long long ans;

inline long long cal(int x, int y) {
	if(x > y) swap(x, y);
	return 1ll * x * (n - y + 1);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++cnt[a[i]];
	for(int i = 1; i <= n; ++i) ans += 1ll * cnt[i] * i * (n - i + 1);
	for(int i = 2; i <= n; ++i) ans -= cal(a[i - 1], a[i]);
	cout << ans; 
}