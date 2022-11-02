#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define int long long

int pir[21][21];
int a[400010];
int cnt[21];

int dp[2000010];

signed main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 20; j++) {
			pir[j][a[i]] += cnt[j];
		}
		cnt[a[i]]++;
	}
	
	/*
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			cout << pir[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	for (int p = 1; p <= 20; p++) {
		for (int i = 0; i < (1 << 20); i++) {
			
			int cnt = 0;
			for (int j = 0; j < 20; j++) {
				if (i&(1 << j))cnt++;
			}
			if (cnt != p)continue;
			//cout << i << " " << p << endl;
			
			dp[i] = 1e18;
			for (int j = 0; j < 20; j++) {
				if ((i&(1 << j)) == 0)continue;
				ll tmp = 0;
				for (int k = 0; k < 20; k++) {
					if (j == k || ((i&(1 << k)) == 0))continue;
					tmp += pir[k + 1][j + 1];
				}
				dp[i] = min(dp[i], dp[i ^ (1 << j)] + tmp);
			}
		}
	}
	cout << dp[(1 << 20) - 1] << endl;
}