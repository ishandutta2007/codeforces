#include <bits/stdc++.h>

const long long INF = 1E18;
const int SIZE = 1 << 24, MASK = SIZE - 1;

int N, M, G, R;
int D[10010];
int ql[SIZE], qg[SIZE], q, p;
int inq[10010][1010];
long long t[10010][1010];
long long min_time = INF;

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i)
        scanf("%d", &D[i]);
    std::sort(D, D + M);
    scanf("%d%d", &G, &R);
    for (int i = 0; i < M; ++i)
        for (int j = 0; j <= G; ++j)
            t[i][j] = INF;
    ql[0] = 0; qg[0] = G; t[0][G] = 0; inq[0][G] = 1;
    q = 0; p = 1;
    while (q < p) {
        int l = ql[q & MASK], g = qg[q & MASK];
        inq[l][g] = 0; ++q;
        if (l == M - 1) {
            if (g == G) {
                min_time = std::min(min_time, t[l][g] - R);
            } else {
                min_time = std::min(min_time, t[l][g]);
            }
            continue;
        }
        if (t[l][g] > min_time) continue;
        for (int dir = -1; dir <= 1; dir += 2) {
            if (l + dir >= 0 && l + dir < M) {
                int nl = l + dir, ng = g - std::abs(D[l + dir] - D[l]);
                long long nt = t[l][g] + std::abs(D[l + dir] - D[l]);
                if (ng >= 0) {
                    if (ng == 0) {
                        ng = G;
                        nt += R;
                    }
                    if (t[nl][ng] > nt) {
                        t[nl][ng] = nt;
                        if (!inq[nl][ng]) {
                            ql[p & MASK] = nl;
                            qg[p & MASK] = ng;
                            inq[nl][ng] = true;
                            ++p;
                        }
                    }
                }
            }
        }
    }
    if (min_time == INF) {
        puts("-1");
    } else {
        printf("%lld\n", min_time);
    }
}