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
    int x, n; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = n-x, r = x;
    if(l >= r){
        cout << "YES" << endl;
        return;
    }
    vector<int> u, v;
    for(int i = 0; i < l; i++) u.push_back(a[i]);
    for(int i = l; i < r; i++) v.push_back(a[i]);
    for(int i = r; i < n; i++) u.push_back(a[i]);
    sort(a.begin(), a.end());
    sort(u.begin(), u.end());
    vector<int> b;
    for(int i = 0; i < l; i++) b.push_back(u[i]);
    for(int i = l; i < r; i++) b.push_back(v[i-l]);
    for(int i = r; i < n; i++) b.push_back(u[i-(r-l)]);
    if(a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}