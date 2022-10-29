#include <bits/stdc++.h>
using namespace std;

void go() {
    int n, k; cin >> n >> k;
    bool flag = false;
    for (int base = 1; base <= 2; ++ base) {
        if (k * base > n || (n - (k - 1) * base) % 2 != base % 2) {
            continue;
        }
        else {
            flag = true;
            puts("YES");
            for (int i = 1; i <= k - 1; ++i) cout << base << ' ';
            cout << n - (k - 1) * base << endl;
            break;
        }
    }
    if (!flag) {
        puts("NO");
    }
}

int main () {
    int T; cin >> T;
    while (T--) {
        go();
    }
}