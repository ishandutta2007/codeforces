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

using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;

T calc_line(ll x1, ll y1, ll x2, ll y2){
    ll a = y2-y1;
    ll b = x1-x2;
    ll c = y1*x2-x1*y2;
    if(a < 0){
        a *= -1;
        b *= -1;
        c *= -1;
    }else if(a == 0){
        if(b < 0){
            b *= -1;
            c *= -1;
        }
    }
    ll g = gcd(gcd(a, b), c);
    a /= g;
    b /= g;
    c /= g;
    return T(a, b, c);
}

ll tri(ll x){
    return (x*(x-1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    map<P, set<T>> mp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            auto l = calc_line(x[i], y[i], x[j], y[j]);
            auto [a, b, c] = l;
            ll g = gcd(a, b);
            P p(a/g, b/g);
            mp[p].insert(l);
        }
    }
    int m = 0;
    for(auto [l, st]: mp) m += st.size();
    ll ans = tri(m);
    for(auto [l, st]: mp) {
        ans -= tri(st.size());
    }
    cout << ans << endl;
}