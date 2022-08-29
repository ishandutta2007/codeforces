#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, x, a[N], dp[N][8];
void Main () {
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	cin >> n ;
	L(i, 1, n) cin >> a[i];
	cin >> x;
	L(i, 1, n) {
		L(j, 0, 7) {
			int dc = j & 3;
			L(o, 0, 1) 
				dp[i][j] = max(dp[i][j], dp[i - 1][(dc << 1) | o] + (j >> 2 & 1));
			if(dp[i][j] >= 0 && j == 7 && a[i] + a[i - 1] + a[i - 2] < x * 3) 
				dp[i][j] = -1e9;
			if(dp[i][j] >= 0 && (j & 6) == 6 && a[i] + a[i - 1] < x * 2) 
				dp[i][j] = -1e9;
		}
	}
	int ret = 0;
	L(i, 0, 7) ret = max(ret, dp[n][i]);
	cout << ret << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}