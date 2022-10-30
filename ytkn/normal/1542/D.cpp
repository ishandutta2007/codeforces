#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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

const ll MOD = 998244353;

class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        if(_v < 0) _v = (v%MOD)+MOD;
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

using mint = ModInt;
// using mint = atcoder::modint998244353;

mint naive(vector<char> t, vector<int> x){
    int n = t.size();
    mint ans = 0;
    vector<int> cnt(n);
    for(int i = 0; i < (1<<n); i++){
        set<int> st;
        for(int j = 0; j < n; j++){
            if(!(i&(1<<j))) continue;
            if(t[j] == '-' && !st.empty()) st.erase(st.begin());
            if(t[j] == '+') st.insert(x[j]);
        }
        ans += accumulate(st.begin(), st.end(), 0ll);
        for(int j = 0; j < n; j++){
            if(st.count(x[j])) cnt[j]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(t[i] == '+') cout << i << ':' << cnt[i] << endl;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<char> t(n);
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
        if(t[i] == '+') cin >> x[i];
    }

    mint ans = 0;
    for(int i = 0; i < n; i++){
        if(t[i] == '-') continue;
        vector<vector<mint>> dp(n+1, vector<mint>(n+1));
        dp[0][0] = 1;
        for(int j = 0; j < n; j++){
            for(int k = 0; k <= j; k++){
                if(t[j] == '-'){
                    if(k == 0) {
                        dp[j+1][0] += dp[j][k]*2;
                    }
                    else {
                        dp[j+1][k-1] += dp[j][k];
                        dp[j+1][k] += dp[j][k];
                    }
                    continue;
                }
                if(j < i){
                    if(x[j] < x[i]) {
                        dp[j+1][k+1] += dp[j][k];
                        dp[j+1][k] += dp[j][k];
                    }else{
                        dp[j+1][k] += dp[j][k]*2;
                    }
                }else if(j == i){
                    dp[j+1][k+1] += dp[j][k];
                }else{
                    if(x[j] <= x[i]) {
                        if(k == 0){
                            dp[j+1][k] += dp[j][k]*2;
                        }else{
                            dp[j+1][k+1] += dp[j][k];
                            dp[j+1][k] += dp[j][k];
                        }
                    }else{
                        dp[j+1][k] += dp[j][k]*2;
                    }
                }
            }
        }
        for(int j = 1; j <= n; j++) ans += dp[n][j]*x[i];
    }
    cout << ans << endl;
    // cout << naive(t, x) << endl;
}