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

using P = pair<int, int>;
const ll INF = 1e18;

pair<vector<ll>, vector<ll>> norm(vector<ll> l, vector<ll> r){
    int n = l.size();
    assert(n == r.size());
    vector<bool> ok(n, true);
    vector<P> p(n);
    for(int i = 0; i < n; i++){
        p[i] = P(l[i], -r[i]);
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++){
        l[i] = p[i].first;
        r[i] = -p[i].second;
    }
    ll rmin = INF;
    for(int i = n-1; i >= 0; i--){
        if(rmin <= r[i]) ok[i] = false;
        chmin(rmin, r[i]);
    }
    vector<ll> al, ar;
    for(int i = 0; i < n; i++){
        if(ok[i]){
            al.push_back(l[i]);
            ar.push_back(r[i]);
        }
    }
    return make_pair(al, ar);
}

vector<ll> sub_solve(ll al, ll ar, vector<ll> l, vector<ll> r){
    if(l.empty()) return {0, 0, 0, 0};
    int m = l.size();
    assert(r.size() == m);
    vector<ll> ans(4);
    ans[0] = min(ar-r[0], l[m-1]-al);
    ans[1] = min((ar-r[0])*2, (l[m-1]-al));
    ans[2] = min((ar-r[0]), (l[m-1]-al)*2);
    ans[3] = min((ar-r[0])*2, (l[m-1]-al)*2);
    for(int i = 1; i < m; i++){
        chmin(ans[0], (l[i-1]-al)+(ar-r[i]));
        chmin(ans[1], (l[i-1]-al)+2*(ar-r[i]));
        chmin(ans[2], 2*(l[i-1]-al)+(ar-r[i]));
        chmin(ans[3], 2*(l[i-1]-al)+2*(ar-r[i]));
    }
    // cout << "====" << endl;
    // cout << al << ' ' << ar << endl;
    // for(int i = 0; i < m; i++) cout << l[i] << ':' << r[i] << ' ';
    // cout << endl;
    // print_vector(ans);
    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n+2, INF);
    a[0] = -INF;
    auto forbidden = vec2d(4, 4, false);
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            if((i&1) == 0 && (k&2) == 0) forbidden[i][k] = true;
        }
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> l_, r_;
    for(int i = 0; i < m; i++){
        ll lx, rx; cin >> lx >> rx;
        auto p = lower_bound(a.begin(), a.end(), lx);
        if(p != a.end() && *p <= rx) continue;
        l_.push_back(lx);
        r_.push_back(rx);
    }
    auto [l, r] = norm(l_, r_);
    m = l.size();
    assert(r.size() == m);
    
    auto dp = vec2d(n+2, 4, INF);
    for(int i = 0; i < 4; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++){
        int il = upper_bound(l.begin(), l.end(), a[i]) - l.begin();
        int ir = upper_bound(l.begin(), l.end(), a[i+1]) - l.begin();
        vector<ll> sl, sr;
        for(int j = il; j < ir; j++){
            sl.push_back(l[j]);
            sr.push_back(r[j]);
        }
        vector<ll> sa = {a[i], a[i+1]};
        auto v = sub_solve(a[i], a[i+1], sl, sr);
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(forbidden[j][k]) continue;
                chmin(dp[i+1][k], dp[i][j]+v[k]);
            }
        }
        // print_vector(dp[i+1]);
    }
    cout << *min_element(dp[n+1].begin(), dp[n+1].end()) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}