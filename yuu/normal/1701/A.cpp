#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) cin >> a[i][j];
    int sum = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) sum += a[i][j];
    if (sum == 0) {
        cout << "0\n";
    } else if (sum <= 3) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}