#include <bits/stdc++.h>
using namespace std;

const int N = 105;
bool f[2][2][N][N];

__attribute__((constructor)) void init() {
    f[0][0][0][0] = f[1][0][0][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int t : {0, 1}) {
                if (j < i) f[0][t][i][j] |= f[1][t][i - 1][j];
                if (j) f[0][t][i][j] |= f[1][!t][i - 1][j - 1];
                f[1][t][i][j] = 1;
                if (j < i) f[1][t][i][j] &= f[0][t][i - 1][j];
                if (j) f[1][t][i][j] &= f[0][t][i - 1][j - 1];
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x % 2 != 0) cnt++;
    }
    cout << (f[0][0][n][cnt] ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}