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

int main()
{
	tint n;
	cin >> n;
	vector<tint> a(n);
	forn(i, n) cin >> a[i];
	vector<tint> count(71,0);
	forn(i, n) count[a[i]]++;
	
	vector<tint> criba(71,1);
	vector<tint> primos;
	forn(i, 71) if(i>=2) if(criba[i]) {
		primos.push_back(i);
		for(int j = 2*i; j<71; j+=i) {
			criba[j] = 0;
		}
	}
	
	tint ps = primos.size();
	vector<tint> mask(71,0);
	forn(i, 71) {
		if(i) {
			tint k = i;
			forn(j, ps) {
				int p = 0;
				while(k%primos[j] == 0) {
					p^=1;
					k/=primos[j];
				}
				mask[i]+= p<<j;
			}
		}
	}
	
	vector<vector<tint> > dp(2, vector<tint>(1<<ps, 0));
	dp[0][0] = 1;
	forn(i, 71) {
		if(i) {
			forn(m, 1<<ps) dp[i%2][m] = 0;
		}
		if(count[i]) {
			tint r = modexp(2, count[i]-1);
			forn(m, 1<<ps) {
				dp[i%2][m] += (dp[(i+1)%2][m]*r)%MOD;
				dp[i%2][m] %= MOD;
				dp[i%2][m^(mask[i])] += (dp[(i+1)%2][m]*r)%MOD;
				dp[i%2][m^(mask[i])] %= MOD;
			}
		} else if(i) {
			forn(m, 1<<ps) {
				dp[i%2][m] += dp[(i+1)%2][m];
				dp[i%2][m] %= MOD;
			}
		}
	}
	
	cout << dp[0][0]-1 << endl;
    return 0;
}