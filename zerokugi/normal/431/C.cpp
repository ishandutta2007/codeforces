#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, k, d;
ll dp[102][102];
main(){
	while(cin >> n >> k >> d){
		memset(dp, 0, sizeof(dp));
		dp[0][n] = 1;
		ll ans = 0;
		REP(i, n+1)REP(j, n+1){
			for(int t=1;t<=k&&t<=j;t++) (dp[i+1][j-t] += dp[i][j]) %= MOD;
			if(j==0) (ans += dp[i][j]) %= MOD;
		}
		memset(dp, 0, sizeof(dp));
		dp[0][n] = 1;
		REP(i, n+1)REP(j, n+1){
			for(int t=1;t<d&&t<=j;t++) (dp[i+1][j-t] += dp[i][j]) %= MOD;
			if(j==0) (ans -= dp[i][j]) %= MOD;
		}
		cout << (ans+MOD)%MOD << endl;
	}
	return 0;
}