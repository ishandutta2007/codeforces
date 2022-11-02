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

void solve(){
    int n, m; cin >> n >> m;
    auto a = vec2d(m, n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> a[j][i];
        }
    }
    vector<P> vp(m);
    for(int i = 0; i < m; i++){
        int mx = *max_element(a[i].begin(), a[i].end());
        vp[i] = P(mx, i);
    }
    sort(vp.begin(), vp.end(), greater<P>());
    m = min(m, n);
    auto mx = vec2d(m, 1<<n, 0);
    for(int i = 0; i < m; i++){
        int l = vp[i].second;
        for(int j = 0; j < n; j++){
            for(int s = 0; s < (1<<n); s++){
                int sum = 0;
                for(int k = 0; k < n; k++){
                    if(s&(1<<k)){
                        int idx = (j+k)%n;
                        sum += a[l][idx];
                    }
                }
                chmax(mx[i][s], sum);
            }
        }
    }
    int all_bits = (1<<n)-1;
    auto dp = vec2d(m+1, 1<<n, 0);
    for(int i = 0; i < m; i++){
        for(int s = 0; s < (1<<n); s++){
            int rem = all_bits-s;
            for(int t = rem; t >= 0; t = (t-1)&rem){
                chmax(dp[i+1][s+t], dp[i][s]+mx[i][t]);
                if(t == 0) break;
            }
        }
    }
    cout << dp[m][(1<<n)-1] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}