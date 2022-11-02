#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MOD 1000000007

using namespace std;
typedef long long ll;

template <typename T>
T gcd(T a, T b) {
	if (a < b) swap(a, b);
		while (b != 0) {
			T tmp = b;
			b = a % b;
			a = tmp;
		}
	return a;
}

ll m, d, w;

ll comb2(ll n){
    return ((n*(n-1))/2);
}

void solve(){
    cin >> m >> d >> w;
    int n = min(m, d);
    if(d == 1){
        cout << 0 << endl;
        return;
    }
    ll g = gcd<ll>(d-1, w);
    ll W = w/g;
    ll rem = n%W;
    ll div = n/W;
    ll ans = 0;
    ans += (rem*comb2(div+1));
    ans += ((W-rem)*comb2(div));
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}