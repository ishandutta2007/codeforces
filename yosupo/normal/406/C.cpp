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
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const int MN = 100010;
vector<P> g[MN];
bool gu[MN] = {}, used[MN] = {};
vector<T> res;

bool dfs(int a, int p) {
    if (used[a]) return true;
    used[a] = true;
    int e = -1;
    for (P p: g[a]) {
        if (gu[p.second]) continue;
        gu[p.second] = true;
        if (!dfs(p.first, a)) continue;
        if (e == -1) {
            e = p.first;
        } else {
            res.push_back(T(p.first, a, e));
            e = -1;
        }
    }
    if (e != -1) {
        res.push_back(T(e, a, p));
        return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(P(b, i));
        g[b].push_back(P(a, i));
    }
    if (m % 2) {
        printf("No solution\n");
    } else {
        dfs(0, -1);
        for (T t: res) {
            int a, b, c;
            tie(a, b, c) = t;
            printf("%d %d %d\n", a+1, b+1, c+1);
        }
    }
    return 0;
}