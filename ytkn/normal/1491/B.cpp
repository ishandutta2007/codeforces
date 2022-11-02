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

void solve(){
    ll n, u, v; cin >> n >> u >> v;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int max_diff = 0;
    for(int i = 1; i < n; i++) chmax(max_diff, abs(a[i]-a[i-1]));
    if(max_diff >= 2){
        cout << 0 << endl;
    }else if(max_diff == 1){
        cout << min(u, v) << endl;
    }else{
        cout << min(u+v, 2*v) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}