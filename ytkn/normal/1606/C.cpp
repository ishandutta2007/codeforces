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

ll pow10[10];

void solve(){
    int n;ll k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll rem = k+1;
    vector<ll> v(n);
    for(int i = 0; i < n-1; i++){
        int d = a[i+1]-a[i];
        if(rem >= pow10[d]-1){
            v[i] = pow10[d]-1;
            rem -= pow10[d]-1;
        }else{
            v[i] = rem;
            rem = 0;
        }
    }
    v[n-1] = rem;
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += v[i]*pow10[a[i]];
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    pow10[0] = 1;
    for(int i = 1; i < 10; i++){
        pow10[i] = pow10[i-1]*10;
    }
    int t; cin >> t;
    while(t--) solve();
}