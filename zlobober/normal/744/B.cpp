#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

const int inf = ((int)1e9) + 42;

const int R = 10;

vector<int> ans[R][2];

int n;
vector<int> ask(vector<int> q) {
    assert(q.size() <= n);
    printf("%d\n", (int)q.size());
    for (int x : q)
        printf("%d ", x);
    printf("\n");
    fflush(stdout);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &res[i]);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    int r = 0;
    while ((1 << r) < n) {
        r++;
    }
    assert(r <= R);
    for (int i = 0; i < r; i++) {
        for (int v = 0; v < 2; v++) {
            vector<int> q;
            for (int j = 0; j < n; j++) {
                if (((j >> i) & 1) == v)
                    q.push_back(j + 1);
            }
            ans[i][v] = ask(q);
        }
    }
    printf("-1\n");
    for (int j = 0; j < n; j++) {
        int cur = inf;
        for (int i = 0; i < r; i++) {
            int p = (j >> i) & 1;
            cur = min(cur, ans[i][!p][j]);
        }
        printf("%d ", cur);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}