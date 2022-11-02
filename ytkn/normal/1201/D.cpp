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
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<vector<int>> treasures(n);
    for(int i = 0; i < k; i++){
        int r, c; cin >> r >> c; c--; r--;
        treasures[r].push_back(c);
    }
    bool ok_zero = true;
    if(treasures[0].empty()){
        treasures[0].push_back(0);
        ok_zero = false;
    }
    vector<int> b(q);
    for(int i = 0; i < q; i++) {
        cin >> b[i]; b[i]--;
    }
    sort(b.begin(), b.end());
    vector<int> v;
    for(int i = 0; i < n; i++){
        sort(treasures[i].begin(), treasures[i].end());
        if(!treasures[i].empty()) v.push_back(i);
    }
    int sz = v.size();
    auto dp = vec2d(sz, 2, inf);
    if(!ok_zero){
        dp[0][0] = 0;
    }else{
        int l = treasures[0][0], r = treasures[0].back();
        dp[0][1] = r;
    }
    auto f = [&](int x, int y){
        if(x > y) swap(x, y);
        auto p = lower_bound(b.begin(), b.end(), x);
        int ans = 2*m;
        if(p != b.end()){
            int c = *p;
            ans = abs(c-x)+abs(y-c);
        }
        if(p != b.begin()){
            int c = *prev(p);
            chmin(ans, abs(c-x)+abs(y-c));
        }
        return ans;
    };
    // cout << "====" << endl;
    // cout << 0 << ":";
    // print_vector(dp[0]);
    for(int i = 0; i+1 < sz; i++){
        int c0 = v[i], l0 = treasures[c0][0], r0 = treasures[c0].back();
        int c1 = v[i+1], l1 = treasures[c1][0], r1 = treasures[c1].back();
        // cout << l0 << ' ' << r0 << endl;
        // cout << l1 << ' ' << r1 << endl;
        dp[i+1][0] = min({
            dp[i][0]+f(l0, r1)+(r1-l1),
            dp[i][1]+f(r0, r1)+(r1-l1)
        });
        dp[i+1][1] = min({
            dp[i][0]+f(l0, l1)+(r1-l1),
            dp[i][1]+f(r0, l1)+(r1-l1),
        });
        // cout << c1 << ":";
        // print_vector(dp[i+1]);
    }
    ll ans = min(dp[sz-1][0], dp[sz-1][1])+v.back();
    cout << ans << endl;
}