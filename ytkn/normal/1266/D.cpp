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
using T = tuple<int, int, ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<ll> sum(n);
    for(int i = 0; i < m; i++){
        int u, v, d; cin >> u >> v >> d; u--; v--;
        sum[u] += d;
        sum[v] -= d;
    }
    priority_queue<P, vector<P>, greater<P>> pos, neg;
    for(int i = 0; i < n; i++){
        if(sum[i] > 0){
            pos.push(P(sum[i], i));
        }
        if(sum[i] < 0){
            neg.push(P(-sum[i], i));
        }
    }
    vector<T> ans;
    while(!pos.empty()){
        auto [sum_u, u] = pos.top(); pos.pop();
        auto [sum_v, v] = neg.top(); neg.pop();
        ll x = min(sum_u, sum_v);
        ans.push_back(T(u, v, x));
        sum_u -= x;
        sum_v -= x;
        if(sum_u > 0){
            pos.push(P(sum_u, u));
        }
        if(sum_v > 0){
            neg.push(P(sum_v, v));
        }
    }
    cout << ans.size() << endl;
    for(auto [u, v, d]: ans) cout << u+1 << ' ' << v+1 << ' ' << d << endl;
}