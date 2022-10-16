#include <bits/stdc++.h>
using namespace std;
int n;
int p[10001];
int ask_min(int i, int j) {
    cout << "? 2 " << i << ' ' << j << " 1\n";
    cout.flush();
    cin >> i;
    return i;
}

int ask_max(int i, int j) {
    cout << "? 1 " << i << ' ' << j << ' ' << n - 1 << '\n';
    cout.flush();
    cin >> i;
    return i;
}

void solve() {
    cin >> n;
    int pos_1 = 0;
    for (int i = 1; i < n; i += 2) {
        int res = ask_min(i, i + 1);
        if (res == 1) {
            pos_1 = i;
            break;
        } else if (res == 2) {
            if (ask_min(i + 1, i) == 1) {
                pos_1 = i + 1;
                break;
            }
        }
    }
    if (pos_1 == 0) pos_1 = n;
    p[pos_1] = 1;
    for (int i = 1; i <= n; i++)
        if (i != pos_1) p[i] = ask_max(pos_1, i);
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}