#include <bits/stdc++.h>
using namespace std;

void go(int n, int a) {
    for (int i = 0; i < n; ++i) {
        cout << a;
    }
}

void go2(int n, int st) {
    for (int i = 0; i < n; ++i) {
        cout << st;
        st = 1 - st;
    }
}

int main () {
    int T; cin >> T;
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0) {
            go(c + 1, 1);
            go2(b, 0);
            cout << endl;
            continue;
        }
        if (c == 0) {
            go(a + 1, 0);
            go2(b, 1);
            cout << endl;
            continue;
        }
        go(a + 1, 0);
        go(c + 1, 1);
        go2(b - 1, 0);
        cout << endl;
    }
}