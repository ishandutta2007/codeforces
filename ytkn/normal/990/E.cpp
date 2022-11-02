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
    int n, m, k; cin >> n >> m >> k;
    vector<bool> ok(n, true);
    for(int i = 0; i < m; i++){
        int s; cin >> s;
        ok[s] = false;
    }
    vector<ll> a(k+1);
    for(int x = 1; x <= k; x++){
        cin >> a[x];
    }
    if(!ok[0]){
        cout << -1 << endl;
        return 0;
    }
    vector<int> prev_ok(n+1);
    for(int x = 1; x <= n; x++){
        if(ok[x]) prev_ok[x] = x;
        else prev_ok[x] = prev_ok[x-1];
    }
    ll ans = inf;
    for(int len = 1; len <= k; len++){
        int x = 0;
        bool ok = true;
        int cnt = 0;
        while(x < n){
            if(prev_ok[x]+len <= x){
                ok = false;
                break;
            }
            x = prev_ok[x]+len;
            cnt++;
        }
        if(ok) chmin(ans, cnt*a[len]);
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}