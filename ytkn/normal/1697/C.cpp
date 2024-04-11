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
    string s, t; cin >> s >> t;
    auto cnt_a = vec2d(n+1, 3, 0);
    auto cnt_b = vec2d(n+1, 3, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cnt_a[i+1][j] = cnt_a[i][j];
        for(int j = 0; j < 3; j++) cnt_b[i+1][j] = cnt_b[i][j];
        cnt_a[i+1][s[i]-'a']++;
        cnt_b[i+1][t[i]-'a']++;
    }
    for(int i = 0; i < 3; i++){
        if(cnt_a[n][i] != cnt_b[n][i]){
            cout << "NO" << endl;
            return;
        }
    }
    vector<vector<int>> s_indices(3), t_indices(3);
    for(int i = 0; i < n; i++){
        s_indices[s[i]-'a'].push_back(i);
        t_indices[t[i]-'a'].push_back(i);
    }
    for(int i = 0; i < s_indices[0].size(); i++){
        if(s_indices[0][i] > t_indices[0][i]){
            cout << "NO" << endl;
            return;
        }
        int si = s_indices[0][i], ti = t_indices[0][i];
        if(cnt_a[si+1][2] != cnt_b[ti+1][2]){
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 0; i < s_indices[2].size(); i++){
        if(s_indices[2][i] < t_indices[2][i]){
            cout << "NO" << endl;
            return;
        }
        int si = s_indices[2][i], ti = t_indices[2][i];
        if(cnt_a[si+1][0] != cnt_b[ti+1][0]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}