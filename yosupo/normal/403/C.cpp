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
const int MN = 2010;
bool g[MN][MN] = {}, rg[MN][MN] = {};
bool f1[MN] = {}, f2[MN] = {};
int n;
void dfs(int i) {
    for (int j = 0; j < n; j++) {
        if (g[i][j] && !f1[j]) {
            f1[j] = true;
            dfs(j);
        }
    }
}
void rdfs(int i) {
    for (int j = 0; j < n; j++) {
        if (rg[i][j] && !f2[j]) {
            f2[j] = true;
            rdfs(j);
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            if (i != j && a) {
                g[i][j] = true;
                rg[j][i] = true;
            }
        }
    }
    f1[0] = f2[0] = true;
    dfs(0); rdfs(0);
    for (int i = 0; i < n; i++) {
        if (!f1[i] || !f2[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}