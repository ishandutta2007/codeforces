#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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
using P = pair<int, int>;

void solve(){
    int n; cin >> n;
    vector<int> a(n+2);
    priority_queue<P> que;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        que.push(P(a[i], i));
    }
    ll ans = 0;
    while(!que.empty()){
        auto [_, i] = que.top(); que.pop();
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            ans+=a[i]-max(a[i-1], a[i+1]);
            a[i] = max(a[i-1], a[i+1]);
        }
    }
    for(int i = 1; i <= n+1; i++){
        ans += abs(a[i]-a[i-1]);
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