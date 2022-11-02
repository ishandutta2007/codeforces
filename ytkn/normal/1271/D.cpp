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

using P = pair<int, int>;

int dp[5005][5005];
bool ok[5005][5005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<int> last_castle(n);
    iota(last_castle.begin(), last_castle.end(), 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        chmax(last_castle[v], u);
    }
    vector<vector<int>> gains(n);
    for(int i = 0; i < n; i++) {
        gains[last_castle[i]].push_back(c[i]);
    }
    ok[0][k] = true;
    for(int i = 0; i < n; i++){
        sort(gains[i].begin(), gains[i].end(), greater<int>());
        auto cumsum = Cumsum<int>(gains[i]);
        int m = gains[i].size();
        for(int j = a[i]; j <= 5000; j++){
            if(!ok[i][j]) continue;
            int k = j+b[i];
            for(int l = 0; l <= m && l <= k; l++){
                ok[i+1][k-l] = true;
                int sum = cumsum.sum(0, l);
                chmax(dp[i+1][k-l], dp[i][j]+sum);
            }
        }
    }
    int ans = -1;
    for(int i = 0; i <= 5000; i++){
        if(ok[n][i]) chmax(ans, dp[n][i]);
    }
    cout << ans << endl;
}