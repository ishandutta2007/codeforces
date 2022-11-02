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

int n;
int dp[128][2];
main(){
	string s;
	while(cin >> s){
		int n = s.size();
		REP(i, 128) dp[i][0] = dp[i][1] = 0;
		REP(i, n) dp[s[i]][i&1] = max(dp[s[i]][i&1], dp[s[i]][!(i&1)]+1);
		cout << (*max_element(&dp[0][0], &dp[0][0]+256)) << endl;
	}
	return 0;
}