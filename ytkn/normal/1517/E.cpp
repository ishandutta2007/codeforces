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

const ll MOD = 998244353;

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
    assert(n >= 0);
	ModInt ans = 1;
	ModInt tmp = a;
	for (int i = 0; i <= 60; i++) {
		ll m = (ll)1 << i;
		if (m & n) {
		ans *= tmp;
		}
		tmp *= tmp;
	}
	return ans;
}

#define N_MAX 200002
ModInt inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=1;fac[1]=1;
    finv[0]=1;finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=(ModInt)MOD-inv[MOD%i]*(MOD/i);
        fac[i]=fac[i-1]*(ll) i;
        finv[i]=finv[i-1]*inv[i];
    }
}

ModInt comb(ll n, ll r){
    if(n < r){
        return ModInt(0);
    }else{
        return fac[n]*finv[r]*finv[n-r];
    }
}

ModInt h(ll n, ll r){
    if(n == 0 && r == 0) return ModInt(1);
    return comb(n+r-1, n-1);
}

template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        if(i < 0) return 0;
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

using mint = ModInt;

void solve(){
    int n; cin >> n;
    vector<ll> a(n), a_cumsum(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) a_cumsum[i+1] = a_cumsum[i]+a[i];
    auto sect_sum = [&](int l, int r){ // sum(a[l, r))
        return a_cumsum[r]-a_cumsum[l];
    };
    set<ll> st;

    st.insert(0);

    mint ans = 0;
    ll sum_e = 0, sum_o = 0;
    for(int l = 0; l < n; l++){ // i: P
        if(l%2 == 0){
            if(l == 0) sum_e = 0;
            else sum_e += (a[l-1]-a[l-2]);
        }else{
            if(l == 1) sum_o = a[0];
            else sum_o += (a[l-1]-a[l-2]);
        }
        ll x = (l%2 == 0 ? sum_e : sum_o);

        // 
        st.insert(sect_sum(0, l)-x); // CCC..C
        st.insert(-a[0]+sect_sum(1, l)-x); // PCC..C

        // 
        st.insert(sect_sum(l, n)-x); // PP...P
        st.insert(sect_sum(l, n-1)-a[n-1]-x); // PP...PC
    }

    map<ll, int> compress = [&](){
        int cnt = 1;
        map<ll, int> ans;
        for(ll x : st){
            ans[x] = cnt;
            cnt++;
        }
        return ans;
    }();

    int m = compress.size();
    bit<ll> bt_e(m), bt_o(m);

    sum_e = 0, sum_o = 0;
    for(int l = 0; l < n; l++){ // i: P
        if(l%2 == 0){
            if(l == 0) sum_e = 0;
            else sum_e += (a[l-1]-a[l-2]);
        }else{
            if(l == 1) sum_o = a[0];
            else sum_o += (a[l-1]-a[l-2]);
        }

        // 
        if(l == 0){
            bt_e.add(compress[0], 1);
        }else if(l == 1){
            bt_o.add(compress[0], 1);
        }else if(l%2 == 0){
            ll s = sect_sum(0, l)-sum_e; // CCC..C
            bt_e.add(compress[s], 1);
            s = -a[0]+sect_sum(1, l)-sum_e; // PCC..C
            if(l != 2) bt_e.add(compress[s], 1);
        }else{
            ll s = sect_sum(0, l)-sum_o; // CCC..C
            bt_o.add(compress[s], 1);
            s = -a[0]+sect_sum(1, l)-sum_o; // PCC..C
            bt_o.add(compress[s], 1);
        }
        mint tmp = ans;
        if(l%2 == 0){
            ll s = sect_sum(l, n)-sum_e; // PP...P
            ans += bt_e.sum(compress[s]-1);
            s = sect_sum(l, n-1)-a[n-1]-sum_e; // PP...PC
            if(l != n-1) ans += bt_e.sum(compress[s]-1);
        }else{
            ll s = sect_sum(l, n)-sum_o; // PP...P
            ans += bt_o.sum(compress[s]-1);
            s = sect_sum(l, n-1)-a[n-1]-sum_o; // PP...PC
            if(l != n-1) ans += bt_o.sum(compress[s]-1);
        }
        // cout << ans-tmp << ' ';
    }
    // cout << endl;

    // PP..PCC..C
    for(int l = 1; l <= n-2; l++){
        if(sect_sum(0, l) > sect_sum(l, n)) ans+=1;
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