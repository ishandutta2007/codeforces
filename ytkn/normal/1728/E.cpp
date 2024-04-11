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


/**
 * ax + by = gcd(a, b)(x, y)gcd(a, b)
 */ 
template <typename T>
T extGCD(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int m; cin >> m;
    vector<ll> x(m), y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    vector<ll> ans(m);
    vector<ll> tastiness(n+1);
    priority_queue<ll> gains;
    for(int i = 0; i < n; i++){
        tastiness[0] += b[i];
        gains.push(a[i]-b[i]);
    }
    for(int x = 1; x <= n; x++){
        ll g = gains.top(); gains.pop();
        tastiness[x] = tastiness[x-1] + g;
    }
    for(int i = 0; i < m; i++){
        ll lc = lcm(x[i], y[i]);
        ll a, b;
        ll g = extGCD(x[i], y[i], a, b);
        if(n%g != 0) {
            ans[i] = -1;
            continue;
        }
        a *= n/g;
        b *= n/g;
        ll da = lc/x[i];
        ll db = lc/y[i];
        if(a < 0){
            ll cnt = ceil_div(-a, da);
            a += da*cnt;
            b -= db*cnt;
        }
        if(a >= da){
            ll cnt = a/da;
            a -= da*cnt;
            b += db*cnt;
        }
        if(x[i]*a > n){
            ans[i] = -1;
            continue;
        }
        if(a*x[i]+lc > n){
            ans[i] = tastiness[a*x[i]];
            continue;
        }
        auto to_idx = [&](int s){
            return a*x[i]+s*lc;
        };
        int r = (n-a*x[i])/lc;
        int l = 0;
        if(tastiness[to_idx(l)] >= tastiness[to_idx(l+1)]){
            ans[i] = tastiness[to_idx(l)];
            continue;
        }
        while(r-l > 1){
            int s = (l+r)/2;
            if(tastiness[to_idx(s)] < tastiness[to_idx(s+1)]) l = s;
            else r = s;
        }
        ans[i] = tastiness[to_idx(l+1)];
    }
    print_vector(ans, '\n');
}