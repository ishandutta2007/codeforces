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

void solve(){
    int n; ll k; cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        int p; cin >> p; p--;
        g[p].push_back(i);
    }
    vector<ll> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    map<P, ll> memo;
    function<ll(int, int)> solve = [&](int v, int cnt){
        P p(v, cnt);
        if(memo.count(p)) return memo[p];
        if(g[v].empty()){
            return s[v]*cnt;
        }
        int c = cnt/g[v].size();
        int rem = cnt%g[v].size();
        ll ans = 0;
        vector<ll> diffs;
        for(int to: g[v]){
            ll a = solve(to, c);
            ll b = a;
            if(rem > 0){
                b = solve(to, c+1);
            }
            ans += a;
            diffs.push_back(b-a);
        }
        sort(diffs.begin(), diffs.end(), greater<ll>());
        for(int i = 0; i < rem; i++) ans += diffs[i];
        ans += cnt*s[v];
        memo[p] = ans;
        return ans;
    };
    cout << solve(0, k) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}