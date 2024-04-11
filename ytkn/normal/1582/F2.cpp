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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    int mx = 8191;
    vector<vector<int>> indices(5001);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        indices[a[i]].push_back(i);
    }
    vector<int> dp(mx+1, inf);
    vector<int> buf(mx+1);
    dp[0] = -1;
    for(int i = 1; i <= 5000; i++){
        if(indices[i].empty()) continue;
        for(int x = 0; x <= mx; x++) buf[x] = dp[x];
        for(int x = 0; x <= mx; x++){
            if(dp[x] < indices[i].back()){
                int j = *upper_bound(indices[i].begin(), indices[i].end(), dp[x]);
                chmin(buf[x^i], j);
            }
        }
        for(int x = 0; x <= mx; x++) dp[x] = buf[x];
    }
    vector<int> ans;
    for(int x = 0; x <= mx; x++){
        if(dp[x] != inf) ans.push_back(x);
    }
    cout << ans.size() << endl;
    print_vector(ans);

}