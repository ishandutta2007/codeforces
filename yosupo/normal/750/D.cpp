#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

const int d8[8][2] = {
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1},
};

const int N = 400;

bool g1[N][N][8], g2[N][N][8];
bool res[N][N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    g1[200][199][0] = true;
    res[200][200] = true;
    for (int fe = 0; fe < n; fe++) {
        memset(g2, 0, sizeof(g2));
        int c;
        cin >> c;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                for (int d = 0; d < 8; d++) {
                    if (!g1[y][x][d]) continue;
                    int nx = x, ny = y;
                    for (int i = 0; i < c; i++) {
                        nx += d8[d][0];
                        ny += d8[d][1];
                        res[ny][nx] = true;
                    }
                    g2[ny][nx][(d+1)%8] = true;
                    g2[ny][nx][(d+7)%8] = true;
                }
            }
        }
        memcpy(g1, g2, sizeof(g2));
    }

    int ans = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (res[y][x]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}