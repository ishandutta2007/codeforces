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
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> cumsum(n+1);
    vector<ll> cumxor(n+1);
    for(int i = 0; i < n; i++){
        cumsum[i+1] = cumsum[i]+a[i];
        cumxor[i+1] = cumxor[i]^a[i];
    }
    auto f = [&](int l, int r){
        return (cumsum[r]-cumsum[l]) - (cumxor[r]^cumxor[l]);
    };
    while(q--){
        int l, r; cin >> l >> r; l--;
        int l0 = l, r0 = r;
        ll mx = f(l, r);
        int j = l+1;
        for(int i = l; i < r; i++){
            chmax(j, i+1);
            while(j < r && f(i, j) < mx){
                j++;
            }
            if(f(i, j) == mx && j-i < r0-l0){
                l0 = i;
                r0 = j;
            }
        }
        cout << l0+1 << ' ' << r0 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}