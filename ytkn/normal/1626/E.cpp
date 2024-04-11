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

struct edge{
    int to;
    int cnt;
    int rev;
};

vector<edge> g[300000];
int c[300000];
int m;
bool seen[300000];
int cnt[300000];

void dfs(int v){
    seen[v] = true;
    cnt[v] += c[v];
    int par = -1;
    for(edge &e: g[v]){
        if(seen[e.to]) {
            par = e.to;
            continue;
        }
        dfs(e.to);
        cnt[v] += cnt[e.to];
        e.cnt = cnt[e.to];
    }
    for(edge &e: g[v]){
        if(e.to == par) {
            e.cnt = m-cnt[v];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        m += c[i];
    }
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(edge{v, 0, (int)g[v].size()});
        g[v].push_back(edge{u, 0, (int)g[u].size()-1});
    }
    dfs(0);
    vector<bool> seen(n);
    queue<int> que;
    vector<int> ans(n);
    auto push = [&](int v){
        ans[v] = 1;
        if(!seen[v]){
            que.push(v);
            seen[v] = true;
        }
    };
    for(int i = 0; i < n; i++){
        if(c[i] == 1){
            push(i);
            for(edge e: g[i]){
                push(e.to);
            }
        }
    }
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(edge e: g[v]){
            edge e_rev = g[e.to][e.rev];
            if(e_rev.cnt >= 2) {
                push(e.to);
            }
        }
    }
    print_vector(ans);
}