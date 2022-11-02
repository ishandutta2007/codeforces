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
    int cnt_a = 0;
    int cnt_p = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'A') cnt_a++;
            else cnt_p++;
        }
    }
    if(cnt_a == 0){
        cout << "MORTAL" << endl;
        return;
    }
    if(cnt_p == 0){
        cout << 0 << endl;
        return;
    }
    auto count = [&](int row, int col, char c){
        int ans = 0;
        if(row == -1){
            for(int i = 0; i < n; i++){
                if(s[i][col] == c) ans++;
            }
            return ans;
        }
        if(col == -1){
            for(int j = 0; j < m; j++){
                if(s[row][j] == c) ans++;
            }
            return ans;
        }
        assert(false);
    };
    if(count(0, -1, 'P') == 0 || count(n-1, -1, 'P') == 0 || count(-1, 0, 'P') == 0 || count(-1, m-1, 'P') == 0){
        cout << 1 << endl;
        return;
    }
    if(s[0][0] == 'A' || s[0][m-1] == 'A' || s[n-1][0] == 'A' || s[n-1][m-1] == 'A'){
        cout << 2 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(count(i, -1, 'P') == 0){
            cout << 2 << endl;
            return;
        }
    }
    for(int j = 0; j < m; j++){
        if(count(-1, j, 'P') == 0){
            cout << 2 << endl;
            return;
        }
    }
    if(count(0, -1, 'A') > 0 || count(n-1, -1, 'A') > 0 || count(-1, 0, 'A') > 0 || count(-1, m-1, 'A') > 0){
        cout << 3 << endl;
        return;
    }
    cout << 4 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}