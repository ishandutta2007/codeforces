#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin>>a[i];
    int mi = *min_element(a+1, a+n+1);
    int ans =0;
    for (int i=1; i<=n; i++) ans+=(a[i]>mi);
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}