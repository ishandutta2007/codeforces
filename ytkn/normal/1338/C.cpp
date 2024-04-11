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



const vector<vector<ll>> v = {
    {0, 0, 0},
    {1, 2, 3},
    {2, 3, 1},
    {3, 1, 2}
};

vector<ll> calc(ll k){
    if(k < 4) return v[k];
    ll r = k%4;
    auto u = calc(k/4);
    for(int i = 0; i < 3; i++) u[i] = u[i]*4+v[r][i];
    return u;
}

ll solve(ll n){
    if(n <= 3) return n;
    int cnt = 0;
    ll r = (n-1)%3;
    ll m = n;
    ll x = 1;
    while(m >= 4){
        cnt++;
        m /= 4;
        x *= 4;
    }
    ll k = (n-x)/3;
    ll ans = calc(k)[r];
    if(r == 0) ans += 1ll<<(2*cnt);
    if(r == 1) ans += 1ll<<(2*cnt+1);
    if(r == 2) {
        ans += 1ll<<(2*cnt);
        ans += 1ll<<(2*cnt+1);
    }
    return ans;
}

vector<ll> test(int n){
    set<ll> used;
    vector<ll> v;
    auto find_a = [&](){
        for(ll x = 1; ; x++){
            if(!used.count(x)) return x;
        }
    };
    auto find_b = [&](ll a){
        for(ll x = a+1; ; x++){
            if(used.count(x)) continue;
            if(used.count(a^x)) continue;
            return x;
        }
    };
    for(int i = 0; i < n; i++){
        ll a = find_a();
        ll b = find_b(a);
        ll c = a^b;
        // cout << a << ' ' << b << ' ' << c << endl;
        used.insert(a);
        used.insert(b);
        used.insert(c);
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
    }
    return v;
}

// auto u = test(1000);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    // for(int n = 1; n <= 999; n++) {
    //     if(solve(n) != u[n-1]) cout << n << endl;
    // }
    while(t--){
        ll n; cin >> n;
        cout << solve(n) << endl;
    }
    // print_vector(v[1]);
    // print_vector(v[1]);
    // print_vector(calc(5));
}