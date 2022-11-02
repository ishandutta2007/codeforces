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
    string s; cin >> s;
    int n = s.size();
    auto nx = vec2d(n+1, 3, -1);
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 3; j++){
            nx[i][j] = nx[i+1][j];
        }
        int x = s[i]-'0'-1;
        nx[i][x] = i;
    }
    // print_vector(nx[0]);
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int j = 0; j < 3; j++){
            if(nx[i][j] == -1) ok = false;
        }
        if(!ok) continue;
        int j = *max_element(nx[i].begin(), nx[i].end());
        int len = j-i+1;
        if(ans == 0 || ans > len) ans = len;
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