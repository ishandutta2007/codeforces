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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = accumulate(a.begin(), a.end(), 0ll);
    vector<ll> ok(n);
    int q; cin >> q;
    map<P, int> mp;
    auto add = [&](int i){
        ok[i]++;
        if(ok[i] <= a[i]) ans--;
    };
    auto del = [&](int i){
        ok[i]--;
        if(ok[i] < a[i]) ans++;
    };
    for(int i = 0; i < q; i++){
        int s, t, u; cin >> s >> t >> u; s--; u--;
        if(mp.count(P(s, t))){
            int x = mp[P(s, t)];
            mp.erase(P(s, t));
            del(x);
        }
        if(u != -1){
            mp[P(s, t)] = u;
            add(u);
        }
        cout << ans << endl;
    }
}