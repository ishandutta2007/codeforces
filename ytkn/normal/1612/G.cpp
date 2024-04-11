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

template <typename T>
class OffsetVec{
    public:
	int n;
    vector<T> v;
	T& operator[](int x) {
        return v[x+n];
	}
    void print(){
        for(int i = -n; i <= n; i++) cout << v[i+n] << ' ';
        cout << endl;
    }
    OffsetVec(int _n){
        n = _n;
        v = vector<T>(2*n+1);
    }
    OffsetVec(int _n, T x){
        n = _n;
        v = vector<T>(2*n+1, x);
    }
};

using mint = ModInt;
const int M_MAX = 1000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int m; cin >> m;
    vector<int> c(m);
    for(int i = 0; i < m; i++) cin >> c[i];
    OffsetVec<int> even_imos(M_MAX+1), odd_imos(M_MAX+1);
    for(int i = 0; i < m; i++){
        int x = c[i]-1;
        if(x%2 == 0){
            even_imos[-x]++;
            even_imos[x+1]--;
        }else{
            odd_imos[-x]++;
            odd_imos[x+1]--;
        }
    }
    for(int i = -M_MAX+1; i <= M_MAX; i++){
        odd_imos[i] += odd_imos[i-1];
        even_imos[i] += even_imos[i-1];
    }
    OffsetVec<int> total(M_MAX);
    mint mx = 0, cnt = 1;
    ll sum = 0;
    for(int i = -M_MAX; i <= M_MAX; i++){
        if(i%2 == 0) total[i] += even_imos[i];
        else total[i] += odd_imos[i];
        mx += mint(total[i])*(sum+sum+total[i]-1)*inv[2]*i;
        cnt *= fac[total[i]];
        sum += total[i];
    }
    cout << mx << ' ' << cnt << endl;
}