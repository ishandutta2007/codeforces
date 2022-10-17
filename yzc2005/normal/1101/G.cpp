#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, a[N], d[30];

inline void ins(int x) {
	for(int i = 29; ~i; --i) if(x >> i & 1) {
		if(!d[i]) {
			d[i] = x;
			break;
		}
		x ^= d[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i], a[i] ^= a[i - 1];
	if(!a[n]) cout << -1, exit(0);
	for(int i = 1; i <= n; ++i) ins(a[i]);
	int ans = 0;
	for(int i = 0; i < 30; ++i) if(d[i]) ++ans;
	cout << ans;
}