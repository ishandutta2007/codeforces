#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;


template <typename T>
vector<T> prime_facs(T N) {
	vector<T> ans;
	for (ll i = 2; i * i <= N; i++) {
		if (N % i == 0) {
		ans.push_back(i);
		while (N % i == 0) {
			N /= i;
		}
		}
	}
	if (N != 1) ans.push_back(N);
	return ans;
}


void solve(){
    ll p, q; cin >> p >> q;
    if(p%q != 0){
        cout << p << endl;
        return;
    }
    auto v = prime_facs<ll>(q);
    ll m = 2e18;
    for(ll x : v){
        int cp = 0;
        ll cur = p;
        while(cur%x == 0){
            cur /= x;
            cp++;
        }
        int cq = 0;
        cur = q;
        while(cur%x == 0){
            cur /= x;
            cq++;
        }
        ll s = 1;
        for(int i = 0; i < (cp-(cq-1)); i++){
            s *= x;
        }
        m = min(s, m);
    }
    cout << p/m << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}