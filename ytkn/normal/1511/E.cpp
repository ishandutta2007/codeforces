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
const int N_MAX = 300000;
mint p[300005];

void init(){
    mint inv2 = mint(2).inv();
    mint inv4 = mint(4).inv();
    p[0] = 1;
    p[1] = mint(2).inv();
    mint cur = inv2;
    mint pw = inv2;
    for(int i = 1; i*2+1 <= N_MAX; i++){
        p[i*2] = cur+pw*inv2;
        p[i*2+1] = cur+pw*inv4;
        pw = pw*inv4;
        cur = cur+pw;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, m; cin >> n >> m;
    int w = 0;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(char c : s[i]) {
            if(c == 'o') w++;
        }
    }
    vector<vector<int>> cntl(n, vector<int>(m));
    vector<vector<int>> cntu(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '*') continue;
            if(j > 0 && s[i][j-1] == 'o') cntl[i][j] = cntl[i][j-1]+1;
            if(i > 0 && s[i-1][j] == 'o') cntu[i][j] = cntu[i-1][j]+1;
        }
    }
    mint inv4 = mint(4).inv();
    mint all = pow(mint(2), w);
    mint ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i+1 < n && s[i][j] == 'o' && s[i+1][j] == 'o'){
                ans += all*p[cntu[i][j]]*inv4;
            }
            if(j+1 < m && s[i][j] == 'o' && s[i][j+1] == 'o'){
                // cout << i << ' ' << j << ' ' << cntl[i][j] << ' ' << p[cntl[i][j]]*64 << endl;
                ans += all*p[cntl[i][j]]*inv4;
            }
        }
    }
    cout << ans << endl;
}