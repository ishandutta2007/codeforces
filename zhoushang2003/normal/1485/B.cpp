#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n , q , k;
int a[100010] , b[100010];
ll sum[100010];

int main() {
	ios::sync_with_stdio(false); 
	cin >> n >> q >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int tl = 1 , tr = k;
		if(i != 1) tl = max(tl , a[i - 1]);
		if(i != n) tr = min(tr , a[i + 1]);
		b[i] = max(tr - tl - 2 , 0);
	}
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i];
	while(q--) {
		int l , r;
		cin >> l >> r;
		if(l == r) {
			if(a[l] > k)
				cout << k << endl;
			else
				cout << k - 1 << endl;
			continue;
		}
		if(a[r] > k && a[r - 1] > k) {
			cout << 0 << endl;
			continue;
		}
		if(a[r] > k) {
			cout << k - a[r - 1] << endl;
			continue;
		}
		ll ans = sum[r - 1] - sum[l];
		ans += a[l + 1] - 2 + k - a[r - 1] - 1;
		cout << ans << endl;
	}
	return 0;
}