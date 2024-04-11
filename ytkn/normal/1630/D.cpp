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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};


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

const ll inf = 1e18;

void test(int n, int g){
    UnionFind uf(1<<n);
    for(int s = 0; s < (1<<n); s++){
        for(int j = 0; j+g <= n; j++){
            int t = s;
            int mask = (1<<g)-1;
            mask <<= j;
            for(int k = 0; k < g; k++) t ^= 1<<(j+k);
            uf.unionSet(s, t);    
        }
    }
    for(int s = 0; s < (1<<n); s++){
        if(uf.findSet(0, s)){
            for(int i = 0; i < n; i++) {
                if(s&(1<<i)) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            // cout << s;
            cout << endl;
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) cin >> b[i];
    int g = 0;
    for(int x: b) g = gcd(x, g);
    vector<ll> ans(2);
    vector<vector<ll>> v(g);
    for(int i = 0; i < n; i++){
        v[i%g].push_back(a[i]);
    }
    for(int k = 0; k < g; k++){
        int n = v[k].size();
        auto dp = vec2d(n+1, 2, -inf);
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                chmax(dp[i+1][j^1], dp[i][j]-v[k][i]);
                chmax(dp[i+1][j], dp[i][j]+v[k][i]);
            }
        }
        ans[0] += dp[n][0];
        ans[1] += dp[n][1];
    }
    cout << max(ans[0], ans[1]) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}