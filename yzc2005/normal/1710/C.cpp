#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
inline void add(int &x, int y) {
    (x += y) >= P && (x -= P);
}
const int N = 2e5 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int f[2][2][2][2][2][2], g[2][2][2][2][2][2];
    memset(f, 0, sizeof f);
    f[1][1][1][0][0][0] = 1;
    int sum = 0;
    for (auto c : s) {
        int cur = c - '0';
        sum = (sum * 2 + cur) % P;
        memset(g, 0, sizeof g);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        for (int p = 0; p < 2; ++p) {
                            for (int q = 0; q < 2; ++q) {
                                int val = f[i][j][k][l][p][q];
                                if (val) {
                                    int l1 = i ? cur : 1, l2 = j ? cur : 1, l3 = k ? cur : 1;
                                    for (int x = 0; x <= l1; ++x) {
                                        for (int y = 0; y <= l2; ++y) {
                                            for (int z = 0; z <= l3; ++z) {
                                                if ((!x && y && z) || (x && !y && !z)) {
                                                    continue;
                                                }
                                                add(g[i && (x == l1)][j && (y == l2)][k && (z == l3)][l || (x != y)][p || (y != z)][q || (x != z)], val);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        memcpy(f, g, sizeof f);
    }
    sum = 1ll * (sum + 1) * sum % P * (sum - 1) % P;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                add(sum, 1ll * (P - 3) * f[i][j][k][1][1][1] % P);
            }
        }
    }
    cout << sum << "\n";
    return 0;
}