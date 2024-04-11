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

struct node{
    ll sum, left, right, any;
    node(ll sum, ll left, ll right, ll any): sum(sum), left(left), right(right), any(any) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(1<<n);
    for(int i = 0; i < (1<<n); i++) cin >> a[i];
    vector<vector<node>> dp(1<<(n+1));
    function<void(int, int, int)> dfs = [&](int l, int r, int idx){
        dp[idx].assign(r-l, node(0, 0, 0, 0));
        if(r == l+1){
            ll mx = max(a[l], 0ll);
            dp[idx][0] = node(a[l], mx, mx ,mx);
            return;
        }
        int c = (l+r)/2;
        int lhs = idx*2+1, rhs = idx*2+2;
        dfs(l, c, lhs);
        dfs(c, r, rhs);
        int len = r-l;
        for(int x = 0; x < len/2; x++){ // bitx
            ll sum = dp[lhs][x].sum + dp[rhs][x].sum;
            { // 0()
                ll lft = max(dp[lhs][x].left, dp[lhs][x].sum+dp[rhs][x].left);
                ll rgt = max(dp[rhs][x].right, dp[rhs][x].sum+dp[lhs][x].right);
                ll any = max({dp[lhs][x].any, dp[rhs][x].any, dp[lhs][x].right+dp[rhs][x].left});
                dp[idx][x] = node(sum, lft, rgt, any);
            }
            {
                ll lft = max(dp[rhs][x].left, dp[rhs][x].sum+dp[lhs][x].left);
                ll rgt = max(dp[lhs][x].right, dp[lhs][x].sum+dp[rhs][x].right);
                ll any = max({dp[lhs][x].any, dp[rhs][x].any, dp[rhs][x].right+dp[lhs][x].left});
                dp[idx][x+len/2] = node(sum, lft, rgt, any);
            }
        }
    };
    dfs(0, 1<<n, 0);
    // for(int x = 0; x < (1<<n); x++) cout << dp[0][x].any << ' ';
    // cout << endl;
    int x = 0;
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        x ^= 1<<k;
        cout << dp[0][x].any << '\n';
    }
}