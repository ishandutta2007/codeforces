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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    auto c = a, d = b;
    vector<int> rem(n, m);
    for(int i = 0; i < n; i++){
        c[i] -= max(0, m-b[i]);
        d[i] -= max(0, m-a[i]);
        rem[i] -= (a[i]-c[i]) + (b[i]-d[i]);
    }
    ll csum = accumulate(c.begin(), c.end(), 0ll);
    ll dsum = accumulate(d.begin(), d.end(), 0ll);
    for(int i = 0; i < n; i++){
        if(csum > dsum){
            ll diff = csum-dsum;
            ll x = min(diff, (ll)rem[i]);
            rem[i] -= x;
            c[i] -= x;
            csum -= x;
        }else if(dsum > csum){
            ll diff = dsum-csum;
            ll x = min(diff, (ll)rem[i]);
            rem[i] -= x;
            d[i] -= x;
            dsum -= x;
        }
        if(rem[i] > 0){
            c[i] -= rem[i]/2;
            csum -= rem[i]/2;
            d[i] -= (rem[i]+1)/2;
            dsum -= (rem[i]+1)/2;
        }
    }
    cout << abs(dsum - csum) << endl;
    for(int i = 0; i < n; i++){
        cout << a[i]-c[i] << ' ' << b[i]-d[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}