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

const ll MOD = 1000000007;

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

using mint = ModInt;

mint solve_dp(ll m){
    vector<vector<mint>> dp(61, vector<mint>(8));
    dp[0][0] = 1;
    for(int i = 0; i < 60; i++){
        bool f = (((ll)1<<i) & m) ? true : false;
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 8; k++){
                int nx = (j+k);
                if(f) nx--;
                if(nx < 0) continue;
                if(nx%2 == 1) continue;
                nx /= 2;
                dp[i+1][nx] += dp[i][j];
            }
        }
    }
    return dp[60][0];
}

mint solve(ll m){
    ll x = (m/4)+1;
    if(m%4 <= 1){
        return mint(x)*mint(x);
    }else{
        return mint(x)*mint(x+1);
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout << setprecision(10) << fixed;
    int t; scanf("%d", &t);
    while(t--){
        ll m;
        scanf("%lld", &m);
        printf("%lld\n", solve(m).v);
    }
    // for(int i = 1; i <= 100; i++) cout << i << ':' << solve_dp(i) << ' ' << solve(i) << endl;
    return 0;
}