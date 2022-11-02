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
    ll x1, y1; cin >> x1 >> y1;
    ll x2, y2; cin >> x2 >> y2;
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> dx(n+1), dy(n+1);
    for(int i = 0; i < n; i++){
        char c = s[i];
        dx[i+1] = dx[i];
        dy[i+1] = dy[i];
        if(c == 'U') dy[i+1] = dy[i]+1;
        if(c == 'D') dy[i+1] = dy[i]-1;
        if(c == 'L') dx[i+1] = dx[i]-1;
        if(c == 'R') dx[i+1] = dx[i]+1;
    }
    auto ok = [&](int i, ll t){
        ll x = x1 + dx[i] + dx[n]*t;
        ll y = y1 + dy[i] + dy[n]*t;
        ll dist = abs(x2-x) + abs(y2-y);
        return dist <= n*t+i;
    };
    ll ans = inf;
    for(int i = 1; i <= n; i++){
        if(ok(i, 0)) {
            chmin(ans, (ll)i);
            continue;
        }
        ll l = 0, r = 1e10;
        if(!ok(i, r)) continue;
        while(r-l > 1){
            ll t = (l+r)/2;
            if(ok(i, t)) r = t;
            else l = t;
        }
        chmin(ans, r*n+i);
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}