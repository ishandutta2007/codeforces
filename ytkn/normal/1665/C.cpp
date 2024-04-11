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

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        int p; cin >> p; p--;
        g[p].push_back(i);
    }
    vector<int> v;
    v.push_back(1);
    for(int i = 0; i < n; i++){
        if(g[i].empty()) continue;
        v.push_back(g[i].size());
    }
    sort(v.begin(), v.end(), greater<int>());
    int m = v.size();
    int ans = m;
    for(int i = 0; i < m; i++){
        v[i] -= (m-i);
        chmax(v[i], 0);
    }
    vector<int> u;
    for(int x: v){
        if(x != 0) u.push_back(x);
    }
    while(!u.empty()){
        ans++;
        vector<int> v;
        bool used = false;
        for(int x: u){
            x--;
            if(x != 0 && !used){
                x--;
                used = true;
            }
            if(x != 0) v.push_back(x);
        }
        u = v;
        sort(u.begin(), u.end(), greater<int>());
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