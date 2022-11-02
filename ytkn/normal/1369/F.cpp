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

using Arr = array<bool, 2>;

bool sub_solve(ll x, ll l, ll r, Arr win){
    if(l <= x){
        assert(x <= r);
        return win[x%2];
    }
    if(l <= 10){
        vector<bool> dp(l*2+1);
        for(int i = l; i <= l*2; i++) dp[i] = win[i%2];
        for(int i = l-1; i >= x; i--) {
            if(dp[i+1] && dp[i*2]) dp[i] = false;
            else dp[i] = true;
        }
        return dp[x];
    }
    if(win[0] && !win[1]){
        return win[x%2];
    }
    ll l1 = (l+1)/2, r1 = l-1;
    Arr nx_win;
    if(win[l%2] && win[0]) nx_win[r1%2] = false;
    else nx_win[r1%2] = true;

    if(nx_win[r1%2] && win[0]) nx_win[(r1+1)%2] = false;
    else nx_win[(r1+1)%2] = true;

    return sub_solve(x, l1, r1, nx_win);
}

const ll inf = 3e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    vector<int> ans(2);
    bool last_win = false;
    for(int i = n-1; i >= 0; i--){
        Arr win = {!last_win, !last_win};
        last_win = sub_solve(l[i], r[i]+1, inf, win);
    }
    ans[0] = last_win;
    last_win = true;
    for(int i = n-1; i >= 0; i--){
        Arr win = {!last_win, !last_win};
        last_win = sub_solve(l[i], r[i]+1, inf, win);
    }
    ans[1] = last_win;
    print_vector(ans);
}