#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m;

string s[N], t[N];

vector <int> f[N], g[N];

bool ask_(int x, int y, int k) {
    return f[x][y] - f[x - k][y] - f[x][y - k] + f[x - k][y - k] == 1ll*k*k;
}

bool chk_(int t) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] = 0;
        }
    }

    t = 2*t + 1;

    for (int i = t; i <= n; i++) {
        for (int j = t; j <= m; j++) {
            if (ask_(i, j, t)) {
                g[i - t + 1][j - t + 1]++;
                g[i + 1][j - t + 1]--;
                g[i - t + 1][j + 1]--;
                g[i + 1][j + 1]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];

            if (s[i - 1][j - 1] == 'X' && !g[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        cin>>s[i];
        t[i].resize(m);

        for (int j = 0; j < m; j++) {
            t[i][j] = '.';
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        f[i].resize(m + 2);
        g[i].resize(m + 2);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1][j - 1] == 'X') {
                f[i][j]++;
            }

            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }

    int l = 0, r = max(n, m);

    while (l < r) {
        int mid = (l + r + 1)>>1;

        if (chk_(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout<<l<<'\n';
    chk_(l);
    int x = l*2 + 1;

    for (int i = x; i <= n; i++) {
        for (int j = x; j <= m; j++) {
            if (ask_(i, j, x)) {
                t[i - 1 - l][j - 1 - l] = 'X';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<t[i]<<'\n';
    }
}