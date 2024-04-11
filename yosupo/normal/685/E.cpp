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

const int MN = 1010;
const int MM = 200200;
const int MQ = 200200;

int g[MN][MN];
int u[MM], v[MM];
int l[MQ], r[MQ], s[MQ], t[MQ];
bool res[MQ];
vector<int> que[MM];

int main() {
    for (int i = 0; i < MN; i++) {
        for (int j = 0; j < MN; j++) {
            g[i][j] = TEN(8);
        }
    }
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", u+i, v+i); u[i]--; v[i]--;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", l+i, r+i, s+i, t+i); l[i]--; r[i]--; s[i]--; t[i]--;
        que[l[i]].push_back(i);
    }
    for (int i = m-1; i >= 0; i--) {
        int a = u[i], b = v[i];
        g[a][b] = g[b][a] = i;
        for (int j = 0; j < n; j++) {
            if (j == a or j == b) continue;
            g[a][j] = min(g[a][j], g[b][j]);
            g[b][j] = min(g[b][j], g[a][j]);
        }
        for (int q: que[i]) {
            res[q] = g[s[q]][t[q]] <= r[q];
        }
    }
    for (int i = 0; i < q; i++) {
        if (res[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}