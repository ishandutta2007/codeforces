#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
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

mint dp[1005][1005][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    
    mint ans = 0;
    for(int i = 0; i < n; i++) dp[i][m][0] = 1;
    for(int i = 0; i < m; i++) dp[n][i][1] = 1;
    // if(a[n-1] != b[m-1]){
    //     dp[n-1][m-1][0] = 1;
    //     dp[n-1][m-1][1] = 1;
    // }
    for(int i = n-2; i >= 0; i--){
        if(a[i] != a[i+1]) dp[i][m][0] += dp[i+1][m][0];
    }
    for(int i = m-2; i >= 0; i--){
        if(b[i] != b[i+1]) dp[n][i][1] += dp[n][i+1][1];
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            // if(a[i] != b[j]){
            //     dp[i][j][0] = 1;
            //     dp[i][j][1] = 1;
            // }
            if(i != n-1 && a[i] != a[i+1]){ // a[i]a[i+1]..b[j]
                dp[i][j][0] += dp[i+1][j][0];
            }
            if( b[j] != a[i]){ // b[j]a[i]
                dp[i][j][1] += dp[i][j+1][0];
                if(j != m-1) dp[i][j][1] += dp[i][m][0];
            }
            if(a[i] != b[j]){ // a[i]b[j]
                dp[i][j][0] += dp[i+1][j][1];
                if(i != n-1) dp[i][j][0] += dp[n][j][1];
            }
            if(j != m-1 && b[j] != b[j+1]){ // b[j]b[j+1]..a[i]
                dp[i][j][1] += dp[i][j+1][1];
            }
        }
    }
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans += dp[i][j][0];
            ans += dp[i][j][1];
            // cout << dp[i][j][0] << ' ';
        }
        // cout << endl;
    }
    cout << ans << endl;
}