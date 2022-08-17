#include <cstdio>
#include <vector>
using namespace std;

const int N = 200500;

const int W = 5;

struct matrix {
    int A[W][W];
    matrix() {
    }
};

matrix id;


const int inf = (int)1e9;

matrix C[10];

void init() {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < W; j++) {
            id.A[i][j] = (i != j) ? inf : 0;
        }
    }
    for (int c = 0; c < 10; c++)
        C[c] = id;

    C[2].A[0][0] = 1;
    C[2].A[1][0] = C[2].A[1][1] = 0;

    C[0].A[1][1] = 1;
    C[0].A[2][1] = C[0].A[2][2] = 0;

    C[1].A[2][2] = 1;
    C[1].A[3][2] = C[1].A[3][3] = 0;

    C[6].A[3][3] = C[6].A[4][4] = 1;

    C[7].A[3][3] = 1;
    C[7].A[4][3] = C[7].A[4][4] = 0;
}

inline void mul(const matrix& a, const matrix& b, matrix& c) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < W; j++) {
            c.A[i][j] = inf;
            for (int k = 0; k < W; k++) {
                int t = b.A[i][k] + a.A[k][j];
                if (t < c.A[i][j])
                    c.A[i][j] = t;
            }
        }
    }
}


matrix L[N], R[N];

struct query {
    int l, r, id;
};

int ans[N];

matrix V[N];


void go(vector<query> Q, int l, int r) {
    if (r - l + 1 <= 3 || Q.empty()) {
        for (auto& q : Q)
            ans[q.id] = -1;
        return;
    }
    int m = (l + r) / 2;
    L[m + 1] = id;
    for (int i = m; i >= l; i--) {
        mul(V[i], L[i + 1], L[i]);
    }
    R[m] = id;
    for (int i = m + 1; i <= r; i++) {
        mul(R[i - 1], V[i], R[i]);
    }
    vector<query> A, B;
    for (query& q : Q) {
        if (q.l <= m + 1 && q.r >= m) {
            matrix X;
            mul(L[q.l], R[q.r], X);
            ans[q.id] = X.A[W - 1][0];
        } else if (q.l > m + 1) {
            B.emplace_back(q);
        } else if (q.r < m) {
            A.emplace_back(q);
        }
    }
    go(A, l, m);
    go(B, m + 1, r);
}


char buf[N];

int main() {
    init();
    int n, q;
    scanf("%d %d ", &n, &q);
    scanf("%s", buf);
    for (int i = 0; i < n; i++) {
        V[i] = C[buf[i] - '0'];
    }
    vector<query> Q;
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        Q.emplace_back(query {l, r, i});
    }
    go(Q, 0, n - 1);
    for (int i = 0; i < q; i++) {
        if (ans[i] >= inf / 2)
            ans[i] = -1;
        printf("%d\n", ans[i]);
    }
}