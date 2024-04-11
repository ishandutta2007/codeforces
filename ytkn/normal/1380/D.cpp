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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    ll x, y; int k; cin >> x >> k >> y;
    vector<int> a(n), b(m);
    vector<int> pos_a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        pos_a[a[i]] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i]; b[i]--;
    }
    for(int i = 1; i < m; i++){
        if(pos_a[b[i-1]] > pos_a[b[i]]){
            cout << -1 << endl;
            return 0;
        }
    }
    auto get_a_val = [&](int i){
        if(i == -1) return -1;
        if(i == n) return -1;
        return a[i];
    };
    auto is_eraseble = [&](int l, int r) -> bool{
        if(r-l >= k) return true;
        int a_max = 0;
        for(int i = l; i < r; i++) chmax(a_max, a[i]);
        return a_max < max(get_a_val(l-1), get_a_val(r));
    };
    auto calc = [&](int l, int r) -> ll{
        ll ans = inf;
        int len = r-l;
        if(len >= k){
            // Fireball
            ans = (ll)(len/k)*x + (ll)(len%k)*y;
            // Berserk
            chmin(ans, x + (ll)(len-k)*y);
        }
        // Berserk
        int a_max = 0;
        for(int i = l; i < r; i++) chmax(a_max, a[i]);
        if(a_max < max(get_a_val(l-1), get_a_val(r))){
            chmin(ans, (ll)len*y);
        }
        // cout << "[" << l << ", " << r << ") " << ans << endl;
        return ans;
    };
    int l = 0;
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int r = pos_a[b[i]];
        if(l < r){
            if(!is_eraseble(l, r)) {
                cout << -1 << endl;
                return 0;
            }
            ans += calc(l, r);
        }
        l = r+1;
    }
    if(l != n){
        if(!is_eraseble(l, n)) {
            cout << -1 << endl;
            return 0;
        }
        ans += calc(l, n);
    }
    cout << ans << endl;
}