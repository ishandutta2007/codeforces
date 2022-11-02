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

/**
 * [maspy](https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7#toc1)()
 */ 
class EulerTour{
    public:
    vector<vector<int>> g;
    int root;
    int n;
    vector<int> par;
    vector<int> ord;
    vector<int> in, out;
    EulerTour(vector<vector<int>> g, int root): g(g), root(root){
        n = g.size();
        par.resize(n);
        in.resize(n);
        out.resize(n);
        build();
    }
    private:
    void build(){
        vector<bool> seen(n, false);
        ord.push_back(0);
        dfs(0, seen);
        for(int i = 0; i < n; i++) in[i] = 1e9;
        for(int i = 0; i < ord.size(); i++){
            chmin(in[ord[i]], i);
            chmax(out[ord[i]], i);
        }
    }
    void dfs(int v, vector<bool> &seen){
        seen[v] = true;
        int cnt = 0;
        for(int to: g[v]){
            if(seen[to]) continue;
            ord.push_back(to);
            par[to] = v;
            dfs(to, seen);
            ord.push_back(v);
            cnt++;
        }  
    }
};

template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

int n, k;
string s;
vector<int> l, r;

void dfs(int v, vector<int> &ord){
    if(l[v] != -1) dfs(l[v], ord);
    ord.push_back(v);
    if(r[v] != -1) dfs(r[v], ord);
}

void dfs_ng(int v, vector<vector<int>> &g, vector<int> &par, vector<bool> &ng){
    ng[v] = true;
    for(int to: g[v]){
        if(to == par[v]) continue;
        if(ng[to]) continue;
        dfs_ng(to, g, par, ng);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    cin >> s;
    l.resize(n);
    r.resize(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
        if(l[i] != -1){
            g[i].push_back(l[i]);
            g[l[i]].push_back(i);
        }
        if(r[i] != -1){
            g[i].push_back(r[i]);
            g[r[i]].push_back(i);
        }
    }
    vector<int> ord;
    dfs(0, ord);
    string t;
    for(int i: ord) t += s[i];
    string nx(n, '#');
    for(int i = n-2; i >= 0; i--){
        if(t[i] == t[i+1]){
            nx[i] = nx[i+1];
        }else{
            nx[i] = t[i+1];
        }
    }
    auto et = EulerTour(g, 0);
    int m = et.ord.size();
    bit<int> bt(m+2);
    for(int v = 0; v < n; v++){
        bt.add(et.in[v]+1, 1);
        bt.add(et.out[v]+2, -1);
    }
    auto get_depth = [&](int v){
        return bt.sum(et.in[v]+1);
    };
    vector<bool> doubled(n, false);
    vector<bool> ng(n);
    for(int j = 0; j < n; j++){
        int i = ord[j];
        if(ng[i]) continue;
        if(doubled[i]) continue;
        if(nx[j] < t[j]) {
            dfs_ng(i, g, et.par, ng);
            continue;
        }
        int d = get_depth(i);
        if(d > k) continue;
        int cur = i;
        while(cur != -1 && !doubled[cur]){
            doubled[cur] = true;
            k--;
            bt.add(et.in[cur]+1, -1);
            bt.add(et.out[cur]+2, 1);
            cur = et.par[cur];
        }
    }
    for(int j = 0; j < n; j++){
        int i = ord[j];
        cout << t[j];
        if(doubled[i]) cout << t[j];
    }
    cout << endl;
}