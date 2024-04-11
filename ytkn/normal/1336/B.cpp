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

const ll inf = 4e18;

void solve(){
    vector<int> n(3);
    for(int i = 0; i < 3; i++) cin >> n[i];
    vector<vector<ll>> w(3);
    for(int i = 0; i < 3; i++){
        w[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++){
            cin >> w[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        sort(w[i].begin(), w[i].end());
    }
    auto calc = [&](ll x, ll y, ll z){
        ll ans = 0;
        ans += (x-y)*(x-y);
        ans += (y-z)*(y-z);
        ans += (z-x)*(z-x);
        return ans;
    };
    ll ans = inf;
    vector<int> v = {0, 1, 2};
    do{
        int i = v[0], j = v[1], k = v[2];
        for(ll x: w[i]){
            if(w[j][0] > x) continue;
            if(w[k].back() < x) continue;
            auto pl = upper_bound(w[j].begin(), w[j].end(), x);
            ll l = *prev(pl);
            auto pr = lower_bound(w[k].begin(), w[k].end(), x);
            ll r = *pr;
            chmin(ans, calc(x, l, r));
        }

    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}