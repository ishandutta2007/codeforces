#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int req = n;
    while ((req > 0) && (a[req] == req)) req--;
    long double prob = (req ? 1 : 0), p;

    for (int i = 1, r; i <= m; i++) {
        cin >> r >> p;
        if (r >= req) prob = prob * (-p + 1);
    }
    prob = -prob + 1;
    cout << setprecision(16) << fixed << prob << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}