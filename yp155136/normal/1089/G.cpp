#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[8];

ll check(int st,ll len) {
	ll ret=0;
	int n = 7;
	while (st != 0 && len > 0) {
		ret += a[st];
		st = (st+1)%n;
		--len;
	}
	if (!len) return ret;
	ll tot=a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6];
	ret += (len/7)*tot;
	len %= 7;
	while (len--) {
		ret += a[st];
		++st;
	}
	return ret;
}

void solve() {
	ll k;
	cin >> k;
	int n=7;
	for (int i=0;i<n;++i) {
		cin >> a[i];
	}
	ll ans = 3984759834755ll;
	for (int start=0;start<n;++start) {
		ll L=0,R=8*k + 7122;
		while (R-L != 1) {
			ll mid = (L+R)>>1;
			if (check(start,mid) >= k) R = mid;
			else L = mid;
		}
		ans = min(ans,R);
	}
	cout << ans << endl;
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}