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

const ll MOD = 1000000007;

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

#define N_MAX 402
ModInt inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=1;fac[1]=1;
    finv[0]=1;finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=ModInt(MOD)-inv[MOD%i]*(MOD/i);
        fac[i]=fac[i-1]*(ll) i;
        finv[i]=finv[i-1]*inv[i];
    }
}

int N;
using mint = ModInt;
mint dp[405][205][205];
bool ok[405][205][205];

mint cmb[405][205];
bool ok_cb[405][205];

void init_comb(){
    for(int n = N; n >= N-404 && n >= 0; n--){
        mint x = 1, y = 1;
        // debug_value(n)
        for(int r = 0; r <= 204 && r <= n; r++){
            cmb[N-n][r] = x*y;
            ok_cb[N-n][r] = true;
            // cout << n << ' ' << r << ' ' << x*y << endl;
            x *= n-r;
            y *= inv[r+1];
        }
    }
}

mint comb(int n, int r){
    if(r == 0) return mint(1);
    if(r == n) return mint(1);
    if(n < r){
        return mint(0);
    }
    if(ok_cb[N-n][r]) return cmb[N-n][r];
    assert(false);
}

mint solve(int rem, int k, int sz){
    // cout << N-rem << endl;
    if(sz == 0) mint(0);
    if(sz == 1) {
        if(k == 0) return mint(1);
        return mint(0);
    }
    if(k == 0) return mint(1);
    if(rem <= 1) {
        if(k == 0) return mint(1);
        return mint(0);
    }
    if(ok[N-rem][k][sz]) return dp[N-rem][k][sz];
    mint ans = 0;
    mint cb = 1;
    for(int i = 0; i*(sz-1) <= k && i*sz <= rem; i++){
        // szi
        if(i > 0) cb *= comb(rem-(i-1)*sz, sz)*fac[sz-1];
        ans += cb*finv[i]*solve(rem-i*sz, k-i*(sz-1), sz-1);
    }
    ok[N-rem][k][sz] = true;
    dp[N-rem][k][sz] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int k; cin >> N >> k;
    init();
    init_comb();
    vector<mint> ans(k+1);
    for(int i = 0; i <= k; i++){
        ans[i] = solve(N, i, i+1);
        if(i >= 2) ans[i] += ans[i-2];
    }
    for(int i = 1; i <= k; i++) cout << ans[i] << ' ';
    cout << endl;
}