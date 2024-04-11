#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
using P = pair<ll, int>;

void solve(){
    ll n, m, x; cin >> n >> m >> x;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<int> ans(n);
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < m; i++) que.push(P(0, i));
    for(int i = 0; i < n; i++){
        auto [x, idx] = que.top(); que.pop();
        ans[i] = idx;
        que.push(P(x+h[i], idx));
    }
    cout << "YES" << endl;
    for(int x : ans) cout << x+1 << ' ';
    cout << endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}