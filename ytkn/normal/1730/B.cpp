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

using P = pair<double, double>;

void solve(){
    int n; cin >> n;
    vector<double> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    vector<double> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    auto f = [&](double tt){
        double l = -1e15, r = 1e15;
        for(int i = 0; i < n; i++){
            if(tt < t[i]) return P(1, -1);
            double rem = tt-t[i];
            chmax(l, x[i]-rem);
            chmin(r, x[i]+rem);
        }
        return P(l, r);
    };
    double l = 0, r = 1e9;
    int rem = 100;
    while(rem--){
        double tt = (l+r)/2;
        auto [xl, xr] = f(tt);
        if(xr >= xl) r = tt;
        else l = tt;
    }
    auto [xl, xr] = f(r);
    cout << xl << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}