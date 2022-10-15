#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        if (n % 2) { cout << "NO\n"; continue; }
        bool flag = 1;
        for (int i = 1; i <= n / 2; i++) {
            if (a[i] == a[i + n / 2]) flag = 0;
            if (i < n / 2 && a[i + 1] == a[i + n / 2]) flag = 0;
        }
        if (!flag) { cout << "NO\n"; continue; }
        cout << "YES\n";
        for (int i = 1; i <= n / 2; i++) {
            cout << a[i] << " " << a[i + n / 2] << " ";
        }
        cout << "\n";
    }
    return 0;
}