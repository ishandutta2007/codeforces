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

mint sub_solve(int n, const vector<int> &l, const vector<int> &r, const vector<int> &x){
    vector<int> imos(n+2);
    int m = l.size();
    vector<int> mx(n+1, 0);
    for(int i = 0; i < m; i++){
        if(x[i] == 1){
            imos[l[i]]++;
            imos[r[i]+1]--;
        }else{
            chmax(mx[r[i]], l[i]);
        }
    }
    for(int i = 0; i <= n; i++) imos[i+1] += imos[i];
    vector<mint> dp(n+1);
    vector<mint> dp_cumsum(n+2);
    auto sect_sum = [&](int l, int r){
        return dp_cumsum[r]-dp_cumsum[l];
    };
    dp[0] = 1;
    dp_cumsum[1] = 1;
    int cur_mx = 0;
    for(int i = 1; i <= n; i++){
        if(imos[i] == 0) {
            dp[i] = sect_sum(cur_mx, i);
        }
        chmax(cur_mx, mx[i]);
        dp_cumsum[i+1] = dp_cumsum[i]+dp[i];
    }
    return sect_sum(cur_mx, n+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k, m; cin >> n >> k >> m;
    vector<int> l(m), r(m), x(m);
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i] >> x[i]; l[i]; r[i];
    }
    mint ans = 1;
    for(int i = 0; i < k; i++){
        vector<int> v(m);
        for(int j = 0; j < m; j++){
            v[j] = (x[j]&(1<<i)) > 0 ? 1 : 0;
        }
        ans *= sub_solve(n, l, r, v);
    }
    cout << ans << endl;
}