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
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    if(s[0][0] == '1'){
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        for(int j = m-1; j >= 1; j--){
            if(s[i][j] == '1'){
                ans.push_back({i, j-1, i, j});
            }
        }
    }
    for(int i = n-1; i >= 1; i--){
        if(s[i][0] == '1'){
            ans.push_back({i-1, 0, i, 0});
        }
    }
    cout << ans.size() << endl;
    for(auto u: ans){
        for(int x: u) cout << x+1 << ' ';
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}