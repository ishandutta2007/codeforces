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



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a[3], b, c, d, ans = 0;
	cin >> a[0] >> a[1] >> a[2] >> d;
	sort(a, a + 3);
	if(abs(a[0] - a[1]) < d)
		ans += d - abs(a[0] - a[1]);
	if(abs(a[1] - a[2]) < d)
		ans += d - abs(a[1] - a[2]);
	cout << ans << '\n';
}