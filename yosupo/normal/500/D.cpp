//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>

using namespace std;
typedef long long ll;
const int MN = 100100;
vector<int> g[MN];
int root[MN];
int size[MN];

int dfs(int p, int b) {
    root[p] = b;
    size[p] = 1;
    for (int d: g[p]) {
        if (d == b) continue;
        size[p] += dfs(d, p);
    }
    return size[p];
}

typedef pair<int, int> P;
typedef tuple<int, int, int> T;
T edge[MN];
ll cm[MN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c); a--; b--;
        edge[i] = T(a, b, c);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    double res = 0;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        tie(a, b, c) = edge[i];
        if (root[b] != a) swap(a, b);
        ll ls = (n-size[b]), rs = size[b];
        cm[i] = ls*(rs)*(rs-1) + ls*(ls-1)*rs;
        res += 1.0*cm[i]*c;
    }
    int q;
    cin >> q;
    ll nc = 1LL*n*(n-1)*(n-2);
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--;
        res -= cm[a]*(get<2>(edge[a])-b);
        get<2>(edge[a]) = b;
        printf("%.20f\n", res*6/nc);
    }
}