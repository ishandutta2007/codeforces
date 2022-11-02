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

struct edge {
    int to, idx;
};

void solve(){
    int n; cin >> n;
    vector<vector<edge>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(edge{b, i});
        g[b].push_back(edge{a, i});
    }
    int s = -1;
    for(int i = 0; i < n; i++){
        if(g[i].size() >= 3){
            cout << -1 << endl;
            return;
        }
        if(g[i].size() == 1) s = i;
    }
    vector<bool> seen(n);
    queue<int> que;
    vector<int> ans(n-1);
    auto push = [&](int v){
        if(!seen[v]) {
            seen[v] = true;
            que.push(v);
            return true;
        }
        return false;
    };
    push(s);
    int cur = 2;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(edge e: g[v]){
            if(push(e.to)){
                ans[e.idx] = cur;
                cur = cur == 2 ? 3 : 2;
            }
        }
    }
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}