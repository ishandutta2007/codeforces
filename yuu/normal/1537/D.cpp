#include <bits/stdc++.h>
using namespace std;
int f[257];
void test() {
    f[1] = 0;
    f[2] = 0;
    for (int i = 3; i <= 256; i++) {
        for (int j = 2; j < i; j++)
            if (f[i - j] == 0)
                if (i % j == 0) {
                    f[i] = 1;
                    break;
                }
    }
}

int first_win(int n) {
    if (n <= 256) return f[n];
    if (n % 2) return 0;
    if (n != (1 << __lg(n))) return 1;
    if (__lg(n) % 2)
        return 0;
    else
        return 1;
}

void solve() {
    int n;
    cin >> n;
    if (first_win(n))
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test();
    int t = 1;
    cin >> t;
    while (t--) solve();
}