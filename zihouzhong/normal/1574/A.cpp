#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cout << string(i, '(') + string(i, ')') + string(n - i, '(') + string(n - i, ')') << endl;
        }
    }
    return 0;
}