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

using mint = ModInt;

const int N_MAX = 300000;
bool seen[N_MAX];
vector<int> g[N_MAX];
mint dp_cnt[N_MAX][5];

bool ok_edge(int i, int j){
    if(j == 0) return false;
    if(i == 0) return false;
    if((i == 2 || i == 4) && (j == 2 || j == 4)) return false;
    if(i == 0 && (j == 1 || j == 2)) return false;
    return true;
}

int nx_edge(int i, int j){
    if(i == 0) return 0;
    if(j == 0) return i;
    if(i == 1) return 3;
    if(i == 2) return 4;
    return i;
}

bool ok(int i, int j){
    if(j == 1 || j == 2) return false;
    return true;
}

int nx(int i, int j){
    return i;
}

void dfs(int v){
    seen[v] = true;
    for(int i = 0; i < 3; i++) dp_cnt[v][i] = 1;
    for(int to: g[v]){
        if(seen[to]) continue;
        dfs(to);
        vector<mint> buf_cnt(5);
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(ok_edge(i, j)) {
                    buf_cnt[nx_edge(i, j)] += dp_cnt[v][i]*dp_cnt[to][j];
                }
                if(ok(i, j)) {
                    buf_cnt[nx(i, j)] += dp_cnt[v][i]*dp_cnt[to][j];
                }
            }
        }
        for(int i = 0; i < 5; i++) {
            dp_cnt[v][i] = buf_cnt[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    mint ans = dp_cnt[0][0]+dp_cnt[0][3]+dp_cnt[0][4]-1;
    cout << ans << endl;
}