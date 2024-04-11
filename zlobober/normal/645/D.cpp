#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100500;
bool was[N];

vector<int> E[N];
vector<int> topsort;

void DFS(int x) {
    was[x] = true;
    for (int y : E[x]) {
        if (was[y])
            continue;
        DFS(y);
    }
    topsort.push_back(x);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    map<pair<int, int>, int> all;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        all[make_pair(a, b)] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (!was[i])
            DFS(i);
    }
    reverse(topsort.begin(), topsort.end());
    bool bad = false;
    int mx = -1;
    for (int i = 0; i + 1 < topsort.size(); i++) {
        int a = topsort[i], b = topsort[i + 1];
        if (all.find(make_pair(a, b)) == all.end()) {
            bad = true;
        } else {
            mx = max(mx, all[make_pair(a, b)]);
        }
    }
    if (bad) {
        printf("-1\n");
        return 0;
    } else {
        printf("%d\n", mx + 1);
    }
}