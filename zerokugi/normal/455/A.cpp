#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef long long int ll;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)

int n;
main(){
	scanf("%d", &n);
	vector<ll> d(100001);
	REP(i, n) {
		int t;
		scanf("%d", &t);
		d[t] += t;
	}
	vector<ll> dp(2);
	FOR(v, d){
		ll t = dp[0];
		dp[0] = max(dp[0], dp[1]);
		dp[1] = max(dp[1], t + *v);
	}
	cout << dp[1] << endl;
	return 0;
}