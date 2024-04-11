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
string s;
main(){
	while(cin >> s){
		ll dp[2][3]={0};
		dp[0][0] = 1;
		REP(i, s.size()){
			dp[(i&1)^1][0] = dp[(i&1)^1][1] = dp[(i&1)^1][2] = 0;
			if(s[i] == '*') dp[(i&1)^1][2] = dp[i&1][1] + dp[i&1][2] + !i;
			if(s[i] == '2') dp[(i&1)^1][1] = dp[i&1][2];
			if(s[i] == '1'){
				if(!i) dp[(i&1)^1][1] = 1;
				else{
					dp[(i&1)^1][1] = dp[i&1][0];
					dp[(i&1)^1][0] = dp[i&1][2];
				}
			}
			if(s[i] == '0') dp[(i&1)^1][0] = dp[i&1][0];
			if(s[i] == '?'){
				if(!i) dp[(i&1)^1][0] = dp[(i&1)^1][1] = dp[(i&1)^1][2] = 1;
				else{
					dp[(i&1)^1][2] = dp[i&1][1] + dp[i&1][2];
					dp[(i&1)^1][1] = dp[i&1][0] + dp[i&1][2];
					dp[(i&1)^1][0] = dp[i&1][0] + dp[i&1][2];
				}
			}
			dp[(i&1)^1][0] %= 1000000007;
			dp[(i&1)^1][1] %= 1000000007;
			dp[(i&1)^1][2] %= 1000000007;
		}
		printf("%I64d\n", (dp[s.size()&1][0] + dp[s.size()&1][2])%1000000007 );
	}
	return 0;
}