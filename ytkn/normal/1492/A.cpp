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

const ll INF = 2e18;

template<class T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--){
        ll p, a, b, c; cin >> p >> a >> b >> c;
        ll ans = INF;
        chmin(ans, ceil_div(p, a)*a-p);
        chmin(ans, ceil_div(p, b)*b-p);
        chmin(ans, ceil_div(p, c)*c-p);
        cout << ans << endl;
    }
}