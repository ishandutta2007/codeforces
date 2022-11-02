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

ll MOD = 1000000007;

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

template<typename T>
class CumsumGrid{
    public:
    CumsumGrid(vector<vector<T>> v): v(v){
        n = v.size();
        m = v[0].size();
        v_cumsum = vector<vector<T>>(n+1, vector<T>(m+1, T(0)));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                v_cumsum[i+1][j+1] = v_cumsum[i+1][j]+v_cumsum[i][j+1]-v_cumsum[i][j]+v[i][j];
            }
        }
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int il, int ir, int jl, int jr){
        if(ir <= il) return T(0);
        if(jr <= jl) return T(0);
        if(ir > n) ir = n;
        if(jr > m) jr = m;
        if(il < 0) il = 0;
        if(jl < 0) jl = 0;
        return v_cumsum[ir][jr]-v_cumsum[ir][jl]-v_cumsum[il][jr]+v_cumsum[il][jl];
    }
    private:
    int n, m;
    vector<vector<T>> v;
    vector<vector<T>> v_cumsum;
};

const int N_MAX = 1000;
ModInt cb[1005][1005], fac[1005];

void init(){
    cb[0][0] = 1;
    fac[0] = 1;
    for(int n = 1; n <= N_MAX; n++){
        cb[n][0] = 1;
        fac[n] = fac[n-1]*n;
        for(int r = 1; r <= n; r++){
            cb[n][r] = cb[n-1][r]+cb[n-1][r-1];
        }
    }
}

ModInt comb(ll n, ll r){
    if(n < r){
        return ModInt(0);
    }else{
        return cb[n][r];
    }
}

using mint = ModInt;

int tri(int x){
    return (x*(x-1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n >> MOD;
    init();
    auto count = vec2d(n+1, tri(n)+1, mint(0));
    auto dp = vec3d(n+1, n, tri(n)+1, mint(0));
    count[0][0] = 1;
    for(int len = 1; len <= n; len++){
        for(int i = 0; i < len; i++){
            int tmp_inv = i;
            for(int pre_inv = 0; pre_inv <= tri(len-1); pre_inv++){
                int inv = pre_inv+tmp_inv;
                count[len][inv] += count[len-1][pre_inv];
                dp[len][i][inv] += count[len-1][pre_inv];
            }
        }
    }
    mint ans = 0;
    for(int i = 0; i < n; i++){
        // p[i] != q[i]
        // p[i] < q[i]
        int len = n-i;
        auto grid_cumsum = CumsumGrid<mint>(dp[len]);
        for(int pi = 0; pi < len; pi++){
            for(int pinv = 0; pinv <= tri(len); pinv++){
                ans += grid_cumsum.sum(pi+1, len, 0, pinv)*dp[len][pi][pinv]*comb(n, len)*fac[i];
            }
        }
    }
    cout << ans << endl;
}