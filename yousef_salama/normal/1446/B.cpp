#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	
	vector < vector <int> > dp(n + 1, vector <int> (m + 1));
	for(int i = n; i >= 0; i--)
	for(int j = m; j >= 0; j--){
		if(i == n || j == m)dp[i][j] = 0;
		else{
			dp[i][j] = 0;
			if(a[i] == b[j])dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j + 1]);
			dp[i][j] = max(dp[i][j], -1 + dp[i + 1][j]);
			dp[i][j] = max(dp[i][j], -1 + dp[i][j + 1]);
		}
	}
	
	int res = 0;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		res = max(res, dp[i][j]);
	printf("%d\n", res);
	
	return 0;
}