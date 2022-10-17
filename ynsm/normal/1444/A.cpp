#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int main()
{
	int t;
	cin >> t;
	while(t--){
		ll p, q;
		cin >> p >> q;
		if(p % q){
			cout << p << endl;
			continue;
		}
		ll g = __gcd(p, q);
		bool fl = 0;
		ll ans = 1;
		for(ll i = 2; i * i <= g; i++)
			if(g % i == 0){
				ll y = p;
				while(y % q == 0 && y % i == 0)
					y /= i;
				if(p % y == 0 && y % q)
                	ans = max(ans, y);
				while(g % i == 0)
					g /= i;
			}
		if(g > 1){
			ll y = p;
			while(y % q == 0 && y % g == 0)
				y /= g;
			if(p % y == 0 && y % q)
       	       	ans = max(ans, y);
		}
		cout << ans << endl;
	}
}