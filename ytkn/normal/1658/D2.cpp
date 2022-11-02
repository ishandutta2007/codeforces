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

int sub_solve(int l, int r, vector<int> a){
    int n = r-l;
    if(n%2 == 1){
        int x1 = 0;
        for(int x: a) x1 ^= x;
        int x2 = 0;
        for(int x = l; x < r; x++) x2 ^= x;
        return x2^x1;
    }
    if(l%2 == 0){
        vector<int> b;
        for(int x: a){
            if(x%2 == 0) b.push_back(x/2);
        }
        return sub_solve(l/2, r/2, b)*2;
    }
    vector<int> v;
    for(int i = 0; i < n; i++){
        bool ok = false;
        if(i >= 1 && a[i-1]/2 == a[i]/2) ok = true;
        if(i+1 < n && a[i]/2 == a[i+1]/2) ok = true;
        if(!ok) v.push_back(a[i]);
    }
    vector<int> u(n);
    int c1 = l^v[0];
    int c2 = (r-1)^v[0];
    if(c1 < (1<<17)){
    for(int i = l; i < r; i++) u[i-l] = c1^i;
        sort(u.begin(), u.end());
        if(a == u) return c1;
    }
    return c2;
}

pair<vector<int>, int> make_data(int l, int r){
    int a = 100;
    vector<int> v;
    for(int x = l; x < r; x++) v.push_back(a^x);
    return make_pair(v, a);
}

void solve(){
    int l, r; cin >> l >> r;
    r++;
    int n = r-l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // auto [a, x] = make_data(l, r);
    sort(a.begin(), a.end());
    int ans = sub_solve(l, r, a);
    vector<int> v(n);
    for(int i = l; i < r; i++) v[i-l] = i^ans;
    sort(v.begin(), v.end());
    assert(a == v);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}