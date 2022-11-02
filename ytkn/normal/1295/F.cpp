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

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

ModInt comb(ll n, ll r){
    if(n < r){
        return ModInt(0);
    }else{
        ModInt ans = 1;
        for(int i = 0; i < r; i++){
            ans *= n-i;
            ans *= ModInt(i+1).inv();
        }
        return ans;
    }
}

using mint = ModInt;
mint dp[55][105][55];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<int> v;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i]; r[i]++;
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    auto cp = Compress<int>(v);
    int m = cp.size();
    auto ok = [&](int i, int j){
        assert(j+1 < m);
        int xl = cp.data[j], xr = cp.data[j+1];
        return xl >= l[i] && xr <= r[i];
    };
    vector<int> cnt(n);
    vector<mint> cnt_inv(n);
    for(int i = 0; i < n; i++){
        cnt[i] = r[i]-l[i];
        cnt_inv[i] = mint(cnt[i]).inv();
    }
    for(int j = 0; j < m-1; j++){
        if(ok(0, j)) {
            dp[0][j][1] += cnt_inv[0];
        }
    }
    auto memo = vec2d(m-1, n+1, mint(0));
    for(int j = 0; j < m-1; j++){
        int xl = cp.data[j], xr = cp.data[j+1];
        int cnt = xr-xl;
        for(int k = 0; k <= n; k++){
            memo[j][k] = comb(cnt-1+k, k);
        }
    }
    auto count = [&](int j, int k) -> mint{
        return memo[j][k];
    };
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m-1; j++){
            if(!ok(i-1, j)) continue;
            for(int to = 0; to <= j; to++){
                if(!ok(i, to)) continue;
                for(int k = 0; k <= i; k++){
                    if(j == to){
                        dp[i][to][k+1] += dp[i-1][j][k]*cnt_inv[i];
                    }else{
                        dp[i][to][1] += dp[i-1][j][k]*count(j, k)*cnt_inv[i];
                    }
                }
            }
        }
    }
    mint ans = 0;
    for(int j = 0; j < m-1; j++){
        for(int k = 0; k <= n; k++){
            ans += dp[n-1][j][k]*count(j, k);
        }
    }
    cout << ans << endl;
}