#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 255;

int n, q, nex[N][26], f[M][M][M];

string s, t[3];

void add_(int x) {
    for (int i = x != 0 ? 0 : t[0].size() - 1; i < t[0].size(); i++) {
        for (int j = x != 1 ? 0 : t[1].size() - 1; j < t[1].size(); j++) {
            for (int k = x != 2 ? 0 : t[2].size() - 1; k < t[2].size(); k++) {
                if (i && f[i - 1][j][k] <= n) {
                    f[i][j][k] = min(f[i][j][k], nex[f[i - 1][j][k]][t[0][i] - 'a']);
                }

                if (j && f[i][j - 1][k] <= n) {
                    f[i][j][k] = min(f[i][j][k], nex[f[i][j - 1][k]][t[1][j] - 'a']);
                }

                if (k && f[i][j][k - 1] <= n) {
                    f[i][j][k] = min(f[i][j][k], nex[f[i][j][k - 1]][t[2][k] - 'a']);
                }
            } 
        }
    }
}

void del_(int x) {
    for (int i = x != 0 ? 0 : t[0].size() - 1; i < t[0].size(); i++) {
        for (int j = x != 1 ? 0 : t[1].size() - 1; j < t[1].size(); j++) {
            for (int k = x != 2 ? 0 : t[2].size() - 1; k < t[2].size(); k++) {
                f[i][j][k] = n + 1;
            } 
        }
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q>>s;
    s = " " + s;
    t[0] = t[1] = t[2] = " ";

    for (int i = 0; i < 26; i++) {
        nex[n][i] = n + 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        memcpy(nex[i], nex[i + 1], sizeof(nex[i]));
        nex[i][s[i + 1] - 'a'] = i + 1;
    }

    memset(f, 0x3f, sizeof(f));
    f[0][0][0] = 0;

    while (q--) {
        cin>>s;
        int x;

        if (s[0] == '+') {
            cin>>x>>s;
            t[--x] += s;
            add_(x);
        } else {
            cin>>x;
            del_(--x);
            t[x].pop_back();
        }

        cout<<(f[t[0].size() - 1][t[1].size() - 1][t[2].size() - 1] <= n ? "YES" : "NO")<<'\n';
    }
}