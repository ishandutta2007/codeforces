#include <bits/stdc++.h>
using namespace std;
int n;
int p[501];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) continue;
        int j = i + 1;
        while (p[j] != i) j++;
        reverse(p + i, p + j + 1);
        break;
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}