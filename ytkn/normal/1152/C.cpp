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

vector<ll> divs(ll n){
    vector<ll> ans;
    for(ll x = 1; x*x <= n; x++){
        if(n%x == 0){
            ans.push_back(x);
            if(x*x != n) ans.push_back(n/x);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll a, b; cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    if(b > a) swap(a, b);
    ll min_lcm = 4e18;
    ll ans = -1;
    auto v = divs(a-b);
    for(ll d: v){
        ll r = a%d;
        ll k = (d-r)%d;
        if(chmin(min_lcm, lcm(a+k, b+k))) ans = k;
    }
    cout << ans << endl;
}