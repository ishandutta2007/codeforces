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
#define mx 500003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, q, l, r, P[21][mx];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	memset(P, -1, sizeof P);
	vector<pair<int, int>> ini;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		ini.pb({l, r});
	}
	sort(ALL(ini));
	int di = -1, maks = -1;
	for(int i = 0; i <= 5e5; i++){
		while(di + 1 < sz(ini) && ini[di + 1].f <= i){
			di++;
			maks = max(maks, ini[di].s);
		}
		P[0][i] = maks;
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= 5e5; i++){
			if(P[j - 1][i] == -1)
				continue;
			P[j][i] = P[j - 1][P[j - 1][i]];
		}
	}
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		int ans = 0;
		// debug(P[19][l]);
		if(P[19][l] < r){
			cout << -1 << '\n';
			continue;
		}
		for(int j = 19; j >= 0; j--){
			if(P[j][l] < r){
				l = P[j][l];
				ans += 1 << j;
				// debug(ans);
				// debug(l);
			}
		}
		ans ++;
		cout << ans << '\n';
	}
}