// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 1000000007 
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 300003
#define pc(x) putchar_unlocked(x);
#define sz(x) (int)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long dep[(1 << 15) + 10][230][3], n, T, t[mx], g[mx];
long long dp(int mask, int sisa, int tadi){
	if(sisa == 0){
		return 1;
	}
	if(__builtin_popcount(mask) == n)
		return 0;
	long long &ret = dep[mask][sisa][tadi];
	if(ret != -1)
		return ret;
	if(__builtin_popcount(mask) == 0)
		tadi = 100;
	ret = 0;
	for(int i = 0; i < n; i++){
		if(!(mask & (1 << i)) && g[i] != tadi && sisa >= t[i]){
			int nex = mask | (1 << i);
			ret = (ret + dp(nex, sisa - t[i], g[i])) % MOD;
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> T;
	for(int i = 0; i < n; i++)
		g[i] --,
		cin >> t[i] >> g[i];
	reset(dep, -1);
	cout << dp(0, T, 0) << '\n';
}