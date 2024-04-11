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
 
#define N_MAX 3300002
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
 
template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}
 
template<typename T>
vector<T> add_vector(vector<T> u, vector<T> v){
    assert(u.size() == v.size());
    int n = u.size();
    vector<T> ans(n);
    for(int i = 0; i < n; i++) ans[i] = u[i]+v[i];
    return ans;
}
 
template<typename T>
vector<T> naive_convolution(vector<T> u, vector<T> v){
    int n = u.size(), m = v.size();
    vector<T> ans(n+m-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans[i+j] += u[i]*v[j];
        }
    }
    return ans;
}
 
/**
 * f(x) = g(x)*h(x) + r(x)(h(x), r(x))
 */ 
template<typename T>
pair<vector<T>, vector<T>> naive_divide(vector<T> f, vector<T> g){
    int n = f.size()-1;
    int m = g.size()-1;
    if(n < m) return make_pair(vector<T>(1, T(0)), f);
    int k = n-m;
    vector<T> h(k+1);
    T iv = T(1)/g[m];
    for(int i = k; i >= 0; i--){
        h[i] = f[i+m]*iv;
        for(int j = 0; j <= m; j++){
            f[i+j] -= g[j]*h[i];
        }
    }
    return make_pair(h, f);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, q; scanf("%d %d", &n, &q);
    vector<mint> f(3*n+4);
    for(int i = 1; i <= 3*n+3; i++) f[i] = comb(3*n+3, i);
    vector<mint> g = {mint(0), mint(3), mint(3), mint(1)};
    auto [h, _] = naive_divide(f, g);
    while(q--){
        int x; scanf("%d", &x);
        printf("%d\n", (int)h[x].v);
    }
}