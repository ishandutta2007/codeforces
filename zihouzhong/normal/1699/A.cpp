#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2) {
            cout << "-1\n";
        } else {
            n /= 2;
            cout << 1 << " " << (n ^ 1) << " " << (n ^ 1) << "\n";
        }
    }
    return 0;
}