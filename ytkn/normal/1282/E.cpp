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

P make_p(int a, int b){
    if(a > b) swap(a, b);
    return P(a, b);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n-1), b(n-2), c(n-2);
    set<P> st;
    auto add = [&](int a, int b){
        if(a > b) swap(a, b);
        P p(a, b);
        if(st.count(p)) st.erase(p);
        else st.insert(p);
    };
    for(int i = 0; i < n-2; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--; c[i]--;
        add(a[i], b[i]);
        add(b[i], c[i]);
        add(c[i], a[i]);
    }
    vector<vector<int>> g(n);
    for(auto [u, v]: st){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> used(n);
    vector<int> p;
    function<void(int)> dfs = [&](int v){
        p.push_back(v);
        used[v] = true;
        for(int to: g[v]){
            if(used[to]) continue;
            dfs(to);
        }
    };
    dfs(0);
    map<P, vector<int>> indices;
    for(int i = 0; i < n-2; i++){
        indices[make_p(a[i], b[i])].push_back(i);
        indices[make_p(b[i], c[i])].push_back(i);
        indices[make_p(c[i], a[i])].push_back(i);
    }
    vector<int> rem(n-2);
    for(int i = 0; i < n-2; i++){
        rem[i] += indices[make_p(a[i], b[i])].size()-1;
        rem[i] += indices[make_p(b[i], c[i])].size()-1;
        rem[i] += indices[make_p(c[i], a[i])].size()-1;
    }
    vector<bool> ok(n-2);
    queue<int> que;
    for(int i = 0; i < n-2; i++){
        if(rem[i] <= 1) que.push(i);
    }
    auto erase = [&](P p, int idx){
        if(indices[p].back() == idx){
            indices[p].pop_back();
        }else{
            swap(indices[p][0], indices[p][1]);
        }
        if(!indices[p].empty()){
            int i = indices[p][0];
            rem[i]--;
            if(rem[i] <= 1 && !ok[i]){
                que.push(i);
            }
        }
    };
    for(int x: p) cout << x+1 << ' ';
    cout << endl;
    while(!que.empty()){
        int idx = que.front(); que.pop();
        if(ok[idx]) continue;
        ok[idx] = true;
        cout << idx+1 << ' ';
        erase(make_p(a[idx], b[idx]), idx);
        erase(make_p(b[idx], c[idx]), idx);
        erase(make_p(c[idx], a[idx]), idx);
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}