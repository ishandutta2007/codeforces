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

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, l, k; cin >> n >> l >> k;
    vector<ll> d(n), a(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    d.push_back(l);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto dp = vec2d(n+1, k+1, inf);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = dp[i-1][j]+(d[i]-d[i-1])*a[i-1];
            if(j == 0) continue;
            for(int p = 0; p <= i-2; p++){
                int removed = i-p-1;
                if(removed > j) continue;
                chmin(dp[i][j], dp[p][j-removed]+(d[i]-d[p])*a[p]);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}