#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m > 1) {
        cout << 1LL * n * (m - 1) << "\n";
    } else {
        cout << n - 1 << "\n";
    }
    return 0;
}