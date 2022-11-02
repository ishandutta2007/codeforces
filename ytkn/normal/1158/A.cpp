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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<ll> b(n), g(m);
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> g[i];
    ll max_b = *max_element(b.begin(), b.end());
    ll min_g = *min_element(g.begin(), g.end());
    if(min_g < max_b){
        cout << -1 << endl;
        return 0;
    }
    ll ans = accumulate(b.begin(), b.end(), 0ll)*m;
    sort(b.begin(), b.end(), greater<ll>());
    vector<ll> v;
    v.push_back(b[1]);
    for(int i = 0; i < m-1; i++) v.push_back(b[0]);
    // print_vector(v);
    for(int i = 0; i < m; i++){
        ans += g[i]-max_b;
        if(g[i] != max_b){
            ans += max_b;
            ans -= v.back();
            v.pop_back();
        }
    }
    cout << ans << endl;
}