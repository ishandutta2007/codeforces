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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    vector<ll> d(n-1);
    ll g = a[0];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i != 0) {
            d[i-1] = a[i]-a[i-1];
            g = gcd(g, d[i-1]);
        }
    }
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < m; i++) {
        cout << gcd(g, a[0]+b[i]) << ' ';
    }
    cout << endl;
}