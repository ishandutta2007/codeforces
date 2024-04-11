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
const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    vector<int> n(3);
    for(int i = 0; i < 3; i++) cin >> n[i];
    vector<vector<ll>> a(3);
    ll sum = 0;
    for(int i = 0; i < 3; i++){
        a[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    ll ans = -inf;
    for(int i = 0; i < 3; i++){
        ll tmp = sum;
        for(int j = 0; j < 3; j++){
            if(i == j) continue;
            tmp -= a[j][0]*2;
        }
        chmax(ans, tmp);
    }
    for(int i = 0; i < 3; i++){
        if(a[i].size() < 2) continue;
        ll tmp = sum - accumulate(a[i].begin(), a[i].end(), 0ll)*2;
        chmax(ans, tmp);
    }
    for(int i = 0; i < 3; i++){
        if(a[i].size() != 1) continue;
        ll tmp = sum - accumulate(a[i].begin(), a[i].end(), 0ll)*2;
        chmax(ans, tmp);
    }
    cout << ans << endl;
}