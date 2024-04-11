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
const ll INF = 1e18;

void solve(){
    ll n; cin >> n;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    priority_queue<int, vector<int>, greater<int>> quel, quer;
    quel.push(c[0]);
    ll ans = INF;
    ll lsum = c[0], rsum = 0;
    for(int i = 2; i <= n; i++){
        if(i%2 == 1) {
            quel.push(c[i-1]);
            lsum += c[i-1];
        } else {
            quer.push(c[i-1]);
            rsum += c[i-1];
        }
        ll l = (i+1)/2, r = i-l;
        ll lmin = quel.top();
        ll rmin = quer.top();
        ll tmp = lsum+(n-l)*lmin+rsum+(n-r)*rmin;
        chmin(ans, tmp);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}