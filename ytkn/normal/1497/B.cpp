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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= m;
        cnt[a[i]]++;
    }
    int ans = 0;
    if(m%2 == 0){
        if(cnt[m/2] > 0) ans++;
    }
    if(cnt[0] > 0) ans++;
    for(int i = 1; 2*i < m; i++){
        int l = min(cnt[i], cnt[m-i]);
        int r = max(cnt[i], cnt[m-i]);
        if(l == 0 && r == 0) continue;
        if(r-l <= 1) ans++;
        else ans += r-l;
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