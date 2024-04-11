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

template<typename T>
void print_set(set<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int x: v) cout << x << delimiter;
    cout << endl;
}

int encode(const string &s){
    int ans = 0;
    for(char c: s){
        int x = 0;
        if(c != '_') x = c-'a'+1;
        ans = ans*27+x;
    }
    return ans;
}

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
    int n, m, k; cin >> n >> m >> k;
    vector<int> idx(531441, -1);
    vector<string> s(m);
    vector<int> mt(m);
    for(int i = 0; i < n; i++) {
        string p; cin >> p;
        idx[encode(p)] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> s[i] >> mt[i];
        mt[i]--;
    }
    vector<vector<int>> g(n);

    for(int i = 0; i < m; i++){
        string pp = s[i];
        bool ok = false;
        for(int t = 0; t < (1<<k); t++){
            for(int j = 0; j < k; j++){
                if(t&(1<<j)) pp[j] = '_';
                else pp[j] = s[i][j];
            }
            int enc = encode(pp);
            if(idx[enc] != -1){
                int ii = idx[enc];
                if(ii == mt[i]) ok = true;
                else{
                    g[mt[i]].push_back(ii);
                }
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<int> ord;
    if(topological_sort(g, ord)){
        cout << "YES" << endl; 
        for(int i: ord) cout << i+1 << ' ';
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
}