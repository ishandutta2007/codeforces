#include <bits/stdc++.h>
using namespace std;

const int N = 5006;
vector<int> G[N];

int sz[N];

void dfs(int now, int par) {
    sz[now] = 1;
    for (int i: G[now]) {
        if (i == par) continue;
        dfs(i, now);
        sz[now] += sz[i];
    }
}

set<int> st;

typedef bitset<N> bst;

int main () {
    int n; scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        G[x].push_back(y); G[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, i);
        bst now;
        now.reset();
        now[0] = true;
        for (int j: G[i]) {
            now |= (now << sz[j]);
        }
        for (int i = 1; i <= n - 2; ++i) {
            if (!now[i]) continue;
            st.insert(i);
            st.insert(n - 1 - i);
        }
    }
    printf("%d\n", (int)st.size());
    for (int i: st) {
        printf("%d %d\n", i, n - 1 - i);
    }
}