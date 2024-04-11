#include <bits/stdc++.h>
using namespace std;
int n;
int h[200001];
int a[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    int low = 1, high = 1e9, mid, ans = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        bool good = true;
        {
            for (int i = 1; i <= n; i++) a[i] = 0;
            for (int i = n; i >= 3; i--) {
                int can_do = min(h[i], a[i] + h[i] - mid);
                if (can_do < 0) {
                    good = false;
                    break;
                }
                a[i - 1] += can_do / 3;
                a[i - 2] += 2 * (can_do / 3);
            }
            a[1] += h[1];
            a[2] += h[2];
            if (min(a[1], a[2]) < mid) good = false;
        }
        if (good) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}