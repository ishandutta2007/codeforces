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

int msb(ll x){
    for(int i = 60; i >= 0; i--){
        if(x&(1ll<<i)) return i;
    }
}

set<ll> written;
vector<string> ans;
int called = 0;

void clear(){
    written.clear();
    called = 0;
    ans.clear();
}


void put(ll x){
    assert(x <= 5e18);
    written.insert(x);
}

ll write_xor(ll a, ll b){
    called++;
    assert(written.count(a));
    assert(written.count(b));
    put(a^b);
    ans.push_back(to_string(a)+" ^ "+to_string(b));
    return a^b;
}

ll write_add(ll a, ll b){
    called++;
    assert(written.count(a));
    assert(written.count(b));
    put(a+b);
    ans.push_back(to_string(a)+" + "+to_string(b));
    return a+b;
}

ll times(ll a, ll n){ // create a*n
    ll ans = 0;
    ll prod = a*n;
    while (n > 0) {
        if (n&1) ans = write_add(ans, a);
        a = write_add(a, a);
        n >>= 1;
    }
    assert(ans == prod);
    return ans;
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

void verify(){
    assert(written.count(1));
    assert(called <= 100000);
}

void output(){
    cout << ans.size() << endl;
    print_vector(ans, '\n');
}

void solve(ll x){
    clear();
    written.insert(x);
    write_xor(x, x);
    int m = msb(x);
    ll y = times(x, 1<<m);
    ll z = write_xor(x, y);
    assert(gcd(z, x) == 1);
    ll a, b;
    extGCD(x, z, a, b);
    a = abs(a);
    b = abs(b);
    ll s = times(x, a);
    ll t = times(z, b);
    if(s > t) swap(s, t);
    if(s%2 == 1){
        s = write_add(s, x);
        t = write_add(t, x);
    }
    write_xor(s, t);
    output();
    verify();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll x; cin >> x;
    solve(x);
}