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

vector<vector<int>> warshallfloyd(vector<vector<int>> g){
    int n = g.size();
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = g[i][j];
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int new_len = dist[j][i] + dist[i][k];
                dist[j][k] = min(new_len, dist[j][k]);
            }
        }
    }
    return dist;
}

const int inf = 1e9;

void test(int m){
    int n = 1<<m;
    auto dist = vec2d(n+1, n+1, inf);
    for(int i = 0; i <= n; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i > (1<<j)) continue;
            int k = (1<<j)-i;
            dist[i][k] = 1;
        }
    }
    auto d = warshallfloyd(dist);
    function<int(int, int)> calc = [&](int i, int j){
        if(i == j) return 0;
        for(int k = 0; k <= m+1; k++){
            if(i+j == 1<<k) return 1;
        }
        if(i%2 == j%2) return calc(i/2, j/2);
        return d[0][i]+d[0][j];
    };
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(d[i][j] != calc(i, j)) cout << i << ' ' << j << ' ' << d[i][j] << ' ' << calc(i, j) << endl;
        }
    }
    debug_value(d[5][7]);
    debug_value(d[4][6]);
}

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

int par(int x){
    assert(x != 0);
    for(int i = 0; i <= 30; i++){
        if(x <= (1<<i)) return (1<<i)-x;
    }
}

using P = pair<int, int>;

P dfs(int v, vector<vector<int>> &g, vector<int> &w, int d, int &ans, int &ans_u, int &ans_v){
    int max_depth = -1;
    int max_v = -1;
    if(w[v] != 0) {
        max_depth = d;
        max_v = v;
    }
    for(int to: g[v]){
        auto [x, u] = dfs(to, g, w, d+1, ans, ans_u, ans_v);
        if(max_depth != -1 && x != -1){
            if(chmax(ans, max_depth+x-d*2)){
                ans_u = u;
                ans_v = max_v;
            }
        }
        if(chmax(max_depth, x)){
            max_v = u;
        }
    }
    return P(max_depth, max_v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    vector<int> v = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int x = a[i];
        while(x != 0){
            v.push_back(x);
            x = par(x);
        }
    }
    auto cp = Compress<int>(v);
    int m = cp.size();
    vector<vector<int>> g(m);
    vector<int> w(m);
    for(int i = 0; i < n; i++){
        w[cp[a[i]]]++;
    }
    for(int i = 0; i < m; i++){
        int x = cp.data[i];
        if(x != 0){
            int p = par(x);
            g[cp[p]].push_back(i);
        }
    }
    int ans = 0;
    int ans_u = 0;
    int ans_v = 0;
    dfs(0, g, w, 0, ans, ans_u, ans_v);
    int uu = cp.data[ans_u];
    int vv = cp.data[ans_v];
    int ui = -1, vi = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == uu) ui = i; 
        if(a[i] == vv) vi = i; 
    }
    cout << ui+1 << ' ' << vi+1 << ' ' << ans << endl;
}