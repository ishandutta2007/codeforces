#include <bits/stdc++.h>
using namespace std;
int n;
int a[51];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = n - i + 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) cout << a[j] << " \n"[j == n];
        swap(a[i], a[i - 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}