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

using P = pair<int, int>;
struct edge{
    int to, cnt;
    edge(int to, int cnt): to(to), cnt(cnt) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    map<P, int> cnt;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        P e(u, v);
        if(cnt.count(e)){
            cnt[e]++;
        }else{
            cnt[e] = 1;
        }
    }
    vector<vector<edge>> g(n), g_inv(n);
    for(auto [p, c]: cnt){
        auto [from, to] = p;
        g[from].push_back(edge(to, c));
        g_inv[to].push_back(edge(from, c));
    }
    auto ok = [&](int x){
        vector<int> d(n, -1);
        vector<int> to_delete(n);
        for(int i = 0; i < n; i++) {
            for(edge e: g[i]){
                to_delete[i] += e.cnt;
            }
        }
        priority_queue<P> que;
        auto push = [&](int v, int dd){
            if(dd < 0) return;
            if(chmax(d[v], dd)){
                que.push(P(d[v], v));
            }
        };
        push(n-1, x);
        while(!que.empty()){
            auto [dd, v] = que.top(); que.pop();
            if(dd != d[v]) continue;
            for(edge e: g_inv[v]){
                int from = e.to;
                P edge(from, v);
                to_delete[from] -= e.cnt;
                int d_from = dd-to_delete[from]-1;
                assert(d_from < dd);
                push(from, d_from);
            }
        }
        return d[0] >= 0;
    };
    int l = 0, r = m;
    while(r-l > 1){
        int x = (l+r)/2;
        if(ok(x)) r = x;
        else l = x;
    }
    cout << r << endl;
}