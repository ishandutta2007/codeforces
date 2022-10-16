#include <bits/stdc++.h>
using namespace std;
int ask(int l, int r) {
    if (l == r) return -1;
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    cin >> l;
    return l;
}
void guess(int p) {
    cout << "! " << p;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    int second_max = ask(1, n);
    int lsm = ask(1, second_max);
    if (lsm == second_max) {
        int low = 1, high = second_max - 1, mid, res;
        while (low <= high) {
            mid = (low + high) / 2;
            if (ask(mid, second_max) == second_max) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        guess(res);
    } else {
        int low = second_max + 1, high = n, mid, res;
        while (low <= high) {
            mid = (low + high) / 2;
            if (ask(second_max, mid) == second_max) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        guess(res);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}