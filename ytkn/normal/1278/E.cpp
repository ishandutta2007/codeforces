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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> l(n), r(n);
    vector<int> ch(n);
    vector<bool> seen(n);
    function<void(int, int)> dfs = [&](int v, int offset){
        seen[v] = true;
        ch[v] = 1;
        int direct_children = g[v].size()-1;
        if(v == 0) direct_children++;
        l[v] = offset;
        r[v] = offset+direct_children+1;
        int idx = 0;
        offset++;
        for(int to: g[v]){
            if(seen[to]) continue;
            dfs(to, offset+direct_children-idx);
            l[to] = l[v]+direct_children-idx;
            idx++;
            ch[v] += ch[to];
            offset += 2*ch[to];
        }
    };
    dfs(0, 0);
    for(int i = 0; i < n; i++) cout << l[i]+1 << ' ' << r[i]+1 << '\n';
}