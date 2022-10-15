#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 3 << "\n";
    } else {
        cout << n / 3 * 4 + n % 3 + 3 << "\n";
    }
    return 0;
}