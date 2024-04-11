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
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    ll x_min = *min_element(x.begin(), x.end());
    ll x_max = *max_element(x.begin(), x.end());
    ll y_min = *min_element(y.begin(), y.end());
    ll y_max = *max_element(y.begin(), y.end());
    ll ans3 = 0;
    for(ll xx: {x_min, x_max}){
        for(ll yy: {y_min, y_max}){
            for(int i = 0; i < n; i++){
                ll tmp = 2*(abs(x[i]-xx)+abs(y[i]-yy));
                chmax(ans3, tmp);
            }
        }
    }
    ll diff_sum = x_max-x_min + y_max-y_min;
    cout << ans3 << ' ';
    for(int i = 4; i <= n; i++){
        cout << diff_sum *2 << ' ';
    }
    cout << endl;
}