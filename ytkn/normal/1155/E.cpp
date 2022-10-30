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

const ll MOD = 1000003;

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

/**
 * ax
 */ 
ModInt calc(const vector<ModInt> &a, ModInt x){
    ModInt cur = 1;
    ModInt ans = 0;
    for(auto b : a){
        ans += b*cur;
        cur *= x;
    }
    return ans;
}

/**
 * f(x_i) = y_i(O(N^2))
 * verified: https://atcoder.jp/contests/abc137/submissions/20140907
 */ 
vector<ModInt> lagrange_interpolation(vector<ModInt> x, vector<ModInt> y){
    assert(x.size() == y.size());
    int n = x.size();
    vector<vector<ModInt>> dp(2, vector<ModInt>(n+1));
    dp[0][0] = x[0]*(-1);
    dp[0][1] = 1;
    for(int i = 1; i < n; i++){
        int cur = i%2, prev = (i+1)%2;
        dp[cur][0] = dp[prev][0]*x[i]*(-1);
        for(int j = 1; j <= i+1; j++){
            dp[cur][j] = dp[prev][j-1]-dp[prev][j]*x[i];
        }
    }
    vector<ModInt> f(n+1);
    for(int i = 0; i <= n; i++) f[i] = dp[(n-1)%2][i];
    vector<ModInt> ans(n);
    for(int i = 0; i < n; i++){
        ModInt prod = 1;
        for(int j = 0; j < n; j++){
            if(i != j) prod *= (x[i]-x[j]);
        }
        // (x-x[i])*q = f
        vector<ModInt> q(n);
        q[n-1] = 1;
        for(int j = n-1; j >= 1; j--){
            q[j-1] = x[i]*q[j]+f[j];
        }
        ModInt coef = y[i]*prod.inv();
        for(int j = 0; j < n; j++) ans[j] += coef*q[j];
    }
    return ans;
}

using mint = ModInt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    auto ask = [&](int x){
        cout << "? " << x << endl;
        int ans; cin >> ans;
        return ans;
    };
    auto verify = [&](int x){
        cout << "! " << x << endl;
    };
    vector<mint> xs, ys;
    for(int x = 0; x <= 10; x++){
        xs.push_back(mint(x));
        ys.push_back(ask(x));
    }
    auto p = lagrange_interpolation(xs, ys);
    for(int x = 0; x < MOD; x++){
        if(calc(p, x).v == 0){
            verify(x);
            return 0;
        }
    }
    verify(-1);
}