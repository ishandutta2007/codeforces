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
    int n; cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    auto calc = [&](int i){
        ll hh = 0;
        if(i != 0) chmax(hh, h[i-1]);
        if(i != n-1) chmax(hh, h[i+1]);
        return max(0ll, hh+1-h[i]);
    };
    if(n%2 == 1){
        ll ans = 0;
        for(int i = 1; i < n; i+=2){
            ans += calc(i);
        }
        cout << ans << endl;
        return;
    }
    vector<ll> from_left(n+1), from_right(n+1);
    for(int i = 0; i < n; i++){
        if(i%2 == 0) {
            from_left[i+1] = from_left[i];
        }else{
            from_left[i+1] = from_left[i]+calc(i);
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(i%2 == 0) {
            from_right[i] = from_right[i+1]+calc(i);
        }else{
            from_right[i] = from_right[i+1];
        }
    }
    ll ans = inf;
    for(int i = 1; i <= n; i+=2){
        chmin(ans, from_left[i]+from_right[i]);
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