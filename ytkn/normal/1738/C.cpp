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

void solve(){
    int n; cin >> n;
    vector<int> cnt(2);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x < 0) x *= -1;
        cnt[x%2]++;
    }
    auto ok = vec3d(cnt[0]+1, cnt[1]+1, 2, false);
    auto dp = vec3d(cnt[0]+1, cnt[1]+1, 2, false);
    function<bool(int, int, int)> solve = [&](int even, int odd, int p){
        int sum = odd%2;
        if(even+odd == 0){
            return p == 0;
        }
        if(ok[even][odd][p]) return dp[even][odd][p] == true;
        bool ans = false;
        if(even > 0){
            if(!solve(even-1, odd, sum^p^1)) ans = true;
        }
        if(odd > 0){
            if(!solve(even, odd-1, sum^p^1)) ans = true;
        }
        dp[even][odd][p] = ans;
        ok[even][odd][p] = true;
        return ans;
    };
    
    if(solve(cnt[0], cnt[1], 0)) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}