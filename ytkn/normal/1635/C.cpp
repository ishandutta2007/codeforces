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

using T = tuple<int, int, int>;
using P = pair<int, int>;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[n-1] < a[n-2]){
        cout << -1 << endl;
        return;
    }
    P idx(n-2, n-1);
    int min_d = a[n-2]-a[n-1];
    vector<T> ans;
    for(int i = n-3; i >= 0; i--){
        if(min_d <= a[i+1]){
            auto [j, k] = idx;
            a[i] = min_d;
            ans.push_back(T(i, j, k));
        }else{
            if(a[i] > a[i+1]){
                cout << -1 << endl;
                return;
            }
        }
        int d = a[i]-a[i+1];
        if(chmin(min_d, d)){
            idx = P(i, i+1);
        }
    }
    cout << ans.size() << endl;
    for(auto [x, y, z]: ans) cout << x+1 << ' ' << y+1 << ' ' << z+1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}