#include <bits/stdc++.h>
using namespace std;
int n;
int x[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int start = x[1] - 1; start <= x[1] + 1; start++) {
        bool good = 1;
        for (int i = 1; i <= n; i++) {
            if (abs(x[i] - (start + i - 1)) > 1) {
                good = 0;
                break;
            }
        }
        if (good) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}