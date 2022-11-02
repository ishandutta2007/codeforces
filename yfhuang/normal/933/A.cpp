#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

const int maxn = 1e4;
int a[maxn];
int dp[maxn][3];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	a[0] = 1;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < i;j++){
			if(a[j] == 1 && a[i] == 1){
				dp[i][0] = max(dp[i][0],dp[j][0] + 1);
				dp[i][2] = max(dp[i][2],dp[j][2] + 1);
				dp[i][1] = max(dp[i][1],max(dp[j][0],dp[j][1]) + 1);
			}
			if(a[j] == 2 && a[i] == 2){
				dp[i][0] = max(dp[i][0],dp[j][0] + 1);
				dp[i][2] = max(dp[i][2],max(dp[j][1],dp[j][2]) + 1);
				dp[i][1] = max(dp[i][1],dp[j][1] + 1);
			}	
			if(a[j] == 1 && a[i] == 2){
				dp[i][0] = max(dp[i][0],dp[j][0] + 1);
				dp[i][2] = max(dp[i][2],max(dp[j][1],dp[j][2]) + 1);
				dp[i][1] = max(dp[i][1],dp[j][0] + 1);
			}
			if(a[j] == 2 && a[i] == 1){
				dp[i][2] = max(dp[i][2],dp[j][1] + 1);
				dp[i][1] = max(dp[i][1],max(dp[j][0],dp[j][1]) + 1);
			}
		}
		ans = max(ans,dp[i][0]);
		ans = max(ans,dp[i][1]);
		ans = max(ans,dp[i][2]);
	}
	cout << ans << endl;
	return 0;
}