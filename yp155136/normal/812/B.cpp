#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 26;
const int MAX_M = 106;

int mp[MAX_N][MAX_M];
int pre[MAX_N][MAX_M];
int mx[MAX_N];
int mn[MAX_N];
int dp[2][MAX_N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while (cin >> n >>m ) {
		memset(pre,0,sizeof(pre));
		int nonempty=0;
		for (int i=1;n>=i;i++) {
			string s;
			cin >> s;
			mn[i] = m+1;
			for (int j=0;m+1>=j;j++) {
				mp[i][j] = (s[j]=='0'?0:1);
				pre[i][j] = pre[i][j-1] + mp[i][j];
				mx[i] = max(mx[i],mp[i][j]*j);
				mn[i] = min(mn[i],(mp[i][j]*j)==0?m+2:j );
			}
			if (pre[i][m+1] != 0 && nonempty==0) {
				nonempty=i;
			}
//			cout<<"mx["<<i<<"] = "<<mx[i]<<" , mn["<<i<<"] = "<<mn[i]<<endl;
//			cout<<"pre["<<i<<"]["<<m+1<<"] = "<<pre[i][m+1]<<endl;
		}
		if (nonempty==0) {
			cout<<0<<endl;
			continue;
		}
		for (int i=n;i>=1;i--) {
			if (i==n) {
				dp[0][i] = (pre[i][m+1]==0?0:2*mx[i]) ;
				dp[1][i] = m+1;
			}
			else {
				dp[0][i] = min(dp[1][i+1] + m+2,dp[0][i+1] + (pre[i][m+1]==0?1:1+2*mx[i]));
				dp[1][i] = min(dp[0][i+1] + m+2,dp[1][i+1] + (pre[i][m+1]==0?1:1+2*(m+1-mn[i])));
			}
			
//			cout<<"dp["<<0<<"]["<<i<<"] = "<<dp[0][i]<<" , dp[1]["<<i<<"] = "<<dp[1][i]<<endl;
		}
		if (nonempty!=n) cout<<min(dp[1][nonempty+1] + 1+1*(m+1-mn[nonempty]),dp[0][nonempty+1] + (1+1*mx[nonempty]))<<endl;
		else cout<<mx[n]<<endl;
	}
}