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

const double inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int y_max = *max_element(y.begin(), y.end());
    int y_min = *min_element(y.begin(), y.end());
    if(y_min < 0 && y_max > 0){
        cout << -1 << endl;
        return 0;
    }
    if(y_max < 0){
        for(int i = 0; i < n; i++) y[i] *= -1;
        y_max = *max_element(y.begin(), y.end());
        y_min = *min_element(y.begin(), y.end());
    }
    auto ok = [&](double r){
        double l_max = -inf, r_min = inf;
        for(int i = 0; i < n; i++){
            double s = sqrt((double)y[i]*(2*r-(double)y[i]));
            double l = x[i]-s, r = x[i]+s;
            chmax(l_max, l);
            chmin(r_min, r);
        }
        return l_max <= r_min;
    };
    double l = y_max*0.5, r = 1e18;
    int rem = 100;
    while(rem--){
        double x = (l+r)/2;
        if(ok(x)) r = x;
        else l = x;
    }
    cout << r << endl;
}