#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 500005;

struct Graph {
    struct Edge {
        int y;
        int next;
    };

    int n;
    Edge e[2 * MAXN];
    int eh[MAXN];
    int en;
    int fa[MAXN];
    int que[MAXN];

    void init(int n_)
    {
        n = n_;
        memset(eh, -1, n * sizeof(*eh));
        en = 0;
    }

    void addedge_one(int x, int y)
    {
        e[en].y = y;
        e[en].next = eh[x];
        eh[x] = en++;
    }

    void addedge(int x, int y)
    {
        addedge_one(x, y);
        addedge_one(y, x);
    }

    void BFS(int s);
};

void Graph::BFS(int s)
{
    int qb = 0, qe = 1;
    que[0] = s;
    fa[s] = -1;
    while (qb < qe) {
        int x = que[qb++];
        for (int i = eh[x]; i != -1; i = e[i].next) {
            if (e[i].y != fa[x]) {
                fa[e[i].y] = x;
                que[qe++] = e[i].y;
            }
        }
    }
}

struct InState {
    int n;
    int e1[MAXN][2];
    int e2[MAXN][2];
};

struct OutState {
    int ansn;
    int ans[MAXN][4];
};

InState in;
OutState out;

void input()
{
    scanf("%d", &in.n);
    for (int i = 0; i < in.n - 1; i++) {
        scanf("%d%d", &in.e1[i][0], &in.e1[i][1]);
        in.e1[i][0]--;
        in.e1[i][1]--;
    }
    for (int i = 0; i < in.n - 1; i++) {
        scanf("%d%d", &in.e2[i][0], &in.e2[i][1]);
        in.e2[i][0]--;
        in.e2[i][1]--;
    }
}

void solve()
{
    static Graph g1;
    static Graph g2;
    g1.init(in.n);
    for (int i = 0; i < in.n - 1; i++) {
        g1.addedge(in.e1[i][0], in.e1[i][1]);
    }
    g2.init(in.n);
    for (int i = 0; i < in.n - 1; i++) {
        g2.addedge(in.e2[i][0], in.e2[i][1]);
    }
    g1.BFS(0);
    g2.BFS(0);
    static bool fl1[MAXN];
    static bool fl2[MAXN];
    memset(fl1, false, in.n * sizeof(*fl1));
    memset(fl2, false, in.n * sizeof(*fl2));
    for (int i = 1; i < in.n; i++) {
        int p = g1.fa[i];
        if (g2.fa[i] == p) {
            fl1[i] = true;
            fl2[i] = true;
        } else if (g2.fa[p] == i) {
            fl1[i] = true;
            fl2[p] = true;
        }
    }
    out.ansn = 0;
    for (int i = in.n - 1; i >= 1; i--) {
        int x = g1.que[i];
        if (fl1[x]) {
            continue;
        }
        int y = x;
        while (fl2[y]) {
            y = g2.fa[y];
        }
        out.ans[out.ansn][0] = x;
        out.ans[out.ansn][1] = g1.fa[x];
        out.ans[out.ansn][2] = y;
        out.ans[out.ansn][3] = g2.fa[y];
        out.ansn++;
    }
}

void output()
{
    printf("%d\n", out.ansn);
    for (int i = 0; i < out.ansn; i++) {
        printf("%d %d %d %d\n", out.ans[i][0] + 1, out.ans[i][1] + 1, out.ans[i][2] + 1, out.ans[i][3] + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("650E.in", "r", stdin);
    freopen("650E.out", "w", stdout);
#endif

    input();
    solve();
    output();

#ifndef ONLINE_JUDGE
    fclose(stdin); fclose(stdout);
#endif
    return 0;
}