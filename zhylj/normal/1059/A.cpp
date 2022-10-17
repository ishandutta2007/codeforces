#include<bits/stdc++.h>

using namespace std;

const int mxk = 2e5 + 10;

int n, m, k, b[mxk], c[mxk]; long long ans = 0;

int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) 
		cin >> b[i] >> c[i];
	int cur = 0;
	for(int i = 1; i <= n; ++i) {
		ans += (b[i] - cur) / k;
		cur = b[i] + c[i];
	}
	ans += (m - cur) / k;
	cout << ans << endl;
}