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

using graph = vector<vector<int>>;

vector<graph> list_trees(int n){
    int m = (n*(n-1))/2;
    vector<graph> ans;
    for(int s = 0; s < (1<<m); s++){
        int idx = 0;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            if(s&(1<<i)) cnt++;
        }
        if(cnt != n-1) continue;
        UnionFind uf(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(s&(1<<idx)){
                    uf.unionSet(i, j);
                }
                idx++;
            }
        }
        if(uf.size(0) == n){
            int idx = 0;
            vector<vector<int>> g(n);
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(s&(1<<idx)){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                    idx++;
                }
            }
            ans.push_back(g);
        }
    }
    return ans;
}

pair<ll, int> calc(int n, vector<vector<int>> g){
    vector<int> subtree_size(n);
    vector<int> ch(n);
    function<void(int, int)> dfs = [&](int v, int par){
        subtree_size[v] = 1;
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
            subtree_size[v] += subtree_size[to];
            ch[v]++;
        }
    };
    dfs(0, -1);
    ll sum = accumulate(subtree_size.begin(), subtree_size.end(), 0ll);
    int coef = *max_element(ch.begin(), ch.end());
    return make_pair(sum, coef);
}

void test(int n){
    auto trees = list_trees(n);
    map<int, int> branching_coefficient;
    map<int, graph> good_trees;
    for(auto g: trees){
        auto [sum, coef] = calc(n, g);
        if(branching_coefficient.count(sum)){
            if(chmin(branching_coefficient[sum], coef)){
                good_trees[sum] = g;
            }
        }else{
            branching_coefficient[sum] = coef;
            good_trees[sum] = g;
        }
    }
    for(auto [sum, coef]: branching_coefficient) {
        cout <<  sum << ": " << coef << endl;
        cout << n << ' ' << n-1 << endl;
        auto g = good_trees[sum];
        for(int i = 0; i < n; i++){
            for(int j: g[i]){
                if(j > i) cout << i << ' ' << j << endl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n; ll s; cin >> n >> s;
    ll mn = 2*n-1, mx = (n*(n+1))/2;
    if(s < mn || s > mx) {
        cout << "No" << endl;
        return 0;
    }
    vector<int> p(n, -1);
    auto ok = [&](int x){
        vector<vector<int>> v(n+1);
        vector<int> cnt(n);
        v[1].push_back(0);
        ll cur = 2;
        ll sum = 1;
        int idx = 0;
        for(ll i = 1; i < n; i++){
            // 
            ll rem = n-i;
            ll min_sum = rem*cur;
            if(rem*cur+sum > s) return false;
            ll max_sum = ((cur+cur+rem-1)*rem)/2;
            if(max_sum+sum < s){
                if(v[cur].empty()) return false;
                cur++;
                idx = 0;
            }
            sum += cur;
            v[cur].push_back(i);
            p[i] = v[cur-1][idx];
            cnt[p[i]]++;
            if(cnt[p[i]] == x){
                idx++;
                if(idx == v[cur-1].size()) {
                    cur++;
                    idx = 0;
                }
            }
        }
        return true;
        
    };
    int l = 1, r = n-1;
    if(!ok(1)){
        while(r-l > 1){
            int x = (l+r)/2;
            if(ok(x)) r = x;
            else l = x;
        }
    }
    ok(r);
    cout << "Yes" << endl;
    for(int i = 1; i < n; i++){
        cout << p[i]+1 << ' ';
    }
    cout << endl;

    // vector<vector<int>> g(n);
    // for(int i = 1; i < n; i++){
    //     g[p[i]].push_back(i);
    //     g[i].push_back(p    [i]);
    // }
    // auto [ss, coef] = calc(n, g);
    // cout << ss << ' ' << coef << endl;
}