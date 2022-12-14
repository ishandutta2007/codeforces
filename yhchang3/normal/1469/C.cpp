#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		vector<int> h(n + 1);
		for(int i=1;i<=n;i++) {
			cin >> h[i];
		}
		bool ok = true;
		int l = h[1], r = h[1];
		for(int i=2;i<n;i++) {
			l -= k - 1;
			r += k - 1;
			l = max(l, h[i]);
			r = min(r, h[i] + k - 1);
			if(l > r) ok = false;
		}
		l -= k - 1;
		r += k - 1;
		if(h[n] < l || h[n] > r)
			ok = false;
		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}