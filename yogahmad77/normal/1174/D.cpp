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
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int n, a[mx], k, x;
int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin >> k >> x;
	int XOR = 0;
	int now = 1;
	vector<int> ve;
	while(1){
		if(now >= 1 << k)
			break;
		// debug(now);
		if((now ^ x) < now){
			now ++;
			continue;
		}
		int bil = now ^ XOR;
		ve.pb(bil);
		XOR ^= bil;
		now ++;
	}
	// for(int i = 0; i < sz(ve); i++){
	// 	int X = 0;
	// 	for(int j = i ; j < sz(ve); j++){
	// 		X ^= ve[j];
	// 		if(X == 0 || X == x){
	// 			// cout << i << ' ' << j << endl;
	// 			// debug(X);
	// 		}
	// 	}
	// }
	cout << sz(ve) << endl;
	for(int i : ve)
		cout << i << ' ';
}