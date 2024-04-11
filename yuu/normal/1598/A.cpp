#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
void solve() {
    cin>>n>>a>>b;
    for (int i=1; i<n; i++) if((a[i]=='1')&&(b[i]=='1')) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}