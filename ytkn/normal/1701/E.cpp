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

const int inf = 1e9;

void solve(){
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> min_idx(m, -1);
    int idx = 0;
    for(int i = 0; i < n && idx < m; i++){
        if(s[i] == t[idx]){
            min_idx[idx] = i;
            idx++;
        }
    }
    if(min_idx[m-1] == -1){
        cout << -1 << endl;
        return;
    }
    auto max_same = vec2d(n, m, 0);
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(s[i] != t[j]) {
                max_same[i][j] = 0;
                continue;
            }
            if(i+1 < n && j+1 < m){
                max_same[i][j] = max_same[i+1][j+1]+1;
            }else{
                max_same[i][j] = 1;
            }
        }
    }
    int base = m+(n-m);
    int ans = base-max_same[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(max_same[i][j] == 0) continue;
            if(min_idx[j] > i) continue;
            int len = max_same[i][j];
            if(i == 0){
                // debug_value(len)
                int base = m+(n-m);
                chmin(ans, base-len);
            }else{
                int base = m+(n-m)+1+(i-j);
                chmin(ans, base-len);
            }
        }
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