#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

tint modexp(tint b, tint e, tint p) {
	if(e == 0) return 1;
	tint ans = modexp(b, e/2, p);
	ans = (ans*ans)%p;
	if(e % 2) ans = (ans*b) % p;
	return ans;
}

tint inv(tint a, tint p) {
	return modexp(a, p-2, p);
}

vvi dp;
vi fact, ifact, pot2;
tint calcdp(tint n, tint k, tint m) {
	if(k == n) return pot2[k-1];
	if(k == 0) return 0;
	if(k > n) return 0;
	if(dp[n][k] != -1) return dp[n][k];
	tint &ans = dp[n][k];
	ans = 0;
	
	forn(i, k) if(i) {
		tint cant = ((fact[k] * ifact[i])%m * ifact[k-i])%m;
		//if(cant < 0) cout << "TODO MAL" << endl;
		ans += ((pot2[i-1] * cant)%m * calcdp(n-i-1, k-i, m))%m;
		//if(ans < 0) cout << "TODO MAL" << endl;
		ans %= m;
	}
	return ans;
}

int main() {
	tint n, m;
	cin >> n >> m;
	dp = vvi(n+1, vi(n+1, -1));
	fact = vi(n+1, 1);
	ifact = vi(n+1, 1);
	pot2 = vi(n+1, 1);
	forn(i, n+1) if(i) {
		fact[i] = fact[i-1] * i;
		fact[i] %= m;
		ifact[i] = inv(fact[i], m);
		pot2[i] = pot2[i-1] * 2;
		pot2[i] %= m;
	}
	
	tint ans = 0;
	forn(i, n+1) {
		//cout << calcdp(n, i, m) << endl;
		ans += calcdp(n, i, m);
		ans %= m;
	}
	cout << ans << endl;
	
}