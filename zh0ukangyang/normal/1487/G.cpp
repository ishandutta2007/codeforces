#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int N = 402, mod = 998244353;
int d1[3] = {0, 1, 25}, d2[4] = {0, 1, 1, 24};
int ans, n, a[N], dp[2][4][4][N][N], now;
int f[2][4][4][N];
int calc1(int x) {
	int res = 0;
	for(int x1 = 1; x1 <= 3; x1 ++) for(int x2 = 1; x2 <= 3; x2++) for(int d = x; d <= n; d++) (res += f[now][x1][x2][d]) %= mod;
	return res;
}
int calc2(int x, int y) {
	int res = 0;
	for(int x1 = 1; x1 <= 3; x1 ++) for(int x2 = 1; x2 <= 3; x2++) 
		for(int d = x; d <= n; d++) for(int p = y; p <= n; p++) (res += dp[now][x1][x2][d][p]) %= mod;
	return res;
}
void Main() { 
	cin >> n;
	for(int i = 1; i <= 26; i++) cin >> a[i];
	ans = 26 * 26;
	for(int i = 3; i <= n; i++) ans = (ll) ans * 25 % mod;
	
	
	f[0][0][0][0] = 1, dp[0][0][0][0][0] = 1;
	for(int d = 1; d <= n; d++) {
		int fl = d / 2 + 2;
		now ^= 1;
		memset(f[now], 0, sizeof(f[now])), memset(dp[now], 0, sizeof(dp[now]));
		for(int i = 0; i <= fl; i++) 
			for(int x1 = 0; x1 <= 2; x1++) for(int x2 = 0; x2 <= 2; x2++) for(int x3 = 1; x3 <= 2; x3++) {
				if(x1 == x3) (f[now][x2][x3][i + (x3 == 1)] += (ll) (d1[x3] - 1) * f[now ^ 1][x1][x2][i] % mod) %= mod;
				else (f[now][x2][x3][i + (x3 == 1)] += (ll) d1[x3] * f[now ^ 1][x1][x2][i] % mod) %= mod;
			}
		for(int i = 0; i <= fl; i++) for(int j = 0; j <= fl; j++) 
			for(int x1 = 0; x1 <= 3; x1++) for(int x2 = 0; x2 <= 3; x2++) for(int x3 = 1; x3 <= 3; x3++) {
				if(x1 == x3) (dp[now][x2][x3][i + (x3 == 1)][j + (x3 == 2)] += (ll) (d2[x3] - 1) * dp[now ^ 1][x1][x2][i][j] % mod) %= mod;
				else (dp[now][x2][x3][i + (x3 == 1)][j + (x3 == 2)] += (ll) d2[x3] * dp[now ^ 1][x1][x2][i][j] % mod) %= mod;
			}
	}
	
	for(int i = 1; i <= 26; i++) (ans += mod - calc1(a[i] + 1)) %= mod;
	for(int i = 1; i <= 26; i++) for(int j = i + 1; j <= 26; j++) (ans += calc2(a[i] + 1, a[j] + 1)) %= mod;
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main();
	return 0;
}