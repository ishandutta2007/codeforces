#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

ll a[200000];
int w[200000];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> w[i];
    ll ans = 0;
    sort(a, a+n);
    sort(w, w+k, greater<int>());
    int l = 0, r = n-1;
    for(int i = k-1; i >= 0; i--){
        ans += a[n-i-1];
        if(w[i] == 1) ans += a[n-(k-i)];
    }
    for(int i = 0; i < k; i++){
        if(w[i] > 1) ans += a[l];
        for(int j = 0; j < w[i]-1; j++){
            l++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}