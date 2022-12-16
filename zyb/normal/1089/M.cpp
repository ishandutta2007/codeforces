#include <bits/stdc++.h>
using namespace std;

const int maxn = 11;

char mat[18][3][2 * 4 * 9];
int ok[maxn][maxn];
int anc[maxn], inx[maxn];
int n, N;
int Floor[maxn];

void work() {
    int w = max(N * (N - 1), n );
    for (int i = 0; i < 2 * N; i++) {
        if (i & 1) {
            for (int k = 0; k < w; k++)
                if (k & 1) mat[i][0][k] = '#';
                else mat[i][0][k] = '.';
            for (int k = 0; k < w; k++)
                mat[i][1][k] = '#';
            for (int k = 0; k < w; k++)
                mat[i][2][k] = '.';
        }
        else {
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < w; k++) mat[i][j][k] = '#';
            for (int j = 0; j < w; j++)
                if (!(j & 1)) mat[i][0][j] = '.';
        }
    }
    int cur = 2 * N - 1;
    for (int i = 1; i <= n; i++)
        if (anc[ inx[i] ] == inx[i]) { Floor[ inx[i] ] = cur; cur -= 2; }

    int nxt = 0;
    for (int i = 1; i <= n; i++) {
        int u = inx[i];
        if (anc[u] != u) continue;
        int ptr = 0;
        for (int j = 1; j <= n; j++)
            if (ok[u][j] && ok[j][u]) mat[ Floor[u] ][2][ptr++] = j + '0';

        for (int j = 1; j <= n; j++)
            if (j != u && anc[j] == j && ok[u][j]) {
                mat[ Floor[u] ][1][nxt] = '.';
                mat[ Floor[j] ][1][nxt] = '.';
                mat[ Floor[j] - 1 ][0][nxt] = '#';
                nxt += 2;
            }
    }

    printf("%d %d %d\n", w, 3, 2 * N);
    for (int i = 2 * N - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < w; k++) putchar(mat[i][j][k]);
            puts("");
        }
        puts("");
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &ok[i][j]);
    for (int i = 1; i <= n; i++) ok[i][i] = true;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (ok[i][k] && ok[k][j]) ok[i][j] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (ok[i][j] && ok[j][i]) { anc[i] = j; break; }
    N = 0;
    for (int i = 1; i <= n; i++) N += (anc[i] == i);

    for (int i = 1; i <= n; i++) inx[i] = i;
    do {
        bool flag = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                if (anc[ inx[i] ] == inx[i] && anc[ inx[j] ] == inx[j] && ok[ inx[i] ][ inx[j] ]) {
                    flag = false;
                    break;
                }

        if (!flag) continue;
        work();
        break;
    } while (next_permutation(inx + 1, inx + n + 1));
    return 0;
}