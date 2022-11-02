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

const ll inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<ll> t(n), x(n);
    for(int i = 0; i < n; i++){
        cin >> t[i] >> x[i];
    }
    t.push_back(inf);
    ll end_time = 0;
    ll start_time = 0;
    ll start_pos = 0;
    ll target_pos = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(end_time > t[i]) {
            ll dx = start_pos < target_pos ? 1 : -1;
            auto calc_pos = [&](ll t){
                return start_pos + dx*(t-start_time);
            };
            ll pos_at_t = calc_pos(t[i]);
            ll pos_at_t_next = end_time < t[i+1] ? calc_pos(end_time) : calc_pos(t[i+1]);
            ll l = min(pos_at_t, pos_at_t_next);
            ll r = max(pos_at_t, pos_at_t_next);
            if(l <= x[i] && x[i] <= r) {
                ans++;
            }
            continue;
        }
        ll dx = x[i]-target_pos;
        start_time = t[i];
        end_time = t[i]+abs(dx);
        if(end_time <= t[i+1]) {
            ans++;
        }
        start_pos = target_pos;
        target_pos = x[i];
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