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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

const int inf = 1e9;

int dp[255][255][255];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto cumsum = Cumsum<int>(a);
    for(int i = 0; i < n; i++){
        for(int sum = 0; sum <= m; sum++){
            for(int last = 0; last <= m; last++){
                dp[i][sum][last] = inf;
            }
        }
    }
    for(int sum = 0; sum <= m; sum++){
        dp[0][sum][sum] = abs(a[0]-sum);
    }
    for(int i = 0; i+1 < n; i++){
        int sum_to_i1 = cumsum.sum(0, i+2);
        for(int sum = 0; sum <= m; sum++){
            for(int last = 0; last*(i+1) <= sum; last++){
                for(int nx = 0; nx <= last && sum+nx <= m; nx++){
                    int add = abs(sum_to_i1-sum-nx);
                    chmin(dp[i+1][sum+nx][nx], dp[i][sum][last]+add);
                }
            }
        }
    }
    int ans = inf;
    for(int last = 0; last <= m; last++){
        chmin(ans, dp[n-1][m][last]);
    }
    cout << ans << endl;
}