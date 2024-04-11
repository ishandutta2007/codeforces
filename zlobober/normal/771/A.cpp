#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int N = 150500;
bool used[N];

vector<int> E[N];
vector<int> comp;

void DFS(int x) {
    used[x] = true;
    comp.push_back(x);
    for (int y : E[x]) {
        if (!used[y]) {
            DFS(y);
        }
    }
}

set<pair<int, int>> edges;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        E[a].push_back(b);
        E[b].push_back(a);
        edges.insert(make_pair(a, b));
        edges.insert(make_pair(b, a));
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        comp.clear();
        DFS(i);
        for (int j = 0; j < comp.size(); j++) {
            for (int k = 0; k < j; k++) {
                int a = comp[j];
                int b = comp[k];
                if (edges.count(make_pair(a, b)) == 0) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    return 0;
}