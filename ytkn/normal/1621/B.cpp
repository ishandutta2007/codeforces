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
const int inf = 2e9;

void solve(){
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i] >> c[i];
    int l_min = inf, r_max = -inf;
    map<P, ll> mp;
    map<int, ll> mpl, mpr;
    for(int i = 0; i < n; i++){
        if(mpl.count(l[i])){
            chmin(mpl[l[i]], c[i]);
        }else{
            mpl[l[i]] = c[i];
        }
        if(mpr.count(r[i])){
            chmin(mpr[r[i]], c[i]);
        }else{
            mpr[r[i]] = c[i];
        }
        P p(l[i], r[i]);
        if(mp.count(p)){
            chmin(mp[p], c[i]);
        }else{
            mp[p] = c[i];
        }
        chmin(l_min, l[i]);
        chmax(r_max, r[i]);
        P pp(l_min, r_max);
        ll ans = mpl[l_min]+mpr[r_max];
        if(mp.count(pp)) chmin(ans, mp[pp]);
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}