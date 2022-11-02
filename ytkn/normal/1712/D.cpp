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
#include <random>

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

ll solve(int n, int k, vector<ll> a){
    const ll mx = 1000000000;
    auto ok = [&](ll x){
        if(x > mx) return false;
        int cnt = 0;
        auto b = a;
        for(int i = 0; i < n; i++){
            if(a[i]*2 < x) {
                cnt++;
                b[i] = mx;
            }
        }
        if(cnt > k) return false;
        for(int i = 0; i < n-1; i++){
            int should_change = 0;
            if(b[i] < x) should_change++;
            if(b[i+1] < x) should_change++;
            if(cnt+should_change <= k) return true;
        }
        return false;
    };
    ll l = 0, r = 1e18;
    while(r-l > 1){
        ll x = (l+r)/2;
        if(ok(x)) l = x;
        else r = x;
    }
    return l;
}

const ll INF = 1e+15;

vector<vector<ll>> warshallfloyd(vector<vector<ll>> g){
    int n = g.size();
    vector<vector<ll>> dist(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = g[i][j];
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ll new_len = dist[j][i] + dist[i][k];
                dist[j][k] = min(new_len, dist[j][k]);
            }
        }
    }
    return dist;
}

int calc(vector<ll> a){
    int n = a.size();
    auto g = vec2d(n, n, INF);
    for(int l = 0; l < n; l++){
        ll mn = a[l];
        for(int r = l+1; r < n; r++){
            chmin(mn, a[r]);
            g[l][r] = mn;
            g[r][l] = mn;
        }
    }
    auto d = warshallfloyd(g);
    ll mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            chmax(mx, d[i][j]);
        }
    }
    return mx;
}

void test(int n, int k){
    const ll mx = 1000000000;
    int iter = 10;
    while(iter--){
        vector<ll> v(n);
        for(int i = 0; i < n; i++) v[i] = (rand()%mx)+1;
        ll ans = 0;
        for(int s = 0; s < (1<<n); s++){
            auto u = v;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(s&(1<<i)){
                    cnt++;
                    u[i] = mx;
                }
            }
            if(cnt > k) continue;
            ll tmp = calc(u);
            chmax(ans, tmp);
        }
        cout << ans << ' ' << solve(n, k, v) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // int n, k; cin >> n >> k;
    // test(n, k);
    // return 0;
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, k, a) << endl;
    }
}