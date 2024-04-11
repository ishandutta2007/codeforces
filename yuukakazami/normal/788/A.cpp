#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)

const int MAX_N = int(1e5 + 10);
int n;
int a[MAX_N];

typedef long long ll;
const ll INF = 1LL << 60;

ll dp[MAX_N][2];

int main(){
	cin>>n; rep(i,0,n) scanf("%d",a+i);

	rep(i,0,n+1) rep(j,0,2) dp[i][j] = -INF;

	dp[0][0] = 0;

	ll ans = 0;

	rep(i,0,n-1){
		int d = abs(a[i] - a[i+1]);
		rep(j,0,2)
			dp[i+1][j^1] = max(dp[i+1][j^1], dp[i][j] + (j==0?d:-d));
		dp[i+1][1] = max(dp[i+1][1],(ll)d);

	}
	rep(i,0,n) rep(j,0,2) ans = max(ans,dp[i][j]);

	cout<<ans<<endl;

	return 0;
}