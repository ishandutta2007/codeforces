#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int last[1000001];
int cnt = 0;
void solve() {
    cnt++;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = cnt;
    }
    sort(a + 1, a + n + 1);
    for (int i = n - n / 2 + 1; i <= n; i++) {
        cout << a[i] << ' ' << a[1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}