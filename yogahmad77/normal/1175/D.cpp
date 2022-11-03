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

long long t, n, a[mx], k, pref[mx];



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// cin >> t;
	t = 1;
	while(t --){
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		long long sum = 0;
		pref[n] = 0;
		for(int i = n - 1; i >= 0; i--)
			pref[i] = pref[i + 1] + a[i];
		sum = pref[0];
		// debug(sum);
		sort(pref + 1, pref + n);
		reverse(pref + 1, pref + n);
		for(int i = 1; i < k; i++)
			sum += pref[i];
		cout << sum << '\n';
	}
}