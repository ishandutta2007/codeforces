#include <bits/stdc++.h>
using namespace std;

int a[123];

void go() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            cout << -abs(a[i]) << ' ';
        }
        else {
            cout << abs(a[i]) << ' ';
        }
    }
    cout << endl;
}

int main () {
    int T; cin >> T;
    while (T--) {
        go();
    }
}