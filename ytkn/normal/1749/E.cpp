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

const int inf = 1e9;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct edge{
    int to, cost;
    edge(int to, int cost): to(to), cost(cost) {}
};

using P = pair<int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> s(n);    
    for(int i = 0; i < n; i++) cin >> s[i];
    auto is_in_field = [&](int i, int j){
        return 0 <= i && i < n && 0 <= j && j < m;
    };
    auto puttable = [&](int i, int j){
        for(int k = 0; k < 4; k++){
            int ii = i+dx[k], jj = j+dy[k];
            if(is_in_field(ii, jj) && s[ii][jj] == '#') return false;
        }
        return true;
    };
    int from = 0, to = n*m+1;
    auto to_idx = [&](int i, int j){
        return i*m+j+1;
    };
    vector<vector<edge>> g(n*m+2);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int idx = to_idx(i, j);
            int c = s[i][j] == '#' ? 0 : 1;
            if(puttable(i, j)){
                for(int dx: {-1, 1}){
                    for(int dy: {-1, 1}){
                        int ii = i+dx, jj = j+dy;
                        int idx_to = to_idx(ii, jj);
                        if(is_in_field(ii, jj)){
                            g[idx].push_back(edge(idx_to, c));
                        }
                    }
                }
                if(j == m-1){
                    g[idx].push_back(edge(to, c));
                }
            }
            if(j == 0){
                g[from].push_back(edge(idx, 0));
            }
        }
    }
    vector<int> dist(n*m+2, inf);
    vector<int> pre(n*m+2, -1);
    priority_queue<P, vector<P>, greater<P>> que;
    auto set_dist = [&](int v, int d){
        if(chmin(dist[v], d)){
            que.push(P(d, v));
            return true;
        }
        return false;
    };
    set_dist(from, 0);
    while(!que.empty()){
        auto [d, v] = que.top(); que.pop();
        for(edge e: g[v]){
            if(set_dist(e.to, d+e.cost)){
                pre[e.to] = v;
            }
        }
    }

    if(dist[to] == inf){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    auto ans = s;
    int cur = to;
    while(cur != from){
        if(cur != to){
            int x = (cur-1)/m;
            int y = (cur-1)%m;
            ans[x][y] = '#';
        }
        cur = pre[cur];
    }
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}