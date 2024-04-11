#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

using T = tuple<int, int, ll>;
using P = pair<int, int>;
using Pli = pair<ll, int>;
const ll inf = 1e18;
struct edge{
    int to;
    ll cost;
};

void solve(){
    int  n, m, k; cin >> n >> m >> k;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    vector<vector<int>> vs(n);
    map<P, vector<T>> g;
    map<P, ll> dist;
    vs[0].push_back(0);
    vs[n-1].push_back(m-1);
    for(int i = 0; i < k; i++){
        int a, b, c, d, h; cin >> a >> b >> c >> d >> h; a--; b--; c--; d--;
        vs[a].push_back(b);
        vs[c].push_back(d);
        dist[P(a, b)] = inf;
        dist[P(c, d)] = inf;
        g[P(a, b)].push_back(T(c, d, h));
    }
    dist[P(n-1, m-1)] = inf;
    dist[P(0, 0)] = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sort(vs[i].begin(), vs[i].end());
        int mm = vs[i].size();
        if(mm == 0) continue;
        for(int j = 0; j < mm-1; j++){
            P p(i, vs[i][j]);
            P q(i, vs[i][j+1]);
            ll len = vs[i][j+1]-vs[i][j];
            chmin(dist[q], dist[p]+len*x[i]);
        }
        for(int j = mm-1; j > 0; j--){
            P p(i, vs[i][j]);
            P q(i, vs[i][j-1]);
            ll len = vs[i][j]-vs[i][j-1];
            chmin(dist[q], dist[p]+len*x[i]);
        }
        int pre = -1;
           
        for(int j: vs[i]){
            if(j == pre) continue;
            pre = j;
            if(g.count(P(i, j)) == 0) {
                continue;   
            }
            sum += g[P(i, j)].size();
            
            if(dist[P(i, j)] == inf) continue;
            for(auto [c, d, h]: g[P(i, j)]){
                chmin(dist[P(c, d)], dist[P(i, j)]-h);
            }
        }
    }
    P t(n-1, m-1);
    if(dist[t] == inf){
        cout << "NO ESCAPE" << endl;
    }else{
        cout << dist[t] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}