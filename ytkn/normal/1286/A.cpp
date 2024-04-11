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

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i]; p[i]--;
    }
    vector<int> cnt = {(n+1)/2, n/2};
    auto dp = vec3d(n+1, n+2, 2, INF);
    auto ok = [&](int i, int parity){
        if(p[i] == -1) return true;
        return p[i]%2 == parity;
    };
    if(ok(0, 0)) dp[0][1][0] = 0;
    if(ok(0, 1)) dp[0][0][1] = 0;
    for(int i = 1; i < n; i++){
        for(int cnt_even = 0; cnt_even <= cnt[0]; cnt_even++){
            for(int parity = 0; parity < 2; parity++){
                for(int nx = 0; nx < 2; nx++){
                    int add = parity == nx ? 0 : 1;
                    int nx_cnt = cnt_even + (nx == 0 ? 1 : 0);
                    if(ok(i, nx)) chmin(dp[i][nx_cnt][nx], dp[i-1][cnt_even][parity]+add);
                }
            }
        }
    }
    int ans = min(dp[n-1][cnt[0]][0], dp[n-1][cnt[0]][1]);
    cout << ans << endl;
}