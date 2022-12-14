#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int l[N], r[N], dp[N], a[N], c[N];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		r[a[i]] = i;
	for(int i=n;i>=1;i--)
		l[a[i]] = i;
	for(int i=n;i>=1;i--) {
		c[a[i]] ++;
		dp[i] = dp[i + 1];
		if(i == l[a[i]]) {
			dp[i] = max(dp[i], c[a[i]] + dp[r[a[i]] + 1]);
		}
		else {
			dp[i] = max(dp[i], c[a[i]]);
		}
	}
	cout << n - dp[1] << endl;
}