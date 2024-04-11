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

const int MN = 300100;
const int LG = 20;
int sz[MN];
int ch[LG][MN];
vector<int> g[MN];
void dfs(int p) {
    sz[p] = 1;
    int ma = -1, mi = -1;
    for (int d: g[p]) {
        dfs(d);
        sz[p] += sz[d];
        if (ma < sz[d]) {
            ma = sz[d];
            mi = d;
        }
    }
    ch[0][p] = mi;
}
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x); x--;
        // x-i
        g[x].push_back(i);
    }
    dfs(0);
    for (int l = 1; l < LG; l++) {
        for (int i = 0; i < n; i++) {
            ch[l][i] = (ch[l-1][i] == -1) ? -1 : ch[l-1][ch[l-1][i]];
        }
    }
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x); x--;
        int a = sz[x];
        for (int l = LG-1; l >= 0; l--) {
            int y = ch[l][x];
            if (y == -1) continue;
            if (sz[y] >= a-a/2) x = y;
        }
        printf("%d\n", x+1);
    }
    return 0;
}