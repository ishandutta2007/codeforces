#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[100001];
int b[100001];
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int high = x;
    int low = n - x + 1;
    bool good = 1;
    if(low<=high){
        for(int i=1; i<=n; i++) b[i]=a[i];
        sort(b+1, b+n+1);
        for(int i=low; i<=high; i++) if(a[i]!=b[i]){
            good = 0;
            break;
        }
    }
    if(good) cout<<"YES\n";
    else cout<<"NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}