#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        if(_v >= MOD) _v %= MOD;
        v = _v;
    }
    ModInt operator+(ll n){
        return ModInt((v+n)%MOD);
    }
    ModInt operator-(ll n){
        return ModInt((v-n+MOD)%MOD);
    }
    ModInt operator*(ll n){
        if(n >= MOD) n %= MOD;
        return ModInt((v*n)%MOD);
    }
    ModInt operator/(ll n){
        return ModInt((ModInt(n).inv()*v).v%MOD);
    }

    void operator+=(ll n){
        v = (v+n)%MOD;
    }
    void operator-=(ll n){
        v = (v-n+MOD)%MOD;
    }
    void operator*=(ll n){
        v = (v*n+MOD)%MOD;
    }
    
    
    ModInt operator+(ModInt n){
        return ModInt((v+n.v)%MOD);
    }
    ModInt operator-(ModInt n){
        return ModInt((v-n.v+MOD)%MOD);
    }
    ModInt operator*(ModInt n){
        return ModInt((v*n.v)%MOD);
    }
    ModInt operator/(ModInt n){
        return ModInt((n.inv()*v).v%MOD);
    }

    void operator+=(ModInt n){
        v = (v+n.v)%MOD;
    }
    void operator-=(ModInt n){
        v = (v-n.v+MOD)%MOD;
    }
    void operator*=(ModInt n){
        v = (v*n.v)%MOD;
    }

    void operator=(ModInt n){
        v = n.v;
    }
    bool operator==(ModInt n){
        return v == n.v;
    }
    bool operator!=(ModInt n){
        return v != n.v;
    }
    void operator=(ll n){
        v = n%MOD;
    }

    ModInt inv(){
        if(v == 1) return ModInt(1);
        else return ModInt(MOD-ModInt(MOD%v).inv().v*(MOD/v)%MOD);
    }
};

ostream& operator<<(ostream& os, const ModInt& m){
    os << m.v;
    return os;
}

istream & operator >> (istream &in,  ModInt &m){
    in >> m.v;
    return in;
}


ModInt pow(ModInt a, ll n) {
	ll ans = 1;
	ll tmp = a.v;
	for (int i = 0; i <= 60; i++) {
		ll m = (ll)1 << i;
		if (m & n) {
		ans *= tmp;
        if(ans >= MOD) ans %= MOD;
		}
		tmp *= tmp;
        if(tmp >= MOD) tmp %= MOD;
	}
	return ModInt(ans);
}

ll INF = 1e18;

ll power(ll x, ll r){
    if(x == 1) return 1;
    ll ans = 1;
    if(r > 63) return INF;
    while(r--){
        if(ans > INF/x) return INF;
        ans *= x;
    }
    return ans;
}

using mint = ModInt;

void solve(){
    ll n, p; cin >> n >> p;
    vector<ll> k(n);
    map<ll, ll> mp;
    mp[0] = 0;
    auto add = [&](ll x){
        if(mp.count(x)) mp[x]++;
        else mp[x] = 1;
    };
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        add(k[i]);
    }
    mint ans = 0;
    auto ptr = mp.end(); ptr--;
    ll cur = 0;
    ll th = 1e12;
    ll pre = -1;
    while(true){
        auto [k, x] = *ptr;
        if(pre != -1) {
            ll pw = power(p, pre-k);
            if(cur != 0 && pw >= th/cur){
                ans += pow(mint(p), pre)*cur - pow(mint(p), k)*th;
                cur = th;
            }else{
                cur *= pw;
            }
        }
        
        if(cur >= x){
            cur -= x;
        }else{
            if(cur%2 == x%2) cur = 0;
            else cur = 1;
        }
        if(ptr == mp.begin()){
            ans += cur;
            break;
        }
        pre = k;
        ptr--;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}