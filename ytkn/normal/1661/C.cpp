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

void solve(){
    int n; cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    int h_max = *max_element(h.begin(), h.end());
    auto days = [&](int i, ll x){
        ll c = (x-h[i])/3;
        ll rem = (x-h[i])%3;
        if(rem == 0) return c*2;
        if(rem == 1) return c*2+1;
        if(rem == 2) return c*2+2;
    };
    auto calc = [&](ll x){
        ll odd = 0, even = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            ll c = (x-h[i])/2;
            sum += (x-h[i]);
            ll rem = (x-h[i])%2;
            even += c;
            if(rem == 1) odd++;
        }
        if(even > odd){
            ll p = sum/3;
            if(sum%3 == 0) return p*2;
            if(sum%3 == 1) return p*2+1;
            if(sum%3 == 2) return p*2+2;
        }else{
            return max(odd*2-1, even*2);
        }
    };
    ll ans = calc(h_max);
    chmin(ans, calc(h_max+1));
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}