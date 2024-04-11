#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, L;
long long a[N << 1], b[N << 2];

inline bool check(int mid) {
	int lp = 1, rp = 0, mn = 1e9;
	for(int i = 1; i <= n << 1; ++i) {
		while(lp <= n << 2 && b[lp] < a[i] - mid) ++lp;
		while(rp < n << 2 && b[rp + 1] <= a[i] + mid) ++rp;
		mn = min(mn, i - lp);
		if(i - rp > mn) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> L;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1); 
	for(int i = 1; i <= n; ++i) a[i] += L, a[i + n] = a[i] + L;
	for(int i = 1; i <= 3 * n; ++i) b[i + n] = b[i] + L;
	int l = 0, r = L - 1, ans;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}