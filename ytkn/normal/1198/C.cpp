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
    int n, m; cin >> n >> m;
    vector<bool> used(3*n);
    vector<int> matchings;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        if(!used[u] && !used[v]){
            matchings.push_back(i);
            used[u] = true;
            used[v] = true;
        }
    }
    if(matchings.size() >= n){
        cout << "Matching" << '\n';
        for(int i = 0; i < n; i++) cout << matchings[i]+1 << ' ';
        cout << '\n';
        return;
    }
    vector<int> ans;
    for(int i = 0; i < 3*n && ans.size() < n; i++){
        if(!used[i]) ans.push_back(i);
    }
    cout << "IndSet" << '\n';
    for(int i = 0; i < n; i++) cout << ans[i]+1 << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}