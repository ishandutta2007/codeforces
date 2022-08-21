#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MN = 50010;
int on[MN] = {};
int num[MN] = {};
set<int> g[MN];
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    int o;
    cin >> o;
    for (int i = 0; i < o; i++) {
        int d;
        cin >> d; d--;
        on[d] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (g[a].size() > g[b].size()) swap(a, b);
        g[a].insert(b);
        num[b] += on[a];
    }
    for (int i = 0; i < q; i++) {
        char c = '\0';
        int u, v;
        while (!isupper(c)) {
            c = getchar();
        }
        scanf("%d", &u); u--;
        switch (c) {
            case 'O':
                on[u] = 1;
                for (int d: g[u]) num[d]++;
                break;
            case 'F':
                on[u] = 0;
                for (int d: g[u]) num[d]--;
                break;
            case 'A':
                scanf("%d", &v); v--;
                if (g[u].size() > g[v].size()) swap(u, v);
                g[u].insert(v);
                num[v] += on[u];
                break;
            case 'D':
                scanf("%d", &v); v--;
                if (g[u].count(v)) {
                    g[u].erase(v);
                    num[v] -= on[u];
                } else {
                    g[v].erase(u);
                    num[u] -= on[v];
                }
                break;
            case 'C':
                int r = num[u];
                for (int d: g[u]) {
                    r += on[d];
                }
                printf("%d\n", r);
                break;
        }
    }
    return 0;
}