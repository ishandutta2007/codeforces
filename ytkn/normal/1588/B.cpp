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
#include <random>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

random_device rnd;
mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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

class Simulator{
    public:
    int n;
    int i, j, k;
    Simulator(int n): n(n) {

    }
};

ll tri(ll n){
    return (n*(n-1))/2;
}

ll tri_inv(ll x){
    ll r = 2e9, l = 0;
    while(r-l > 1){
        ll c = (l+r)/2;
        if(tri(c) >= x) r = c;
        else l = c;
    }
    return r;
}

void solve(){
    ll n; cin >> n;
    auto ask = [&](ll l, ll r){
        cout << "? " << l+1 << ' ' << r+1 << endl;
        ll x; cin >> x;
        return x;
    };
    auto verify = [&](ll i, ll j, ll k){
        cout << "! " << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
    };
    ll total = ask(0, n-1);
    ll l = 0, r = n-1;
    while(r-l > 1){
        ll x = (l+r)/2;
        if(ask(0, x) == total) r = x;
        else l = x;
    }
    ll k = r;
    ll slide = ask(0, k-1);
    ll j = k-(total-slide);
    ll len = tri_inv(total - tri(k-j+1));
    ll i = j-len;
    verify(i, j, k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}