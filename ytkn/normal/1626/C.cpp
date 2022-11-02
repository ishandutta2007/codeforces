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

ll tri(ll x){
    return (x*(x+1))/2;
}

const ll inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<ll> k(n+1), h(n+1);
    for(int i = 1; i <= n; i++) cin >> k[i];
    for(int i = 1; i <= n; i++) cin >> h[i];
    ll ans = 0;
    ll pre = 0;
    for(int i = 1; i <= n; i++){
        bool ok = true;
        ll x = inf;
        for(int j = i; j <= n; j++){
            if(k[j]-k[i-1] < h[j]) ok = false;
            chmin(x, k[j]-h[j]);
        }
        if(ok) pre = 0;
        if(pre == 0){
            assert(x >= k[i-1]);
            ans += tri(k[i]-x);
            pre = k[i]-x;
        }else{
            ll len = k[i]-k[i-1];
            ans += ((pre+1+pre+len)*len)/2;
            pre = pre+len;
        }
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