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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int h, w, n; cin >> h >> w >> n;
    vector<bool> vh(h), vw(w);
    for(int i = 0; i < n; i++){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; r1--; c1--; r2--; c2--;
        vh[r1] = true;
        vh[r2] = true;
        vw[c1] = true;
        vw[c2] = true;
    }
    int cnt_h = 0, cnt_w = 0;
    for(int i = 0; i < h; i++){
        if(vh[i]) cnt_h++;
    }
    for(int i = 0; i < w; i++){
        if(vw[i]) cnt_w++;
    }
    auto dph = vec2d(h+1, h/2+1, mint(0));
    dph[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j <= h/2; j++){
            if(i+2 <= h && j+1 <= h/2){
                if(!vh[i] && !vh[i+1]) dph[i+2][j+1] += dph[i][j];
            }
            dph[i+1][j] += dph[i][j];
        }
    }
    auto dpw = vec2d(w+1, w/2+1, mint(0));
    dpw[0][0] = 1;
    for(int i = 0; i < w; i++){
        for(int j = 0; j <= w/2; j++){
            if(i+2 <= w && j+1 <= w/2){
                if(!vw[i] && !vw[i+1]) dpw[i+2][j+1] += dpw[i][j];
            }
            dpw[i+1][j] += dpw[i][j];
        }
    }
    mint ans = 0;
    for(int i = 0; 2*i <= h-cnt_h; i++){
        for(int j = 0; 2*j <= w-cnt_w; j++){
            mint tmp = dph[h][i]*dpw[w][j]*comb(h-2*i-cnt_h, j)*comb(w-2*j-cnt_w, i)*fac[i]*fac[j];
            ans += dph[h][i]*dpw[w][j]*comb(h-2*i-cnt_h, j)*comb(w-2*j-cnt_w, i)*fac[i]*fac[j];
        }
    }
    cout << ans << endl;
}