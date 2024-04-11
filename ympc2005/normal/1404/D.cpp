#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, p[N], c[N];

vector <int> e[N];

void dfs_(int u) {
    for (int v : e[u]) {
        if (!c[v]) {
            c[v] = 3 - c[u];
            dfs_(v);
        }
    }
}

int main() {
    scanf("%d", &n);

    if (!(n&1)) {
        puts("First");
        fflush(stdout);

        for (int i = 1; i <= 2*n; i++) {
            printf("%d ", i%n + 1);
        }

        puts("");
        fflush(stdout);
        exit(0);
    }

    puts("Second");
    fflush(stdout);

    for (int x, i = 1; i <= 2*n; i++) {
        scanf("%d", &x);

        if (!p[x]) {
            p[x] = i;
        } else {
            e[p[x]].push_back(i);
            e[i].push_back(p[x]);
        }

        if (i <= n) {
            e[i].push_back(i + n);
            e[i + n].push_back(i);
        }
    }

    for (int i = 1; i <= 2*n; i++) {
        if (!c[i]) {
            c[i] = 1;
            dfs_(i);
        }
    }

    int sum = 0;

    for (int i = 1; i <= 2*n; i++) {
        if (c[i] == 1) {
            sum = (sum + i)%(n*2);
        }
    }

    int f = sum ? 2 : 1;

    for (int i = 1; i <= 2*n; i++) {
        if (c[i] == f) {
            printf("%d ", i);
        }
    }

    puts("");
    fflush(stdout);
}