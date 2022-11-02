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

using P = pair<int, int>;
using T = tuple<int, int, int, int>;

int a[2000][2000];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = -1;
        }
    }
    int a_max = -1;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '.') continue;
            a[i][j] = s[j]-'a';
            chmax(a_max, a[i][j]);
        }
    }
    if(a_max == -1){
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    vector<vector<P>> pos(a_max+1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(a[i][j] == -1) continue;
            pos[a[i][j]].push_back(P(i, j));
        }
    }
    
    vector<T> ans(a_max+1);
    for(int x = a_max; x >= 0; x--){
        int x_max = 0, x_min = n-1, y_max = 0, y_min = m-1; 
        if(pos[x].empty()){
            auto [i, j] = pos[a_max][0];
            ans[x] = T(i, j, i, j);
            continue;
        }
        for(auto [x, y]: pos[x]){
            chmax(x_max, x);  
            chmin(x_min, x);  
            chmax(y_max, y);  
            chmin(y_min, y);  
        }
        if(x_max != x_min && y_max != y_min){
            cout << "NO" << endl;
            return;
        }
        if(x_max == x_min){
            for(int j = y_min; j <= y_max; j++){
                if(a[x_min][j] < x){
                    cout << "NO" << endl;
                    return;
                }
            }
            ans[x] = T(x_min, y_min, x_min, y_max);
        }else if(y_max == y_min){
            for(int i = x_min; i <= x_max; i++){
                if(a[i][y_min] < x){
                    cout << "NO" << endl;
                    return;
                }
            }
            ans[x] = T(x_min, y_min, x_max, y_max);
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(int x = 0; x <= a_max; x++){
        auto [a, b, c, d] = ans[x];
        cout << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << d+1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}