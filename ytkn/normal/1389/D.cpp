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

void solve(){
    int n; ll k; cin >> n >> k;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l2 < l1){
        swap(l1, l2);
        swap(r1, r2);
    }
    ll intersect = max(0ll, min(r1, r2)-max(l1, l2));
    k -= intersect*n;
    if(k <= 0){
        cout << 0 << endl;
        return;
    }
    ll d = max(l2-r1, 0ll);
    ll ans = inf;
    auto calc = [&](int x){
        ll ans = d*x;
        ll rem = k;
        ll len = max(r1, r2)-min(l1, l2)-intersect;
        if(len*x >= rem) {
            ans += rem;
        }else{
            ans += len*x;
            rem -= len*x;
            ans += rem*2;
        }
        // cout << x << ":" << ans << endl;
        return ans;
    };
    for(int x = 1; x <= n; x++){
        chmin(ans, calc(x));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}