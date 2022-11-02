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

using P = pair<ll, int>;

void solve(){
    int n; ll W; cin >> n >> W;
    vector<ll> w(n);
    vector<P> p(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        p[i] = P(w[i], i);
    }
    sort(p.begin(), p.end(), greater<P>());
    ll w_sum = accumulate(w.begin(), w.end(), 0ll);
    if(w_sum*2 < (W+1)/2){
        cout << -1 << endl;
        return;
    }
    ll sum = 0;
    ll lw = (W+1)/2;
    vector<int> ans;
    for(auto [w, i]: p){
        if(sum + w > W) continue;
        ans.push_back(i);
        sum += w;
        if(lw <= sum && sum <= W) break;
    }
    if(sum < lw){
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for(int i: ans) cout << i+1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}