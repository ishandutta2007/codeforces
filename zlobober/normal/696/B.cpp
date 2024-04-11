#include <cstdio>
#include <vector>
using namespace std;

const int N = 100500;

vector<int> E[N];

double ans[N];

int sz[N];

void DFS(int x) {
    sz[x] = 1;
    for (int y : E[x]) {
        DFS(y);
        sz[x] += sz[y];
    }
}

void DFS2(int x, double cur) {
    ans[x] = cur;
    for (int y : E[x]) {
        DFS2(y, cur + 1 + (sz[x] - sz[y] - 1) / 2.0);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        E[p].push_back(i);
    }
    DFS(1);
    DFS2(1, 1);
    for (int i = 1; i <= n; i++) {
        printf("%.10lf ", ans[i]);
    }
    printf("\n");
}