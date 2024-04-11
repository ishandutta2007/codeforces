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

int max_right(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    int c = n;
    auto count = [&](int l, int r){ // [l, r)
        return (int)(lower_bound(b.begin(), b.end(), r)-lower_bound(b.begin(), b.end(), l));
    };
    for(int i = n-1; i >= 0; i--){
        if(a[i] > 0) c = i;
    }
    if(c == n) return 0;
    // cout << c << endl;
    vector<int> cumsum(n+1);
    for(int i = n-1; i >= 0; i--){
        if(count(a[i], a[i]+1)) cumsum[i] = cumsum[i+1]+1;
        else cumsum[i] = cumsum[i+1];
    }
    int ans = 0;
    int r = c;
    for(int l = 0; l < m; l++){
        if(b[l] < a[c]) continue;
        while(r < n-1 && a[r+1] <= b[l]+r-c) {
            // cout << a[r+1] << ' '  << b[l]+r-c << endl;
            r++;
        }
        // cout << l << ':' << r << ' ';
        chmax(ans, count(b[l], b[l]+r-c+1) + cumsum[r+1]);
    }
    // cout << endl;
    return ans;
}

void solve(){
    // cout << "====" << endl;
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int ans = 0;
    ans += max_right(a, b);
    for(int i = 0; i < n; i++) a[i] *= -1;
    for(int i = 0; i < m; i++) b[i] *= -1;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // cout << ans << endl;
    ans += max_right(a, b);
    cout << ans << endl;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}