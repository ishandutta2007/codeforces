#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXM = 200005;
const int LN = 20;

int N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
int BL[MAXN << 1], ID[MAXN << 1], VAL[2][MAXN];
long long ANS[MAXM];
int d[MAXN], l[MAXN], r[MAXN];
bool VIS[MAXN];
int type[MAXN];
vector < int > adjList[MAXN];

struct query{
    int id, l, r, lc;
    inline friend bool operator < (query lhs, query rhs){
        return (BL[lhs.l] == BL[rhs.l]) ? (lhs.r < rhs.r) : (BL[lhs.l] < BL[rhs.l]);
    }
}Q[MAXM];

void dfs(int u, int par){
    l[u] = ++cur;
    ID[cur] = u;
    for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
    for (int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        if (v == par) continue;
        LVL[v] = LVL[u] + 1;
        DP[0][v] = u;
        dfs(v, u);
    }
    r[u] = ++cur; ID[cur] = u;
}

inline int lca(int u, int v){
    if (LVL[u] > LVL[v]) swap(u, v);
    for (int i = LN - 1; i >= 0; i--)
        if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
    if (u == v) return u;
    for (int i = LN - 1; i >= 0; i--){
        if (DP[i][u] != DP[i][v]){
            u = DP[i][u];
            v = DP[i][v];
        }
    }
    return DP[0][u];
}

inline void check(int x, long long& res){
    // If (x) occurs twice, then don't consider it's value
    if (VIS[x]) {
        res -= VAL[type[x] ^ 1][A[x]];
        VAL[type[x]][A[x]]--;
    } else {
        res += VAL[type[x] ^ 1][A[x]];
        VAL[type[x]][A[x]]++;
    }
    VIS[x] ^= 1;
}

void compute(){

    int curL = Q[0].l, curR = Q[0].l - 1;
    long long res = 0;

    for (int i = 0; i < M; i++){

        while (curL < Q[i].l) check(ID[curL++], res);
        while (curL > Q[i].l) check(ID[--curL], res);
        while (curR < Q[i].r) check(ID[++curR], res);
        while (curR > Q[i].r) check(ID[curR--], res);

        int u = ID[curL], v = ID[curR];

        if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);

        ANS[Q[i].id] = res;

        if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
    }

    for (int i = 0; i < M; i++) printf("%lld\n", ANS[i]);
}

int main(){
    int u, v, x;
    int t = 1;
    while (t--){
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &type[i]);
        }
        cur = 0;
        memset(VIS, 0, sizeof(VIS));
        memset(VAL, 0, sizeof(VAL));
        for (int i = 1; i <= N; i++) adjList[i].clear();
        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        memcpy(d + 1, A + 1, sizeof(int) * N);

        sort(d + 1, d + N + 1);
        K = unique(d + 1, d + N + 1) - d - 1;
        for (int i = 1; i <= N; i++) A[i] = lower_bound(d + 1, d + K + 1, A[i]) - d;

        for (int i = 1; i < N; i++){
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        DP[0][1] = 1;
        dfs(1, -1);
        int size = max(1, (int) sqrt(cur));

        for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;

        scanf("%d", &M);
        for (int i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            Q[i].lc = lca(u, v);
            if (l[u] > l[v]) swap(u, v);
            if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
            else Q[i].l = r[u], Q[i].r = l[v];
            Q[i].id = i;
        }

        sort(Q, Q + M);
        compute();
    }
}