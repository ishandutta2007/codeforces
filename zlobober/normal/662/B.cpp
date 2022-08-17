#include <cstdio>
#include <algorithm>
#include <tuple>
#include <memory.h>
#include <vector>
using namespace std;

const int N = 100500;

int A[N], B[N], T[N];


bool notBipartite = false;

int n, m;

int col[N];

vector<pair<int, int>> E[N];

vector<int> bycol[2];

void DFS(int x, int cur = 0) {
    col[x] = cur;
    bycol[cur].push_back(x);
    for (auto pr : E[x]) {
        int y, c;
        tie(y, c) = pr;
        if (col[y] == -1)
            DFS(y, cur ^ c);
        else {
            if (col[y] != (col[x] ^ c)) {
                notBipartite = true;
            }
        }
    }
}

vector<int> ans;

bool calcAns() {
    notBipartite = false;
    memset(col, -1, sizeof(col));
    ans.clear();
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            bycol[0].clear();
            bycol[1].clear();
            DFS(i);
            if (notBipartite)
                return false;
            if (bycol[0].size() < bycol[1].size())
                ans.insert(ans.end(), bycol[0].begin(), bycol[0].end());
            else
                ans.insert(ans.end(), bycol[1].begin(), bycol[1].end());
        }
    }

    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        char t;
        scanf("%d %d %c", &a, &b, &t);
        --a, --b;
        A[i] = a, B[i] = b, T[i] = (t == 'R');
    }

    vector<int> gans;
    bool found = false;
    for (int it = 0; it < 2; it++) {
        for (int i = 0; i < n; i++)
            E[i].clear();
        for (int i = 0; i < m; i++) {
            E[A[i]].push_back(make_pair(B[i], T[i])), E[B[i]].push_back(make_pair(A[i], T[i]));
        }
        if (calcAns()) {
            if (!found) {
                found = true;
                gans = ans;
            } else {
                if (gans.size() > ans.size())
                    gans = ans;
            }
        }
        for (int i = 0; i < m; i++)
            T[i] = 1 - T[i];
    }
    if (!found) {
        printf("-1\n");
    } else {
        printf("%d\n", (int)gans.size());
        for (int x : gans) {
            printf("%d ", x + 1);
        }
        printf("\n");
    }
}