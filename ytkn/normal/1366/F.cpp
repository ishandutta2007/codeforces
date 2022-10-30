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
const ll inf = 1e18;

mint sum_arithmetic_progression(mint l, mint r, mint n){
    return (l+r)*mint(n)/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, q; cin >> n >> m >> q;
    vector<int> u(m), v(m);
    vector<ll> w(m);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i]; u[i]--; v[i]--;
    }
    int N = 2*n+2*m;
    auto dp = vec2d(N+1, n, -inf);
    dp[0][0] = 0;
    vector<ll> ans(N+1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < m; j++){
            chmax(dp[i+1][v[j]], dp[i][u[j]]+w[j]);
            chmax(dp[i+1][u[j]], dp[i][v[j]]+w[j]);
        }
    }
    for(int i = 0; i <= N; i++) ans[i] = *max_element(dp[i].begin(), dp[i].end());
    if(q <= N){
        mint sum = 0;
        for(int i = 1; i <= q; i++) sum += ans[i];
        cout << sum << endl;
        return 0;
    }
    mint sum = 0;
    for(int i = 1; i <= N; i++) sum += ans[i];
    vector<ll> a(m);
    for(int i = 0; i < m; i++){
        chmax(a[i], dp[N][u[i]]);
        chmax(a[i], dp[N][v[i]]);
    }
    auto get_elm = [&](int i, ll x){
        return a[i]+w[i]*(x-N);
    };
    auto get_max_idx = [&](ll x){
        int max_idx = 0;
        ll mx = 0;
        for(int i = 0; i < m; i++){
            if(chmax(mx, get_elm(i, x))) max_idx = i;
        }
        return max_idx;
    };
    int max_idx = get_max_idx(N+1);
    auto ok = [&](int i, ll x)->bool{
        for(int j = 0; j < m; j++){
            if(get_elm(j, x) > get_elm(i, x)) return false;
        }
        return true;
    };
    ll cur_time = N+1;
    while(true){
        if(ok(max_idx, q)){
            ll l = get_elm(max_idx, cur_time);
            ll r = get_elm(max_idx, q);
            sum += sum_arithmetic_progression(mint(l), mint(r), mint(q-cur_time+1));
            break;
        }
        ll lb = cur_time, rb = q;
        while(rb-lb > 1){
            ll x = (lb+rb)/2;
            if(ok(max_idx, x)) lb = x;
            else rb = x;
        }
        ll l = get_elm(max_idx, cur_time);
        ll r = get_elm(max_idx, lb);
        sum += sum_arithmetic_progression(mint(l), mint(r), mint(lb-cur_time+1));
        cur_time = lb+1;
        max_idx = get_max_idx(cur_time);
        assert(ok(max_idx, cur_time));
    }
    cout << sum << endl;
}