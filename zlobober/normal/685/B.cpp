#include <cstdio>
#include <memory.h>
#include <cassert>
#include <vector>
using namespace std;

const int N = 300500;
vector<int> E[N];

int C[N];
int sz[N];
int par[N];

int mx_sub[N];

bool is_centroid(int x, int s) {
    if (s - sz[x] > s / 2)
        return false;
    if (mx_sub[x] != -1) {
        for (int y : E[x]) {
            mx_sub[x] = max(mx_sub[x], sz[y]);
        }
    }
    return mx_sub[x] <= s / 2;
}

void DFS(int x) {
    sz[x] = 1;
    for (int y : E[x]) {
        DFS(y);
        sz[x] += sz[y];
    }
    int mxy = -1;
    for (int i = 0; i < (int)E[x].size(); i++) {
        int y = E[x][i];
        if (mxy == -1 || sz[mxy] < sz[y])
            mxy = y;
    }
    if (sz[x] == 1) {
        C[x] = x;
        return;
    }
    int c = C[mxy];
    while (true) {
        if (is_centroid(c, sz[x])) {
            C[x] = c;
            break;
        }
        if (c == x)
            assert(false);
        c = par[c];
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    memset(mx_sub, -1, sizeof(int) * (n + 1));
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        par[i] = p;
        E[p].push_back(i);
    }
    DFS(1);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", C[x]);
    }
}