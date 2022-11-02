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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

using P = pair<ll, int>;

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    vector<int> p(2);
    vector<ll> t(2);
    for(int i = 0; i < 2; i++){
        cin >> p[i] >> t[i];
    }
    if(p[0] > p[1]){
        swap(p[0], p[1]);
        swap(t[0], t[1]);
    }
    int h, s; cin >> h >> s;
    vector<ll> damage = {max(0, p[0]-s), p[1]-s};
    vector<ll> min_time(h+1, inf);
    int a_max = 1;
    if(p[0] > s) a_max = ceil_div(h, p[0]-s);
    int b_max = ceil_div(h, p[1]-s);
    for(int a = 1; a <= a_max; a++){
        for(int b = 1; b <= b_max; b++){
            int sum = damage[0]*(a-1)+damage[1]*(b-1) + (p[0]+p[1]-s);
            if(a >= 1 && sum - p[0] >= h) continue;
            if(b >= 1 && sum - p[1] >= h) continue;
            chmin(sum, h);
            ll tt = max(t[0]*a, t[1]*b);
            chmin(min_time[sum], tt);
        }
    }
    vector<ll> dp(h+1, inf);
    dp[0] = 0;
    for(int x = 1; x <= h; x++){
        for(int d = 0; d <= h; d++){
            chmin(dp[min(d+x, h)], dp[d]+min_time[x]);
        }
    }
    int sum_damage = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    if(damage[0] > 0) que.push(P(t[0], 0));
    que.push(P(t[1], 1));
    min_time.assign(h+1, inf);
    min_time[0] = 0;
    while(true){
        auto [tt, idx] = que.top(); que.pop();
        sum_damage += damage[idx];
        if(sum_damage >= h){
            sum_damage = h;
        }
        min_time[sum_damage] = tt;
        if(sum_damage == h) break;
        que.push(P(tt+t[idx], idx));
    }
    ll ans = inf;
    for(int x = 0; x <= h; x++){
        for(int y = 0; y <= h; y++){
            if(x+y >= h) chmin(ans, dp[x]+min_time[y]);
        }
    }
    cout << ans << endl;
}