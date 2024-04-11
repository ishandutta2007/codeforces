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
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    auto a_min = [&](int i){
        ll ans = inf;
        for(int j = 0; j < n; j++) chmin(ans, abs(a[i]-b[j]));
        return ans;
    };
    auto b_min = [&](int i){
        ll ans = inf;
        for(int j = 0; j < n; j++) chmin(ans, abs(b[i]-a[j]));
        return ans;
    };
    ll a_min_l = a_min(0);
    ll a_min_r = a_min(n-1);
    ll b_min_l = b_min(0);
    ll b_min_r = b_min(n-1);
    auto calc = [&](int i, int j){
        return abs(a[i]-b[j]);
    };
    ll ans = inf;
    vector<int> v = {-1, 0, n-1};
    for(int i: v){
        for(int j: v){
            ll tmp = 0;
            if(i != -1){
                tmp += calc(0, i);
            }else{
                tmp += a_min_l;
            }
            if(j != -1){
                tmp += calc(n-1, j);
            }else{
                tmp += a_min_r;
            }
            if(i != 0 && j != 0) tmp += b_min_l;
            if(i != n-1 && j != n-1) tmp += b_min_r;
            chmin(ans, tmp);
        }
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