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
    vector<vector<int>> idx(n);
    for(int i = 0; i < n; i++) idx[i].push_back(0);
    for(int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        idx[a].push_back(i+1);
    }
    for(int i = 0; i < n; i++) idx[i].push_back(n+1);
    vector<int> max_diff(n, 0);
    vector<int> ans(n+5, 2*n);
    for(int i = 0; i < n; i++){
        int m = idx[i].size();
        for(int j = 0; j < m-1; j++) chmax(max_diff[i], idx[i][j+1]-idx[i][j]);
        chmin(ans[max_diff[i]], i);
    }
    for(int i = 1; i <= n; i++){
        chmin(ans[i], ans[i-1]);
        if(ans[i] == 2*n) cout << -1 << ' ';
        else cout << ans[i]+1 << ' ';
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