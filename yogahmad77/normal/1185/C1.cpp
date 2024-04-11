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
#define mx 100003
#define pc(x) putchar_unlocked(x);
#define sz(x) (int)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long n, m, x, cnt[mx];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long tot = 0;
	for(int i = 1; i <= n; i++){
		cin >> x;
		// debug(tot);
		// debug(x);
		if(tot + x <= m)
			cout << 0 << ' ';
		else{
			long long kurang = 0, to = 0;
			for(int i = 100; i >= 1; i--){
				if(tot + x - kurang - 1LL * cnt[i] * i <= m){
					long long lo = 0, hi = cnt[i], mid, ans = hi;
					while(lo <= hi){
						mid = (lo + hi) >> 1;
						if(tot + x - kurang - 1LL * mid * i <= m){
							hi = mid - 1;
							ans = mid;
						}
						else lo = mid + 1;
					}
					// debug(ans + tot);
					// debug(ans);
					cout << ans + to << ' ';
					break;
				}
				else kurang += 1LL * i * cnt[i], to += cnt[i];
			}
		}
		cnt[x] ++;
		tot += x;
	}
}