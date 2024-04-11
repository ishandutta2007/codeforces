#include <cstdio>
#include <cassert>
#include <set>
#include <vector>
using namespace std;

const int N = 300500;

set<int> E[N];

set<int> unused;

//vector<vector<int>> subtrees;

int deg1 = 0;

void DFS(int x) 
{
    assert(unused.erase(x));
    for (set<int>::iterator it = E[x].begin(), it2 = ++E[x].begin(); it2 != E[x].end(); ++it, ++it2) {
        int l = *it + 1;
        int r = *it2;
        while (true) {
            auto uit = unused.lower_bound(l);
            if (uit == unused.end() || *uit >= r)
                break;
            if (x == 1)
                ++deg1;    
            DFS(*uit);
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].insert(b);
        E[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        E[i].insert(0);
        E[i].insert(n + 1);
    }
    if ((n - 1) - ((int)E[1].size() - 2) < k) {
        puts("impossible");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        unused.insert(i);
    DFS(1);
    if (!unused.empty()) {
        puts("impossible");
        return 0;
    }
    if (deg1 <= k) {
        puts("possible");
        return 0;
    } else {
        puts("impossible");
        return 0;
    }
/*    int num_bridges
    for (const auto& subtree : subtrees) {
        bool is_bridge = true;
        for (int x : subtree) {
            if (!E[x].count(1))
                is_bridge = false;
        }

    }*/
}