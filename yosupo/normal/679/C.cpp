#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

/**
 * QuickFind
 *
 * See_Also: http://topcoder.g.hatena.ne.jp/iwiwi/20131226/1388062106
 */
template <int N>
struct UnionFind {
    int ig[N];
    vector<int> gi[N];
    int gn;

    void init(int n = N) {
        for (int i = 0; i < n; ++i) {
            ig[i] = i;
            gi[i] = {i};
        }
        gn = n;
    }

    void merge(int a, int b) {
        if (same(a, b)) return;
        gn--;
        int x = ig[a], y = ig[b];
        if (gi[x].size() < gi[y].size()) swap(x, y);
        for (int j: gi[y]) {
            ig[j] = x;
        }
        gi[x].insert(gi[x].end(), gi[y].begin(), gi[y].end());
        gi[y].clear();
    }

    bool same(int a, int b) {
        return ig[a] == ig[b];
    }

    int group_num() {
        return gn;
    }
};
const int d4[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

const int MN = 520;
int n, k;

bool bc(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < n;
}

bool g[MN][MN];
int gid[MN][MN];
int gsz[MN*MN];
int used[MN][MN];
int mp[MN*MN];
int now = 0;

void ins_n(int x, int y) {
    if (!bc(x, y) or g[y][x]) return;   
    used[y][x]++;
    if (used[y][x] > 1) return;
    int g = gid[y][x];
    mp[g]++;
    if (mp[g] == 1) {
        now += gsz[g];
    }
}
void ins(int x, int y) {
    ins_n(x, y);
    for (int d = 0; d < 4; d++) {
        ins_n(x+d4[d][0], y+d4[d][1]);
    }
}
void era_n(int x, int y) {
    if (!bc(x, y) or g[y][x]) return;
    used[y][x]--;
    if (used[y][x]) return;
    int g = gid[y][x];
    mp[g]--;
    if (mp[g] == 0) {
        now -= gsz[g];
    }
}
void era(int x, int y) {
    era_n(x, y);
    for (int d = 0; d < 4; d++) {
        era_n(x+d4[d][0], y+d4[d][1]);
    }
}

int solve() {
    int ans = k*k;
    for (int fe = 0; fe <= n-k; fe++) {
        int bc = 0;
        for (int y = 0; y < k-1; y++) {
            for (int x = fe; x < fe+k; x++) {
                ins(x, y);
                if (g[y][x]) bc++;
            }
        }
        for (int y = k-1; y < n; y++) {
            for (int x = fe; x < fe+k; x++) {
                ins(x, y);
                if (g[y][x]) bc++;
            }
//            printf("%d(%d), ", now, bc);
            ans = max(ans, now+bc);
            for (int x = fe; x < fe+k; x++) {
                era(x, y-k+1);
                if (g[y-k+1][x]) bc--;
            }
        }
        for (int y = n-k+1; y < n; y++) {
            for (int x = fe; x < fe+k; x++) {
                era(x, y);
                if (g[y][x]) bc++;
            }
        }
    }
    return ans;
}

UnionFind<MN*MN> uf;
int main() {
    scanf("%d %d", &n, &k);
//    cin >> n >> k;
    uf.init(n*n);
    for (int i = 0; i < n; i++) {
//        string s;
        char s[MN];
        scanf("%s", s);
//        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j]=='X';
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            for (int d = 0; d < 4; d++) {
                int nx = x+d4[d][0], ny = y+d4[d][1];
                if (!bc(nx, ny)) continue;
                if (g[y][x] or g[ny][nx]) continue;
                uf.merge(y*n+x, ny*n+nx);
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            gid[y][x] = uf.ig[y*n+x];
        }
    }
    for (int i = 0; i < n*n; i++) {
        gsz[i] = uf.gi[i].size();
    }

    cout << solve() << endl;

    return 0;
}