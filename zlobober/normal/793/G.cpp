#include <cstdio>
#include <memory.h>
#include <cassert>
#include <vector>
using namespace std;

const int N = 2000500;

struct edge {
    int t, f, c;
};

int ept;
edge edges[N];

vector<int> E[N];

void add_edge(int a, int b, int c) {
    edges[ept++] = {b, 0, c};
    edges[ept++] = {a, 0, 0};
    E[a].push_back(ept - 2);
    E[b].push_back(ept - 1);
}

int D[N];
int Q[N];
int used[N];
int curu = 0;

int pt[N];

bool BFS(int s, int t) {
    int lpt = 0, rpt = 0;
    Q[rpt++] = s;
    D[s] = 0;
    used[s] = ++curu;
    while (lpt < rpt) {
        int x = Q[lpt++];
        pt[x] = 0;
        for (int e : E[x]) {
            auto& ed = edges[e];
            if (used[ed.t] == curu || ed.f == ed.c)
                continue;
            used[ed.t] = curu;
            D[ed.t] = D[x] + 1;
            Q[rpt++] = ed.t;
        }
    }
    return used[t] == curu;
}

const int inf = 1e9 + 42;

int push(int x, int t, int cur = inf) {
    if (x == t) {
        return cur;
    }
    int sum = 0;
    for (; pt[x] != (int)E[x].size(); pt[x]++) {
        auto &ed = edges[E[x][pt[x]]], &red = edges[E[x][pt[x]] ^ 1];
        if (ed.f == ed.c || D[ed.t] != D[x] + 1)
            continue;
        int rem = ed.c - ed.f;
        int pushed = push(ed.t, t, min(cur, rem));
        if (pushed) {
            ed.f += pushed;
            red.f -= pushed;
            cur -= pushed;
            sum += pushed;
        }
        if (cur == 0)
            break;
    }
    return sum;
}

int ver = 0;

const int M = 10500;
bool F[M][M];

int s, t;
vector<int> L, R;
vector<int> TL, TR;

void build(int l, int r, int v, int up, vector<int>& A, vector<int>& T) {
    T[v] = ver++;
    if (l == r) {
        A[l] = T[v];
        return;
    }
    build(l, (l + r) / 2, 2 * v, up, A, T);
    build((l + r) / 2 + 1, r, 2 * v + 1, up, A, T);
    if (up) {
        add_edge(T[2 * v], T[v], inf);
        add_edge(T[2 * v + 1], T[v], inf);
    } else {
        add_edge(T[v], T[2 * v], inf);
        add_edge(T[v], T[2 * v + 1], inf);
    }

}

void add(int l, int r, int L, int R, int v, int up, int x, vector<int>& T) {
    if (l <= L && R <= r) {
        if (up) {
            add_edge(T[v], x, inf);
        } else {
            add_edge(x, T[v], inf);
        }
        return;
    }
    if (r < L || l > R) {
        return;
    }
    add(l, r, L, (L + R) / 2, 2 * v, up, x, T);
    add(l, r, (L + R) / 2 + 1, R, 2 * v + 1, up, x, T);
}

int n;

void add_rect(int l1, int l2, int r1, int r2) {
    //fprintf(stderr, "adding rect [%d, %d] [%d, %d]\n", l1, l2, r1, r2);
    int c = ver++;
    add(l1, l2, 0, n - 1, 1, true, c, TL);
    add(r1, r2, 0, n - 1, 1, false, c, TR);
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        --x1, --y1, --x2, --y2;
        swap(x1, y1);
        swap(x2, y2);
        for (int y = y1; y <= y2; y++) {
            memset(F[y] + x1, 1, (x2 - x1 + 1) * sizeof(bool));
        }
    }
    int s = ver++;
    int t = ver++;
    L.resize(n);
    R.resize(n);
    TL.resize(4 * n);
    TR.resize(4 * n);
    build(0, n - 1, 1, true, L, TL);
    build(0, n - 1, 1, false, R, TR);
    for (int i = 0; i < n; i++) {
        add_edge(s, L[i], 1);
        add_edge(R[i], t, 1);
    }

    for (int i = 0; i < n; i++) {
        F[i][n] = true;
        F[n][i] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!F[i][j]) {
                int k = j;
                while (!F[i][k])
                    ++k;
                --k;
                int last = i;
                for (int z = i; z < n; z++) {
                    bool any = false;
                    for (int r = j; r <= k; r++) {
                        if (F[z][r]) {
                            any = true;
                            break;
                        }
                    }
                    if (any)
                        break;
                    last = z;
                }
                for (int z = i; z <= last; z++)
                    memset(F[z] + j, 1, (k - j + 1) * sizeof(bool));
                add_rect(i, last, j, k);
            }
        }
    }

    int flow = 0;
    while (true) {
        if (!BFS(s, t))
            break;
        int pushed = push(s, t);
        assert(pushed > 0);
        flow += pushed;
    }
    fprintf(stderr, "ver = %d, ept = %d\n", ver, ept);
    printf("%d\n", flow);
    //while(true);
}