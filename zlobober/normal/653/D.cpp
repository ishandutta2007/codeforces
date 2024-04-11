#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

const int N = 100500;

struct edge {
    int to;
    int f, c;
    int nxt;
};

edge E[N];
int first[N];

const int IT = 100;
vector<tuple<int, int, int>> EE;


int ept = 0;
void add_edge(int a, int b, int c) {
    E[ept] = {b, 0, c, first[a]};
    E[ept + 1] = {a, 0, 0, first[b]};
    first[a] = ept;
    first[b] = ept + 1;
    ept += 2;
}

int prv[N];
int Q[N];
int used[N];
int mn[N];
int curver = 1;
int n;
int BFS() {
    int l = 0, r = 0;
    Q[r++] = 1;
    curver++;
    used[1] = curver;
    mn[1] = 1e9;
    while (l < r) {
        int x = Q[l++];
        for (int e = first[x]; e != -1; e = E[e].nxt) {
            if (used[E[e].to] == curver)
                continue;
            if (E[e].c > E[e].f) {
                prv[E[e].to] = e;
                used[E[e].to] = curver;
                Q[r++] = E[e].to;
                mn[E[e].to] = min(mn[x], E[e].c - E[e].f);
            }
        }
    }
    if (used[n] != curver)
        return 0;
    int pushed = mn[n];
    for (int x = n; x != 1; x = E[prv[x] ^ 1].to) {
        E[prv[x]].f += pushed;
        E[prv[x] ^ 1].f -= pushed;
    }
    return pushed;
}

int x;

bool can(double w) {
    ept = 0;
    memset(first, -1, sizeof(int) * (n + 1));
    for (auto t : EE) {
        int a, b, c;
        tie(a, b, c) = t;
        add_edge(a, b, min(N * 1.0, c / w));
    }
    int flow = 0;
    int pushed = 0;
    while ((pushed = BFS()) && flow < x)
        flow += pushed;
    return flow >= x;
}

int main() {
    int m;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        EE.emplace_back(a, b, c);
    }
    double l = 0, r = 1e6 + 42;
    for (int it = 0; it < IT; it++) {
        double w = (l + r) / 2;
        if (can(w))
            l = w;
        else
            r = w;
    }
    printf("%.10lf\n", x * (l + r) / 2);
}