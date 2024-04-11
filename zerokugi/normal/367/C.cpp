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

ll n,m;

ll check(ll n){
	if(n<3) return n-1;
	if(n%2) return n*(n-1)/2;
	return n*(n-1)/2 + n/2 - 1;
}

main(){
	cin >> n >> m;
	vector<int> cost;
	REP(i, m){
		int x, y;
		cin >> x >> y;
		cost.push_back(y);
	}
	sort(cost.rbegin(), cost.rend());
	int i;
	ll ans = 0;
	for(i=0;check(i+1)<n && i < m;i++){
		ans += cost[i];
	}
	cout << ans << endl;
	return 0;
}