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

int n, m;
int dh[4] = {0, 0, -1, 1};
int dw[4] = {-1, 1, 0, 0};

inline bool is_in_field(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j, vector<string> &s, vector<vector<int>> &cnt, vector<vector<bool>> &seen){
    seen[i][j] = true;
    for(int k = 0; k < 4; k++){
        int ito = i+dh[k];
        int jto = j+dw[k];
        if(!is_in_field(ito, jto)) continue;
        if(s[ito][jto] == '#') continue;
        cnt[ito][jto]--;
    }
    for(int k = 0; k < 4; k++){
        int ito = i+dh[k];
        int jto = j+dw[k];
        if(!is_in_field(ito, jto)) continue;
        if(s[ito][jto] == '#') continue;
        if(seen[ito][jto]) continue;
        if(cnt[ito][jto] <= 1) dfs(ito, jto, s, cnt, seen);
    }
}

void solve(){
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int si = -1, sj = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'L'){
                si = i;
                sj = j;
            }
        }
    }
    auto seen = vec2d(n, m, false);
    auto cnt = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '#') continue;
            for(int k = 0; k < 4; k++){
                int ito = i+dh[k];
                int jto = j+dw[k];
                if(!is_in_field(ito, jto)) continue;
                if(s[ito][jto] == '#') continue;
                cnt[i][j]++;
            }
        }
    }
    dfs(si, sj, s, cnt, seen);
    auto ans = s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(seen[i][j] && s[i][j] != 'L') ans[i][j] = '+';
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
    s.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}