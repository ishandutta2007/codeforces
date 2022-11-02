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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> cumsum(2, vector<ll>(n+1));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cumsum[i%2][i+1] = cumsum[i%2][i]+a[i];
        cumsum[(i%2)^1][i+1] = cumsum[(i%2)^1][i];
    }
    ll ans = -INF;
    for(int i = 0; i < n; i++){
        chmax(ans, cumsum[0][i+1]-cumsum[0][0]+cumsum[1][n]-cumsum[1][i+1]);
        chmax(ans, cumsum[1][i+1]-cumsum[1][0]+cumsum[0][n]-cumsum[0][i+1]);
    }
    cout << ans << endl;
}