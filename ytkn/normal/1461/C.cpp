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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> index(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        index[a[i]] = i;
    }
    vector<double> p(n);
    for(int i = 0; i < m; i++){
        int r; double q; cin >> r >> q; r--;
        p[r] = 1.0-(1.0-p[r])*(1.0-q);
    }
    vector<int> mx(n);
    mx[0] = index[0];
    for(int i = 1; i < n; i++){
        mx[i] = max(index[i], mx[i-1]);
    }
    int last_idx = -1;
    for(int i = 0; i < n; i++){
        if(mx[i] == index[i]) continue;
        last_idx = i;
    }
    double ans = 1.0;
    if(last_idx != -1){
        double bad = 1.0;    
        for(int i = last_idx; i < n; i++){
            bad *= 1.0-p[i];
        }
        ans -= bad;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}