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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    reverse(b.begin(), b.end());
    ll ans = 0;
    auto imos = vec2d(2, n+1, 0ll);
    ll x = ceil_div(b[0], (ll)k);
    imos[0][0] = -x;
    imos[0][k] = x;
    imos[1][0] = x*k;
    imos[1][k] = -x;
    ans += x;
    for(int i = 1; i+k <= n; i++){
        imos[0][i] += imos[0][i-1];
        imos[1][i] += imos[1][i-1]+imos[0][i];
        if(imos[1][i] < b[i]){
            ll x = ceil_div(b[i]-imos[1][i], (ll)k);
            ans += x;
            imos[0][i] -= x;
            imos[0][i+k] += x;
            imos[1][i] += x*k;
            imos[1][i+k] += -x;
        }
    }
    int l = n-k;
    ll mx = 0;
    for(int i = n-k+1; i < n; i++){
        ll x = k-(i-l);
        imos[0][i] += imos[0][i-1];
        imos[1][i] += imos[1][i-1]+imos[0][i];
        if(imos[1][i] < b[i]){
            chmax(mx, ceil_div(b[i]-imos[1][i], x));
        }
    }
    ans += mx;
    cout << ans << endl;
}