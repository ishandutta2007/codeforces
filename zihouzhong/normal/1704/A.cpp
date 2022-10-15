#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        if (a.substr(n - m + 1) != b.substr(1)) {
            cout << "NO\n";
        } else {
            char l = *min_element(a.begin(), a.begin() + n - m + 1);
            char r = *max_element(a.begin(), a.begin() + n - m + 1);
            if (l <= b[0] && b[0] <= r) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}