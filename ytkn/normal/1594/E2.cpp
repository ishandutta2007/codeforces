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

using mint = ModInt;

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

ll parent(ll v){
    return v/2;
}

int to_index(string s){
    if(s == "white") return 0;
    if(s == "yellow") return 1;
    if(s == "green") return 2;
    if(s == "blue") return 3;
    if(s == "red") return 4;
    return 5;
}

bool ok(int i, int j){
    if(i/2 == j/2) return false;
    return true;
}

vector<mint> dfs(int v, vector<vector<int>> &g, vector<int> &col, int d, int max_depth){
    vector<mint> ans(6);
    vector<mint> ans_l, ans_r;
    int k = max_depth-d;
    mint x = k == 0 ? mint(1) : pow(mint(4), (1ll<<k)-2);
    if(k == 0){
        if(col[v] == -1) return vector<mint>(6, x);
        vector<mint> ans(6, mint(0));
        ans[col[v]] = x;
        return ans;
    }
    if(g[v].empty()){
        ans_l = vector<mint>(6, x);
        ans_r = vector<mint>(6, x);
    }
    if(g[v].size() == 1){
        int l = g[v][0];
        ans_l = dfs(l, g, col, d+1, max_depth);
        ans_r = vector<mint>(6, x);
    }
    if(g[v].size() == 2){
        int l = g[v][0];
        int r = g[v][1];
        ans_l = dfs(l, g, col, d+1, max_depth);
        ans_r = dfs(r, g, col, d+1, max_depth);
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                if(ok(i, j) && ok(i, k)) ans[i] += ans_l[j]*ans_r[k];
            }
        }
    }
    if(col[v] != -1){
        for(int i = 0; i < 6; i++){
            if(i != col[v]) ans[i] = 0;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int k; cin >> k;
    int n; cin >> n;
    vector<ll> v(n);
    vector<int> indices(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        string s; cin >> s;
        indices[i] = to_index(s);
    }
    vector<ll> u;
    for(int i = 0; i < n; i++){
        ll cur = v[i];
        while(true){
            u.push_back(cur);
            if(cur == 1) break;
            cur = parent(cur);
        }
    }
    auto cp = Compress<ll>(u);
    int m = cp.size();
    vector<int> col(m, -1);
    vector<vector<int>> g(m);
    for(int i = 0; i < n; i++){
        col[cp[v[i]]] = indices[i];
    }
    for(ll x: cp.data){
        if(x == 1) continue;
        ll par = parent(x);
        g[cp[par]].push_back(cp[x]);
    }
    auto ans = dfs(0, g, col, 0, k-1);
    cout << accumulate(ans.begin(), ans.end(), mint(0)) << endl;
    // cout << pow(mint(4), (1ll<<k)-2)*6 << endl;
}