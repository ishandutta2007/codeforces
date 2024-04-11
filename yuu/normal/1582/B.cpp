#include <bits/stdc++.h>
#define pdebug(x) cerr << __LINE__ << ": " << #x << " = " << x << '\n'
using namespace std;
int n;
int a[100001];
int cnt[2];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cnt[0] = 0;
    cnt[1] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] < 2) cnt[a[i]]++;
    cout << (1LL << cnt[0]) * cnt[1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}