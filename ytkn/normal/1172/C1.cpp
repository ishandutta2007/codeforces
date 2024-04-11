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

#define N_MAX 200002
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

ModInt comb(ll n, ll r){
    if(n < r){
        return ModInt(0);
    }else{
        return fac[n]*finv[r]*finv[n-r];
    }
}

using mint = ModInt;

mint dp[55][55][55];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, m; cin >> n >> m;
    vector<int> a(n), w(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> w[i];
    int w_sum = accumulate(w.begin(), w.end(), 0);
    int n_like = accumulate(a.begin(), a.end(), 0);
    int n_dislike = n-n_like;
    int w_sum_like = 0, w_sum_dislike = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1) w_sum_like += w[i];
        else w_sum_dislike += w[i];
    }
    auto calc = [&](int idx) -> mint{
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= m; k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j <= i; j++){
                int current_w_sum_like = w_sum_like + j;
                int current_w_sum_dislike = w_sum_dislike - (i-j);
                if(current_w_sum_dislike < 0) {
                    continue;
                }
                int current_w_sum = current_w_sum_like+current_w_sum_dislike;
                int max_self = a[idx] == 1 ? j : i-j;
                for(int k = 0; k <= max_self; k++){
                    // 
                    mint p_like = mint(current_w_sum_like)*inv[current_w_sum];
                    mint p_dislike = mint(current_w_sum_dislike)*inv[current_w_sum];
                    if(a[idx] == 1){
                        int w_idx = w[idx]+k;
                        mint p_idx = mint(w_idx)*inv[current_w_sum_like];
                        mint p_not_idx = mint(1)-p_idx;
                        dp[i+1][j+1][k] += dp[i][j][k]*p_like*p_not_idx;
                        dp[i+1][j+1][k+1] += dp[i][j][k]*p_like*p_idx;
                    }else{
                        dp[i+1][j+1][k] += dp[i][j][k]*p_like;
                    }
                    // 
                    if(current_w_sum_dislike > 0){
                        if(a[idx] == 0){
                            int w_idx = w[idx]-k;
                            if(w_idx >= 0){
                                mint p_idx = mint(w_idx)*inv[current_w_sum_dislike];
                                mint p_not_idx = mint(1)-p_idx;
                                
                                dp[i+1][j][k] += dp[i][j][k]*p_dislike*p_not_idx;
                                dp[i+1][j][k+1] += dp[i][j][k]*p_dislike*p_idx;
                            }
                        }else{
                            dp[i+1][j][k] += dp[i][j][k]*p_dislike;
                        }
                    }
                }
            }
        }
        mint ans = 0;
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= m; k++){
                int w_idx = w[idx] + (a[idx] == 1 ? k : -k);
                if(w_idx <= 0) continue;
                ans += mint(w_idx)*dp[m][j][k];
                // cout << j << ' ' << k << ' ' << w_idx << ' ' << dp[m][j][k] << endl;
            }
        }
        return ans;
    };
    for(int i = 0; i < n; i++) {
        cout << calc(i) << endl;
    }
}