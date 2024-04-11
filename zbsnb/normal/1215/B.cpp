#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define int long long
int dp[200010][2];
int a[200010];

signed main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = (a[i] < 0) ? dp[i - 1][1] + 1 : dp[i - 1][0];
		dp[i][1] = (a[i] < 0) ? dp[i - 1][0] : dp[i - 1][1] + 1;
		//cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
		ans1 += dp[i][0];
		ans2 += dp[i][1];
	}
	cout << ans1 << " " << ans2 << endl;
}