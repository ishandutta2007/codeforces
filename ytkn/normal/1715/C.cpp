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

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = ((ll)n*(ll)(n+1))/2;
    auto f = [&](int i){
        ll l = i+1, r = n-i-1;
        return l*r;
    };
    for(int i = 0; i < n-1; i++){
        if(a[i] != a[i+1]){
            ans += f(i);
        }
    }
    while(m--){
        int i, x; cin >> i >> x; i--;
        if(i != 0 && a[i-1] != a[i]) ans -= f(i-1);
        if(i != n-1 && a[i] != a[i+1]) ans -= f(i);
        a[i] = x;
        if(i != 0 && a[i-1] != a[i]) ans += f(i-1);
        if(i != n-1 && a[i] != a[i+1]) ans += f(i);
        cout << ans << endl;
    }
}