#include <bits/stdc++.h>
using namespace std;
void solve() {
    int64_t p, a;
    cin >> p;
    int64_t ans = 1.2e18;
    for (int i=0; i<3; i++){
        cin>>a;
        if(p%a==0) ans = 0;
        else ans = min(ans, a-p%a);
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}