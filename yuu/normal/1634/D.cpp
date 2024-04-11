#include <bits/stdc++.h>
using namespace std;
int n;
int ask(int i, int j, int k) {
    cout << "? " << i << ' ' << j << ' ' << k << '\n';
    cout.flush();
    cin >> i;
    return i;
}

void guess(int a, int b) {
    cout << "! " << a << ' ' << b << '\n';
    cout.flush();
}
void solve() {
    cin >> n;
    int best = ask(1, 2, 3);  // 1
    int key = 3;
    for (int i = 4; i <= n; i++) {  // n - 3
        int res = ask(1, 2, i);
        if (res > best) {
            best = res;
            key = i;
        }
    }

    int key_2 = 2;
    for (int i = 3; i <= n; i++) {  // n - 3
        if (i == key) continue;

        int res = ask(1, key, i);
        if (res > best) {
            best = res;
            key_2 = i;
        }
    }
    // 3 more queries.
    int a = 1, b = key, c = key_2;
    int d = 2;
    while (d == key || d == key_2) d++;

    int abd = ask(a, b, d);
    int acd = ask(a, c, d);
    int bcd = ask(b, c, d);
    if (abd == best)
        guess(a, b);
    else if (bcd == best)
        guess(b, c);
    else {
        assert(acd == best);
        guess(a, c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}