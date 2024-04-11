#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int N_MAX = 100;

ll D;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll inv_(ll n){
    if(n == 1) return 1;
    else return MOD-inv_(MOD%n)*(MOD/n)%MOD;
}

ll comb(ll n, ll r){
  ll ans;
  if(n < r){
      ans = 0;
  }else{
      ans = (fac[n]*finv[r])%MOD;
      ans = (ans*finv[n-r])%MOD;
      ans = (ans+MOD)%MOD;
  }
  return ans;
}

vector<ll> prime_facs(){
    ll D_ = D;
    vector<ll> ans;
    for(ll i = 2; i*i <= D_; i++){
        if(D%i == 0) {
            ans.push_back(i);
            while(D%i == 0){
                D /= i;
            }
        }
    }
    if(D != 1) ans.push_back(D);
    return ans;
}

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

vector<ll> facs;

ll path(ll u, ll v){
    if(u < v) swap(u, v);
    ll w = u/v;
    ll ans = 1;
    int sum = 0;
    for(ll f : facs){
        int cnt = 0;
        ll tmp = f;
        while(w%tmp == 0){
            cnt++;
            tmp *= f;
        }
        sum += cnt;
    }
    for(ll f : facs){
        int cnt = 0;
        ll tmp = f;
        while(w%tmp == 0){
            cnt++;
            tmp *= f;
        }
        ans *= comb(sum, cnt);
        ans %= MOD;
        sum -= cnt;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> D;
    int q;
    cin >> q;
    init();
    facs = prime_facs();
    for(int i = 0; i < q; i++){
        ll u, v;
        cin >> u >> v;
        ll g = gcd<ll>(u, v);
        ll ans = path(g, u);
        ans *= path(g, v);
        ans %= MOD;
        cout << ans << endl;
    }
}