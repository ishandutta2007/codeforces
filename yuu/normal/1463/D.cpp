#include <bits/stdc++.h>
using namespace std;
int n;
int b[200001];
int c[200001];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1, j = 1; i <= n; i++) {
        c[i] = c[i - 1] + 1;
        while ((j <= n) && (b[j] < c[i])) j++;
        while ((j <= n) && (c[i] == b[j])) {
            c[i]++;
            j++;
        }
    }
    int max_low = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        if (b[i] > c[j]) {
            max_low++;
            j++;
        }
    }
    int min_low = n;
    for (int i = n, j = n; i >= 1; i--) {
        if (b[i] < c[j]) {
            min_low--;
            j--;
        }
    }
    cout << max_low - min_low + 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}