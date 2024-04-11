#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = 1050;

char F[N][N];
int S[N][N];

bool empty(int y1, int x1, int y2, int x2) {
    assert(y1 == y2 || x1 == x2);
    if (y1 > y2)
        swap(y1, y2);
    if (x1 > x2)
        swap(x1, x2);
    return S[y2 + 1][x2 + 1] - S[y1][x2 + 1] - S[y2 + 1][x1] + S[y1][x1] == 0;
}

void yes() {
    puts("YES");
    exit(0);
}

void no() {
    puts("NO");
    exit(0);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", F[i]);
    }
    int sy = -1, sx = -1;
    int ty = -1, tx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (F[i][j] == 'S')
                sy = i, sx = j;
            if (F[i][j] == 'T')
                ty = i, tx = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            S[i + 1][j + 1] = S[i + 1][j] + S[i][j + 1] - S[i][j] + (F[i][j] == '*');
        }
    }

    if (sy == ty || sx == tx) {
        if (empty(sy, sx, ty, tx)) {
            yes();
        }
    }
    for (int x = 0; x < m; x++) {
        if (empty(sy, sx, sy, x) && empty(sy, x, ty, x) && empty(ty, x, ty, tx)) {
            yes();
        }
    }
    for (int y = 0; y < n; y++) {
        if (empty(sy, sx, y, sx) && empty(y, sx, y, tx) && empty(y, tx, ty, tx)) {
            yes();
        }
    }
    if (empty(sy, sx, ty, sx) && empty(ty, sx, ty, tx)) {
        yes();
    }
    if (empty(sy, sx, sy, tx) && empty(sy, tx, ty, tx)) {
        yes();
    }
    no();
}