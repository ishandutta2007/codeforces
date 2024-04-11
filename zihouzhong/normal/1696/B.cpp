#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (count(a + 1, a + n + 1, 0) == n) {
            cout << "0\n"; continue;
        }
        int l = 1, r = n;
        while (!a[l]) l++;
        while (!a[r]) r--;
        if (!count(a + l, a + r + 1, 0)) {
            cout << "1\n"; continue;
        }
        cout << "2\n";
    }
    return 0;
}