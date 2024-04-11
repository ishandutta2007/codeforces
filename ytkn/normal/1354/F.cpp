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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    vector<P> p(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        p[i] = P(b[i], i);
    }
    sort(p.begin(), p.end());
    auto dp = vec2d(n+1, k+1, -1);
    auto pre = vec2d(n+1, k+1, P(-1, -1));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        auto [_, idx] = p[i];
        for(int j = 0; j <= k; j++){
            if(dp[i][j] == -1) continue;
            // 
            if(chmax(dp[i+1][j], dp[i][j]+(k-1)*b[idx])){
                pre[i+1][j] = P(i, j);
            }
            // 
            if(j != k){
                if(chmax(dp[i+1][j+1], dp[i][j]+j*b[idx]+a[idx])){
                    pre[i+1][j+1] = P(i, j);
                }
            }
        }
    }
    vector<int> remain, erased;
    int i = n, j = k;
    while(true){
        if(i == 0) {
            assert(j == 0);
            break;
        }
        auto [pi, pj] = pre[i][j];
        int idx = p[pi].second;
        if(pj == j){
            erased.push_back(idx);
        }else{
            remain.push_back(idx);
        }
        i = pi;
        j = pj;
    }
    vector<int> ans;
    reverse(remain.begin(), remain.end());
    for(int i = 0; i < k-1; i++){
        ans.push_back(remain[i]+1);
    }
    for(int i: erased){
        ans.push_back(i+1);
        ans.push_back(-(i+1));
    }
    // debug_value(dp[n][k]);
    ans.push_back(remain.back()+1);
    cout << ans.size() << endl;
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}