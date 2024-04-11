#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

tint modexp(tint b, tint e) {
	if(e == 0) return 1;
	tint ans = modexp(b, e/2);
	ans = (ans*ans)%MOD;
	if(e%2) ans = (ans*b)%MOD;
	return ans;
}

tint inv(tint a) {
	return modexp(a, MOD-2);
}

tint calcdp(tint as, tint abs, tint k, tint pbab, vector<vector<tint>>& dp) {
	tint paab = (MOD+1-pbab)%MOD;
	if(abs >= k) return abs;
	if(dp[as][abs] != -1) return dp[as][abs];
	dp[as][abs] = 0;
	dp[as][abs] += paab*calcdp(as+1, abs, k, pbab, dp);
	dp[as][abs] %= MOD;
	dp[as][abs] += pbab*calcdp(as, abs+as, k, pbab, dp);
	dp[as][abs] %= MOD;
	return dp[as][abs];
	
}

int main()
{
	tint k, pa, pb;
	cin >> k >> pa >> pb;
	
	vector<vector<tint>> dp(k+1, vector<tint>(k+1, -1));
	
	tint pbab = (pb*inv(pa+pb))%MOD;
	forn(i, k+1) {
		dp[k][i] = (MOD + k + i - 1 + inv(pbab))%MOD;
	}
	
	cout << calcdp(1, 0, k, pbab, dp) << endl;
	
	return 0;
}