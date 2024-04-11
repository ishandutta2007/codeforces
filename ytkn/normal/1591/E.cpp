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

struct query{
    int idx, l, k;
};

int n, q;
vector<int> a;
vector<int> cnt;
vector<int> ans;
vector<vector<int>> g;
vector<set<int>> elements;
vector<vector<query>> queries;

void clear(){
    a.clear();
    ans.clear();
    cnt.clear();
    g.clear();
    elements.clear();
    queries.clear();
}

void dfs(int v, bit<int> &bt){
    if(cnt[a[v]]) {
        bt.add(cnt[a[v]], -1);
        elements[cnt[a[v]]].erase(a[v]);
    }
    cnt[a[v]]++;
    elements[cnt[a[v]]].insert(a[v]);
    bt.add(cnt[a[v]], 1);
    for(auto q: queries[v]){
        int cnt_less = bt.sum(q.l-1);
        int cnt_all = bt.sum(n);
        if(cnt_all-cnt_less < q.k){
            ans[q.idx] = -1;
            continue;
        }
        int l = 0, r = n;
        while(r-l > 1){
            int c = (l+r)/2;
            int cnt_to_c = bt.sum(c);
            if(cnt_to_c-cnt_less < q.k) l = c;
            else r = c;
        }
        ans[q.idx] = *elements[r].begin();
    }
    for(int to: g[v]){
        dfs(to, bt);
    }

    bt.add(cnt[a[v]], -1);
    elements[cnt[a[v]]].erase(a[v]);
    cnt[a[v]]--;
    if(cnt[a[v]]) {
        bt.add(cnt[a[v]], 1);
        elements[cnt[a[v]]].insert(a[v]);
    }
}

void solve(){
    cin >> n >> q;
    a.resize(n);
    cnt.resize(n+1);
    ans.resize(q);
    g.resize(n);
    elements.resize(n+1);
    queries.resize(n);
    auto bt = bit<int>(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        int p; cin >> p; p--;
        g[p].push_back(i);
    }
    for(int i = 0; i < q; i++){
        int v, l, k; cin >> v >> l >> k; v--;
        queries[v].push_back(query{i, l, k});
    }
    dfs(0, bt);
    for(int i = 0; i < q; i++) cout << ans[i] << ' ';
    cout << "\n";
    clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}