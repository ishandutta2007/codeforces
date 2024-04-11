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
    int n, m; cin >> n >> m;
    vector<set<int>> friends(n);
    int ans = n;
    auto add = [&](int u, int v){
        if(u > v) swap(u, v);
        if(friends[u].empty()) ans--;
        friends[u].insert(v);
    };
    auto erase = [&](int u, int v){
        if(u > v) swap(u, v);
        friends[u].erase(v);
        if(friends[u].empty()) ans++;
    };
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        add(u, v);
    }
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u, v; cin >> u >> v; u--; v--;
            add(u, v);
        }else if(t == 2){
            int u, v; cin >> u >> v; u--; v--;
            erase(u, v);
        }else{
            cout << ans << endl;
        }
    }
}