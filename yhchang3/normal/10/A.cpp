#include<bits/stdc++.h>
using namespace std;

int l[110], r[110];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, p[3], t[2];
	cin >> n >> p[0] >> p[1] >> p[2] >> t[0] >> t[1];
	for(int i=1;i<=n;i++)
		cin >> l[i] >> r[i];
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(i != 1) {
			int diff = l[i] - r[i - 1];
			if(diff > t[0])
				ans += p[0] * t[0], diff -= t[0];
			else
				ans += p[0] * diff, diff = 0;
			if(diff > t[1])
				ans += p[1] * t[1], diff -= t[1];
			else
				ans += p[1] * diff, diff = 0;
			ans += p[2] * diff;
		}
		ans += (r[i] - l[i]) * p[0];
	}
	cout << ans << endl;
}