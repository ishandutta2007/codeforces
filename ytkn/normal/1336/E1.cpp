#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

const ll MOD = 998244353;

class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        if(_v < 0) _v = (_v%MOD)+MOD;
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

    ModInt &operator+=(ll n){
        v = (v+n)%MOD;
        return *this;
    }
    ModInt &operator-=(ll n){
        v = (v-n+MOD)%MOD;
        return *this;
    }
    ModInt &operator*=(ll n){
        v = (v*n+MOD)%MOD;
        return *this;
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

    ModInt &operator+=(ModInt n){
        v = (v+n.v)%MOD;
        return *this;
    }
    ModInt &operator-=(ModInt n){
        v = (v-n.v+MOD)%MOD;
        return *this;
    }
    ModInt &operator*=(ModInt n){
        v = (v*n.v)%MOD;
        return *this;
    }

    bool operator==(ModInt n){
        return v == n.v;
    }
    bool operator!=(ModInt n){
        return v != n.v;
    }
    ModInt &operator=(ll n){
        v = n%MOD;
        return *this;
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
    while (n > 0) {
        if (n&1) ans = ans*a;
        a = a*a;
        n >>= 1;
    }
	return ans;
}

using mint = ModInt;

int64_t msb(int64_t v){
  v = v | (v >>  1);
  v = v | (v >>  2);
  v = v | (v >>  4);
  v = v | (v >>  8);
  v = v | (v >> 16);
  v = v | (v >> 32);
  return v ^ (v >> 1);
}
 
/**
 * thanks to: https://codeforces.com/contest/1101/submission/84060649
 */ 
struct GJ_Xor{
    vector<int64_t> V;
 
    void add(int64_t a){
        for(int64_t v : V) if(msb(v)&a) a ^= v;
        if(a > 0){
            for(int64_t& v : V) if(msb(a)&v) v ^= a;
            V.push_back(a);
            sort(V.rbegin(), V.rend());
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto popcount = [&](ll x){
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(x&(1ll<<i)) ans++;
        }
        return ans;
    };
    GJ_Xor gj;
    for(int i = 0; i < n; i++) gj.add(a[i]);
    vector<int> base_bits;
    vector<bool> is_base_bit(m);
    vector<int> non_base_bits;
    for(auto x: gj.V) {
        for(int i = m-1; i >= 0; i--){
            if(x&(1ll<<i)){
                is_base_bit[i] = true;
                base_bits.push_back(i);
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(!is_base_bit[i]){
            non_base_bits.push_back(i);
        }
    }
    // print_vector(base_bits);
    // print_vector(non_base_bits);
    int nb = base_bits.size();
    int nnb = non_base_bits.size();
    mint pw = pow(mint(2), n-gj.V.size());
    vector<mint> ans(m+1);
    if(nb <= 18){
        for(int s = 0; s < (1<<nb); s++){
            ll x = 0;
            for(int i = 0; i < nb; i++){
                if(s&(1<<i)) x ^= gj.V[i];
            }
            ans[popcount(x)] += pw;
        }
    }else{
        vector<ll> v(nb);
        for(int i = 0; i < nb; i++){
            for(int j = 0; j < nnb; j++){
                ll x = gj.V[i]&(1ll<<non_base_bits[j]);
                v[i] += (x > 0 ? 1ll<<j : 0);
            }
        }
        // print_vector(v);
        auto dp = vec3d(nb+1, nb+1, 1<<nnb, mint(0));
        dp[0][0][0] = 1;
        for(int i = 0; i < nb; i++){
            for(int j = 0; j <= i; j++){
                for(int s = 0; s < (1<<nnb); s++){
                    // i
                    dp[i+1][j+1][s^v[i]] += dp[i][j][s];
                    // i
                    dp[i+1][j][s] += dp[i][j][s];
                }
            }
        }
        for(int j = 0; j <= nb; j++){
            for(int s = 0; s < (1<<nnb); s++){
                int cnt = popcount(s)+j;
                ans[cnt] += pw*dp[nb][j][s];
            }
        }
    }
    print_vector(ans);
}