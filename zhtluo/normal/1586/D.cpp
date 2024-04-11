#include <bits/stdc++.h>

int N;
int next[500], app[500];
int trav[500];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        printf ("?");
        for (int j = 1; j <= N; ++j) if (i == j) printf(" 1"); else printf(" 2");
        puts("");
        fflush(stdout);
        int u; scanf("%d", &u);
        if (u != 0 && u != i) next[u] = i, app[i] = 1;

        printf ("?");
        for (int j = 1; j <= N; ++j) if (i == j) printf(" 2"); else printf(" 1");
        puts("");
        fflush(stdout);
        scanf("%d", &u);
        if (u != 0 && u != i) next[i] = u, app[u] = 1;
    }
    printf("!"); int begin = -1;
    for (int i = 1; i <= N; ++i) if (!app[i]) begin = i;
    for (int i = 1; i <= N; ++i) {
        trav[begin] = i;
        begin = next[begin];
    }
    for (int i = 1; i <= N; ++i) {
        printf(" %d", trav[i]);
    }
    puts("");
    fflush(stdout);
}