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
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

const ll INF = 1LL<<61;

class DP{
public:
	int x, k, mi, t;
	
	DP(){}
	
	bool operator< (const DP &opp) const {
		return k<opp.k;
	}
};

int n, m;
ll b;

ll dp[1<<20];

main(){
	cin >> n >> m >> b;
	vector<DP> q(n);
	REP(i, n){
		cin >> q[i].x >> q[i].k >> q[i].mi;
		q[i].t = 0;
		REP(j, q[i].mi){
			int tt;
			cin >> tt;
			q[i].t |= 1 << (tt-1);
		}
	}
	sort(q.begin(), q.end());
	ll ans = INF;
	REP(i, 1<<m) dp[i] = INF;
	dp[0] = 0;
	REP(i, n){
		for(int j =  (1<<m)-1;j>=0;j--){
			if(dp[j]!=INF) dp[j|q[i].t] = min(dp[j|q[i].t], dp[j] + q[i].x);
		}
		ans = min(ans, dp[(1<<m)-1] + q[i].k * b);
	}
	cout << (ans==INF ? -1 : ans) << endl;
	return 0;
}