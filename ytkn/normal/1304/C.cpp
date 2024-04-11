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
    int n, m; cin >> n >> m;
    vector<T> vt(n);
    for(int i = 0; i < n; i++){
        int t, l, r; cin >> t >> l >> r;
        vt[i] = T(t, l, r);
    }
    sort(vt.begin(), vt.end());
    P p(m, m);
    int prev_t = 0;
    for(auto [t, l, r]: vt){
        int len = t-prev_t;
        auto [tl, tr] = p;
        tl -= len;
        tr += len;
        chmax(tl, l);
        chmin(tr, r);
        if(tr < tl){
            cout << "NO" << endl;
            return;
        }
        prev_t = t;
        p = P(tl, tr);
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}