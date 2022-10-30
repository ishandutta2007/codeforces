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

vector<int> g[1000];
bool seen[1000];

void dfs(int v, vector<int> &ord, vector<int> &par){
    seen[v] = true;
    ord.push_back(v);
    for(int to: g[v]){
        if(seen[to]) continue;
        par[to] = v;
        dfs(to, ord, par);
    }
}

// class Simulator{
//     public:
//     int n;
//     vector<int> a;
//     Simulator(int n): n(n){

//     }
// };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ord;
    vector<int> par(n);
    dfs(0, ord, par);
    auto ask = [&](vector<int> a){
        cout << "? " << a.size() << ' ';
        for(int x: a) cout << x+1 << ' ';
        cout << endl;
        int ans; cin >> ans;
        return ans;
    };
    auto verify = [&](int a, int b){
        cout << "! " << a+1 << ' ' << b+1 << endl;
    };
    vector<int> v;
    for(int i = 0; i < n; i++) v.push_back(i);
    int mx = ask(v);
    auto ask_to = [&](int x){
        vector<int> v;
        for(int i = 0; i <= x; i++) v.push_back(ord[i]);
        return ask(v);
    };
    if(ask_to(1) == mx){
        verify(ord[0], ord[1]);
        return 0;
    }
    int l = 1, r = n-1;
    while(r-l > 1){
        int x = (l+r)/2;
        if(ask_to(x) == mx) r = x;
        else l = x;
    }
    verify(par[ord[r]], ord[r]);
}