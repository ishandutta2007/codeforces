#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

bool topological_sort(vector<vector<int>> g, vector<int> &order){
    int n = g.size();
    order.clear();
    vector<bool> used(n, false);
    function<void(int)> dfs = [&](int v){
        used[v] = true;
        for(int to : g[v]){
            if(!used[to]) dfs(to);
        }
        order.push_back(v);
    };
    for(int v = 0; v < n; v++){
        if(!used[v]) dfs(v);
    }
    reverse(order.begin(), order.end());
    vector<int> inv_order(n);
    for(int i = 0; i < n; i++) inv_order[order[i]] = i;
    for(int v = 0; v < n; v++){
        for(int u : g[v]){
            if(inv_order[v] > inv_order[u]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> g_inv(n);
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    for(int i = 0; i < m; i++){
        if(t[a[i]] == t[b[i]]) {
            cout << -1 << endl;
            return 0;
        }
        if(t[a[i]] < t[b[i]]) {
            g[a[i]].push_back(b[i]);
            g_inv[b[i]].push_back(a[i]);
        } else {
            g[b[i]].push_back(a[i]);
            g_inv[a[i]].push_back(b[i]);
        }
    }
    vector<int> t_ord;
    if(topological_sort(g, t_ord)){
        set<int> st;
        for(int i = 0; i < n; i++) st.insert(i+1);
        for(int i = 0; i < n; i++){
            vector<int> v;
            for(int j : g_inv[i]) {
                if(st.count(t[j])) {
                    st.erase(t[j]);
                    v.push_back(t[j]);
                }
            }
            if(*st.begin() != t[i]){
                cout << -1 << endl;
                return 0;
            }
            for(int x : v) st.insert(x);
        }
        for(int x : t_ord) cout << x+1 << ' ';
        cout << endl;
    }else{
        cout << -1 << endl;
    }
}