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
#include <stack>

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


/**
 * verified: https://judge.yosupo.jp/submission/86411
 */ 
struct RollbackUnionFind{
    int n;
    vector<int> data;
    stack<pair<pair<int, int>, pair<int, int>>> history;
    RollbackUnionFind(int n): n(n), data(n, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        history.push(make_pair(make_pair(x, data[x]), make_pair(y, data[y])));
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
        return data[x] < 0 ? x : root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
    void undo(){
        auto p1 = history.top().first;
        auto p2 = history.top().second;
        history.pop();
        data[p1.first] = p1.second;
        data[p2.first] = p2.second;
    }
};


void solve(){
    int n; cin >> n;
    string t; cin >> t;
    vector<int> p(26, -1);
    vector<int> v;
    {
        vector<bool> used(26);
        for(int i = 0; i < n; i++){
            int x = t[i]-'a';
            if(used[x]) continue;
            used[x] = true;
            v.push_back(x);
        }
    }
    RollbackUnionFind uf(26);
    vector<bool> used(26);
    function<bool(int)> dfs = [&](int i){
        if(i == v.size()) {
            return true;
        }
        
        int x = v[i];
        for(int j = 0; j < 26; j++){
            if(used[j]) continue;
            if(uf.findSet(x, j) && i+1 < 26) continue;
            p[x] = j;
            used[j] = true;
            uf.unionSet(x, j);
            if(dfs(i+1)) return true;
            uf.undo();
            used[j] = false;
            p[x] = -1;
        }
        return false;
    };
    if(!dfs(0)){
        cout << "???" << endl;
    }
    
    string ans;
    for(int i = 0; i < n; i++){
        int x = t[i]-'a';
        ans += p[x]+'a';
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}