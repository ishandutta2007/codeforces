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

int calc(vector<vector<int>> v){
    int n = v.size(), m = v[0].size();
    auto cumsum = vec2d(n+1, m+1, 0);
    auto filpped = vec2d(n, m, false);
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            int cnt = cumsum[i][j+1]+cumsum[i+1][j]-cumsum[i+1][j+1];
            cumsum[i][j] = cumsum[i][j+1]+cumsum[i+1][j]-cumsum[i+1][j+1];
            if((v[i][j])^(cnt%2)){
                filpped[i][j] = true;
                cumsum[i][j]++;
                ans++;
            }
        }
    }
    bool dec = false;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            if(filpped[i][j] && filpped[i][m-1] && filpped[n-1][j] && filpped[n-1][m-1]){
                dec = true;
            }
        }
    }
    if(dec) ans--;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    auto v = vec2d(n, m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'B') v[i][j] = 1;
        }
    }
    int ans = calc(v);
    cout << ans << endl;
}