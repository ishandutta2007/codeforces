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

vector<ll> prime_facs(ll n){
    ll m = n;
    vector<ll> ans;
    for(ll p = 2; p*p <= n; p++){
        if(m%p == 0){
            ans.push_back(p);
            while(m%p == 0) m /= p;
        }
    }
    if(m != 1) ans.push_back(m);
    return ans;
}

void solve(){
    ll a, m; cin >> a >> m;
    ll g = gcd(a, m);
    a /= g; m /= g;
    auto ps = prime_facs(m);
    int n = ps.size();
    auto count = [&](ll p) -> ll{
        return (a+m-1)/p - (a-1)/p;
    };
    ll ans = 0;
    for(int s = 0; s < (1<<n); s++){
        ll p = 1;
        ll sgn = 1;
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) {
                p *= ps[i];
                sgn *= -1;
            }
        }
        ans += sgn*count(p);
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