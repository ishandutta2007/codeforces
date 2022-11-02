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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

using P = pair<int, int>;
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
mint all_ans = 0;

template<typename T>
struct ReRooting {
    int n;
    T(*e)();
    T(*merge)(T, T);
    T(*f)(T, int);
    T(*g)(T, int);
    vector<vector<int>> G;
    vector<vector<T>> dp;
    ReRooting(int n, T(*e)(), T(*merge)(T, T), T(*f)(T, int), T(*g)(T, int)): n(n), e(e), merge(merge), f(f), g(g) {
        dp.resize(n);
        G.resize(n);
    }
    ReRooting(vector<vector<int>> G, T(*e)(), T(*merge)(T, T), T(*f)(T, int), T(*g)(T, int)): n(G.size()), G(G), e(e), merge(merge), f(f), g(g) {
        dp.resize(n);
    }
    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    T dfs1(int v, int p){
        T ans = e();
        for(int i = 0; i < G[v].size(); i++){
            int u = G[v][i];
            if(u == p) continue;
            dp[v][i] = dfs1(u, v);
            ans = merge(ans, dp[v][i]);
            all_ans -= dp[v][i].cnt_root;
        }
        return g(ans, v);;
    }
    void dfs2(int v, int p, T from_par){
        all_ans -= from_par.cnt_root;
        int deg = G[v].size();
        for(int i = 0; i < deg; i++){
            if(G[v][i] == p){
                dp[v][i] = from_par;
                break;
            }
        }
        vector<T> from_right(deg+1, e());
        for(int i = deg-1; i >= 0; i--){
            from_right[i] = merge(from_right[i+1], f(dp[v][i], G[v][i]));
        }
        T from_left = e();
        for(int i = 0; i < deg; i++){
            int u = G[v][i];
            if(u != p){
                T x = merge(from_left, from_right[i+1]);
                dfs2(u, v, g(x, v));
            }
            from_left = merge(from_left, f(dp[v][i], G[v][i]));
        }
    }
    vector<T> solve(int r = 0){
        for(int i = 0; i < n; i++) dp[i].assign(G[i].size(), e());
        dfs1(r, -1);
        dfs2(r, -1, e());
        vector<T> ans(n, e());
        for(int v = 0; v < n; v++){
            for(int i = 0; i < G[v].size(); i++){
                ans[v] = merge(ans[v], f(dp[v][i], G[v][i]));
            }
            ans[v] = g(ans[v], v);
        }
        return ans;
    }
};

int n, k;

struct S{
    int n;
    mint cnt, cnt_root;
    S(int n, mint cnt, mint cnt_root): n(n), cnt(cnt), cnt_root(cnt_root) {}
};

S g(S s, int v){
    mint cnt = comb(s.n+1, k);
    mint cnt_root = s.cnt_root+(cnt-s.cnt)*(n-s.n-1);
    return S(s.n+1, cnt, cnt_root);
}

S f(S s, int v){
    return s;
}

S e(){
    return S(0, mint(0), mint(0));
}

S merge(S x, S y){
    return S(x.n+y.n, x.cnt+y.cnt, x.cnt_root+y.cnt_root);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    cin >> n >> k;
    vector<vector<int>> G(n);
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    all_ans = comb(n, k)*n*n;
    ReRooting<S> rr(G, e, merge, f, g);
    rr.solve();
    cout << all_ans << endl;
}