#include <cstdio>
#include <memory.h>
#include <cassert>
#include <algorithm>
#include <unistd.h>
using namespace std;

inline char nextChar() {
    const int SIZE = int(1e6);
    static char buf[SIZE];
    static int ptr = 0, cur_sz = 0;
    static bool eof = false;
    if (eof) {
        return -1;
    }
    if (ptr < cur_sz) {
        return buf[ptr++];
    }
    for (;;) {
        int cur = read(0, buf, SIZE);
        if (cur <= 0) {
            eof = true;
            return -1;
        }
        if (cur > 0) {
            cur_sz = cur;
            ptr = 0;
            return buf[ptr++];
        }
    }
}

inline int nextInt() {
    int res = 0;
    char ch = nextChar();
    while (!(ch >= '0' && ch <= '9')) {
        ch = nextChar();
    }
    while (ch >= '0' && ch <= '9') {
        res = res * 10 + ch - '0';
        ch = nextChar();
    }
    return res;
}


const int N = 1024;
int F[N][N];

inline int get(int _y, int _x) {
    int ans = 0;
    for (int x = _x; x >= 0; x &= x + 1, --x) {
        for (int y = _y; y >= 0; y &= y + 1, --y) {
            ans += F[y][x];
        }
    }
    return ans;
}

inline void upd(int _y, int _x, int d) {
    for (int y = _y; y < N; y |= y + 1) {
        for (int x = _x; x < N; x |= x + 1) {
            F[y][x] += d;
        }
    }
}

pair<int, int> perm[N * N];

int S[N][N];

inline int get(int y1, int x1, int y2, int x2) {
    return S[y2][x2] - S[y1][x2] - S[y2][x1] + S[y1][x1];
}

int mx[N][N];
const int M = 1000500;

int QX1[M], QY1[M], QX2[M], QY2[M];

pair<int, int> order[N * N];

int L[M], R[M], BS[M];

vector<int> byBS[N];

char out[M * 8];

inline int getf(int y1, int x1, int y2, int x2) {
    return get(y2, x2) - get(y1 - 1, x2) - get(y2, x1 - 1) + get(y1 - 1, x1 - 1);
}

void test_speed() {
    /*const int n = 1000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            perm[i * n + j] = make_pair(i, j);
        }
    }
    random_shuffle(perm, perm + n * n);
    upd(0, 0, 1);
    for (int k = 0; k < 10; k++) {
        for (auto i = 0; i < n * n; i++) {
            auto pr = perm[i];
            int s = get(pr.first, pr.second) - get(pr.first - 1, pr.second) - get(pr.first, pr.second - 1) + get(pr.first - 1, pr.second - 1);
            upd(pr.first, pr.second, s);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            ans += F[i][j];
    }
    printf("%d\n", ans);*/
    exit(0);
}

int main() {
    int n, m;
    n = nextInt();
    m = nextInt();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c = nextInt();
            S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + c;
        }
    }

    int opt = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            mx[i][j] = mx[i + 1][j + 1] + 1;
            while (mx[i][j] >= 0 && get(i, j, i + mx[i][j], j + mx[i][j]) < mx[i][j] * mx[i][j])
                --mx[i][j];
            assert(mx[i][j] != -1);
            order[opt++] = make_pair(mx[i][j], i * m + j);
        }
    }
    sort(order, order + opt);
    int q = nextInt();
    for (int i = 0; i < q; i++) {
        QY1[i] = nextInt() - 1;
        QX1[i] = nextInt() - 1;
        QY2[i] = nextInt() - 1;
        QX2[i] = nextInt() - 1;
        L[i] = 0, R[i] = min(QY2[i] - QY1[i], QX2[i] - QX1[i]) + 2;
    }
    for (int it = 0; ; it++) {
        bool any = false;
        for (int i = 0; i <= min(n, m); i++)
            byBS[i].clear();
        for (int i = 0; i < q; i++) {
            int& l = L[i];
            int& r = R[i];
            if (r - l == 1) {
                BS[i] = -1;
                continue;
            } else {
                any = true;
                BS[i] = (l + r) / 2;
                byBS[BS[i]].push_back(i);
            }
        }
        memset(F, 0, sizeof(F));
        opt = n * m - 1;
        for (int c = min(n, m) + 1; c >= 0; c--) {
            while (opt >= 0 && order[opt].first >= c) {
                int x = order[opt].second % m;
                int y = order[opt].second / m;
                upd(y, x, 1);
                --opt;
            }
            for (int i : byBS[c]) {
                int y1 = QY1[i], x1 = QX1[i];
                int y2 = QY2[i] - (BS[i] - 1);
                int x2 = QX2[i] - (BS[i] - 1);
                int g = getf(y1, x1, y2, x2);
                if (g > 0) {
                    L[i] = BS[i];
                } else {
                    R[i] = BS[i];
                }
            }
        }
        if (!any)
            break;
    }

    opt = 0;
    for (int i = 0; i < q; i++) {
        printf("%d\n", L[i]);
    }
}