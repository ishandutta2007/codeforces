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
    ll n, k; cin >> n >> k;
    auto count = [&](ll l, ll r){
        chmax(l, 1ll);
        chmin(r, n);
        return max(r-l+1, 0ll);
    };
    function<ll(ll)> count_prefix = [&](ll p)->ll{
        ll p0 = p;
        ll p1 = p+1;
        ll ans = 0;
        while(p0 <= inf){
            ans += count(p0, p1-1);
            p0 <<= 1;
            p1 <<= 1;
        }
        if(p%2 == 0) ans += count_prefix(p+1);
        return ans;
    };
    auto max_even = [&](){
        ll l = 1, r = n/2;
        if(count_prefix(2*l) < k) return -1ll;
        if(count_prefix(2*r) >= k) return 2*r;
        while(r-l > 1){
            ll p = (l+r)/2;
            if(count_prefix(2*p) >= k){
                l = p;
            }else{
                r = p;
            }
        }
        return 2*l;
    };
    auto max_odd = [&](){
        ll l = 0, r = n/2;
        if(count_prefix(2*l+1) < k) {
            return -1ll;
        }
        if(count_prefix(2*r+1) >= k) return 2*r+1;
        while(r-l > 1){
            ll p = (l+r)/2;
            if(count_prefix(2*p+1) >= k){
                l = p;
            }else{
                r = p;
            }
        }
        return 2*l+1;
    };
    cout << max(max_even(), max_odd()) << endl;
}