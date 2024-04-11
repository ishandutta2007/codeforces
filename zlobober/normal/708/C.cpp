#include <cassert>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 400500;

int par[N];
vector<int> E[N];

int maxgood[N];
int sz[N];

int n;

void DFS(int x, int p = -1) {
    sz[x] = 1;
    par[x] = p;
    if (p != -1) {
        E[x].erase(find(E[x].begin(), E[x].end(), p));
    }
    maxgood[x] = -N;
    for (int y : E[x]) {
        DFS(y, x);
        sz[x] += sz[y];
        maxgood[x] = max(maxgood[x], maxgood[y]);
    }
    if (2 * sz[x] <= n) {
        maxgood[x] = sz[x];
    }
    assert(maxgood[x] >= 1);
}

bool ans[N];

void DFS2(int x, int maxgoodsup = -N) {
    pair<int, int> largest(n - sz[x], -1);
    for (int y : E[x]) {
        largest = max(largest, make_pair(sz[y], y));
    }
    if (2 * largest.first <= n) {
        // already ok
        ans[x] = true;
    } else {
        int mxg = (largest.second != -1) ? maxgood[largest.second] : maxgoodsup;
        ans[x] = (2 * (largest.first - mxg) <= n);
    }
    pair<int, int> mx1(-N, -1), mx2(-N, -1);
    for (int y : E[x]) {
        if (mx1.first < maxgood[y]) {
            mx2 = mx1;
            mx1 = make_pair(maxgood[y], y);
        } else if (mx2.first < maxgood[y]) {
            mx2 = make_pair(maxgood[y], y);
        }
    }

    for (int y : E[x]) {
        int nmaxgoodsup = maxgoodsup;
        if (2 * (n - sz[y]) <= n) {
            nmaxgoodsup = max(nmaxgoodsup, n - sz[y]);
        }
        if (mx1.second != y && mx1.second != -1) {
            nmaxgoodsup = max(nmaxgoodsup, mx1.first);
        }
        if (mx2.second != y && mx2.second != -1) {
            nmaxgoodsup = max(nmaxgoodsup, mx2.first);
        }
        DFS2(y, nmaxgoodsup);
    }
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(0);
    DFS2(0);
    for (int i = 0; i < n; i++) {
        printf("%d%c", (int)ans[i], " \n"[i + 1 == n]);
    }
}