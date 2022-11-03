#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define MOD 998244353  
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 1000003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
long long t, n, a[mx], b[mx], kali[mx];

bool cmp(int x, int y){
	return (double)kali[x] / (double)a[y] < (double)kali[y] / (double)a[x];
}

int main(){
	// cin >> t;
	t = 1;
	while(t --){
		cin >> n;
		long long jaw = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		vector<int> ve;
		for(int i = 1; i <= n; i++){
			kali[i] = 1LL * i * (n - i + 1);
			ve.pb(i);
		}
		sort(ALL(ve), cmp);
		sort(b + 1, b + n + 1);
		reverse(b + 1, b + n + 1);
		long long sum = 0;
		int now = 1;
		for(int i : ve){
			jaw += a[i] * kali[i] % MOD * b[now] % MOD;
			now++;
			jaw %= MOD;
			// debug(b[now]);
			// debug(a[i] * kali[i]);
		}
		cout << jaw << '\n';
	}
}