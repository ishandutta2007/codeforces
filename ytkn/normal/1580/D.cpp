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
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    function<vector<ll>(int, int)> dfs = [&](int l, int r) -> vector<ll>{
        if(l == r){
            return {0ll};
        }
        ll min_value = inf;
        int min_idx = -1;
        for(int i = l; i < r; i++){
            if(chmin(min_value, a[i])) min_idx = i;
        }
        vector<ll> dpl = dfs(l, min_idx);
        vector<ll> dpr = dfs(min_idx+1, r);
        vector<ll> ans(r-l+1, -inf);
        for(ll x = 0; x <= min_idx-l; x++){
            for(ll y = 0; y <= r-min_idx-1; y++){
                // 
                chmax(ans[x+y], dpl[x]+dpr[y]-2ll*x*y*a[min_idx]);
                // 
                chmax(ans[x+y+1], dpl[x]+dpr[y]-2ll*(x*y+x+y)*a[min_idx]+a[min_idx]*(m-1));
            }
        }
        return ans;
    };
    auto v = dfs(0, n);
    cout << v[m] << endl;
}