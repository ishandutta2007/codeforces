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

#define N_MAX 1000002
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

const int M_MAX = 100;
// 0: empty, 1: A, 2: B
int grundy[M_MAX+1][2];

int mex(vector<int> v){
    int mx = *max_element(v.begin(), v.end());
    vector<bool> used(mx+2);
    for(int x : v) used[x] = true;
    for(int i = 0; i <= mx+1; i++){
        if(!used[i]) return i;
    }
}

void init_g(){
    grundy[1][0] = 1;
    grundy[1][1] = 0;
    for(int n = 2; n <= M_MAX; n++){
        vector<int> v;
        // 
        for(int l = 0; l < n; l++){
            // a
            if(l > 0 && l+1 != n){
                v.push_back(grundy[l][0]^grundy[n-l-1][0]);
            }
            // b
            v.push_back(grundy[l][1]^grundy[n-l-1][1]);
        }
        grundy[n][0] = mex(v);
        v.clear();
        for(int l = 0; l < n; l++){
            // a
            if(l > 0){
                v.push_back(grundy[l][0]^grundy[n-l-1][1]);
            }
            // b
            if(l+1 != n){
                v.push_back(grundy[l][1]^grundy[n-l-1][0]);
            }
        }
        grundy[n][1] = mex(v);
    }
}

void test(){
    init_g();
    for(int i = 1; i <= M_MAX; i++){
        cout << grundy[i][0] << ' ' << grundy[i][1] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n; cin >> n;
    mint ans = 0;
    for(int k = 1; 2*k <= n; k++){
        ans += fac[2*k]*comb(2*k, n-2*k)*2;
        if(n-2*k-1 >= 0){
            ans += fac[2*k]*comb(2*k-1, n-2*k-1)*2;
        }
    }
    cout << ans << endl;
}