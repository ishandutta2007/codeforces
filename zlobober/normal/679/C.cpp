#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 1505;
int A[N][N];
int S[N][N];

int n;

int col[N][N];
int colsz[N * N];

int vy[] = {1, 0, -1, 0};
int vx[] = {0, 1, 0, -1};

int DFS(int y, int x, int c) {
    col[y][x] = c;
    int sz = 1;
    for (int v = 0; v < 4; v++) {
        int ty = y + vy[v];
        int tx = x + vx[v];
        if (ty < 0 || tx < 0 || ty >= n || tx >= n || !A[ty][tx])
            continue;
        if (col[ty][tx] == -1)
            sz += DFS(ty, tx, c);
    }
    return sz;
}

int sum_comp = 0;
int in[N * N];

int get_blocked(int y1, int x1, int y2, int x2) {
    x1 = max(0, x1);
    y1 = max(0, y1);
    y2 = min(n, y2);
    x2 = min(n, x2);
    if (x1 >= x2 || y1 >= y2)
        return 0;
    return S[y2][x2] + S[y1][x1] - S[y2][x1] - S[y1][x2];
}

void add(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= n)
        return;
    if (col[y][x] == -1) {
        //blocked++;
    } else {
        in[col[y][x]]++;
        if (in[col[y][x]] == 1)
            sum_comp += colsz[col[y][x]];
    }
}

void del(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= n)
        return;
    if (col[y][x] == -1) {
        //blocked--;
    } else {
        in[col[y][x]]--;
        if (in[col[y][x]] == 0)
            sum_comp -= colsz[col[y][x]];
    }
}

int main() {
    int k;
    scanf("%d %d", &n, &k);
    k += 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            scanf(" %c ", &c);
            if (c == '.')
                A[i][j] = 1;
            S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + 1 -  A[i][j];
        }
    }
    memset(col, -1, sizeof(col));
    int pt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] && col[i][j] == -1)
                colsz[pt] = DFS(i, j, pt), pt++;
        }
    }
    int ans = 0;
    for (int c = -k; c <= n; c++) {
        int x2 = c + k - 1;
        int x1 = x2 - k + 2;
        int x0 = x1 - 1;
        if (x1 < 0 || x1 + k - 3 >= n)
            continue;
        for (int r = 0; r <= n + k; r++) {
            int y2 = r;
            int y1 = y2 - k + 2;
            int y0 = y1 - 1;
            for (int j = c; j < c + k; j++) {
                add(r, j);
                del(r - k, j);
            }
            del(y0, x0);
            del(y0, x2);
            del(y2, x0);
            del(y2, x2);
            ans = max(ans, get_blocked(y1, x1, y2, x2) + sum_comp);
            add(y0, x0);
            add(y0, x2);
            add(y2, x0);
            add(y2, x2);
        }
    }
    printf("%d\n", ans);
}