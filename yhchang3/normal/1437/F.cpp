#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5001;
const int mod = 998244353;
void upd(int &x,int y){
	x += y;
	if(x >= mod)
		x -= mod;
}

int dp[MAXN][MAXN];
int pre[MAXN][MAXN];
int a[MAXN];
int cnt[MAXN];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	{
		int c = 0;
		for(int i=1;i<=n;i++){
			while(a[c+1] * 2 <= a[i])
				c ++;
			cnt[i] = c;	
		}
	}
	for(int j=1;j<=n;j++)
		dp[1][j] = 1, pre[1][j] = pre[1][j-1], upd(pre[1][j], dp[1][j]);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[j] - (i - 2) > 0)
				upd(dp[i][j], (long long int) dp[i-1][j] * (cnt[j] - (i - 2)) % mod);
			upd(dp[i][j], pre[i-1][cnt[j]]);
			pre[i][j] = pre[i][j-1];
			upd(pre[i][j], dp[i][j]);
		}
	}
	cout << dp[n][n] << endl;
}