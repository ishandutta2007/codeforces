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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

using P = pair<int, int>;
using T = tuple<int, int, int>;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int asum = accumulate(a.begin(), a.end(), 0);
    // debug_value(asum)
    if(asum % n != 0){
        cout << -1 << endl;
        return;
    }
    int d = asum/n;
    vector<T> ans;
    for(int i = 2; i <= n; i++){
        int r = i - a[i]%i;
        if(r == i) r = 0;
        ans.push_back(T(1, i, r));
        a[1] -= r;
        a[i] += r;
        int x = a[i]/i;
        ans.push_back(T(i, 1, x));
        a[1] += x*i;
        a[i] -= x*i;
    }
    for(int i = 2; i <= n; i++){
        ans.push_back(T(1, i, d));
        a[1] -= d;
        a[i] += d;
    }
    cout << ans.size() << endl;
    for(auto [i, j, x]: ans) cout << i << ' ' << j << ' ' << x << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}