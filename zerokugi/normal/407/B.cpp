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

const int MOD = 1000000007;

int n;
int p[1002];
ll memo[1002];
main(){
	scanf("%d", &n);
	REP(i, n) scanf("%d", &p[i]);
	memo[0] = 0;
	int ans;
	REP(i, n){
		memo[i+1] = ((memo[i] + memo[i] - memo[p[i]-1] + 2) % MOD + MOD) % MOD;
	}
	cout << memo[n] << endl;
	return 0;
}