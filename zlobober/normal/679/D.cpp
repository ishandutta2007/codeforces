#include <cstdio>
#include <cassert>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 405;

int A[N][N];
int D[N][N];
double P[N];

int ord[N];
int pos[N];
int cnt[N];
double prob_le[N], prob_eq[N], prob_gr[N];
int deg[N];

struct lazy_guy {
    int y = 0;
    int ver = 0;
    int gpt = 0;
    void init(int _y) {
        y = _y;
        ver++;
        gpt = 0;
    }
    double prob[N];
    double gmx[N], gsum[N];
    int group_ver[N];
    int groups[N];
    void set_prob(int v, double p) {
        int g = D[y][v];
        if (group_ver[g] != ver) {
            gmx[g] = 0; //gsum[g] = 0.0;
            group_ver[g] = ver;
            groups[gpt++] = g;
        }
        gmx[g] = max(gmx[g], p);
        //gsum[g] += p;
    }
    double ans() {
        double sum = 0;
        for (int ig = 0; ig < gpt; ig++) {
            int g = groups[ig];
            sum += gmx[g];
        }
        return sum;
    }
} L;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        A[a][b] = A[b][a] = 1;
        deg[a]++, deg[b]++;
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            D[y][x] = A[y][x] ? 1 : N;
        }
        D[x][x] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    double ans = 0;

    for (int i = 0; i < n; i++)
        ord[i] = i;

    for (int x = 0; x < n; x++) {
        int mxd = *max_element(D[x], D[x] + n);

        sort(ord, ord + n, [&](int i, int j) { return D[x][i] < D[x][j]; });
        for (int d = 0; d <= mxd + 1; d++) {
            pos[d] = n;
            for (int i = 0; i < n; i++) {
                if (D[x][ord[i]] >= d) {
                    pos[d] = i;
                    break;
                }
            }
        }

        memset(cnt, 0, sizeof(int) * (mxd + 1));
        for (int i = 0; i < n; i++)
            cnt[D[x][i]]++;

        for (int i = 0; i < n; i++)
            prob_le[i] = prob_eq[i] = prob_gr[i] = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j]) {
                    if (D[x][j] > D[x][i])
                        prob_gr[j] += 1.0 / deg[i];
                    else if (D[x][j] == D[x][i])
                        prob_eq[j] += 1.0 / deg[i];
                    else if (D[x][j] < D[x][i])
                        prob_le[j] += 1.0 / deg[i];
                }
            }
        }
        double cur = 0;
        for (int dx = 0; dx <= mxd; dx++) {
            double prob1 = cnt[dx] * 1.0 / n;
            double prob2 = 0;
            for (int y = 0; y < n; y++) {
                L.init(y);
                for (int i = pos[max(0, dx - 1)]; i < pos[min(mxd + 1, dx + 2)]; i++) {
                    int v = ord[i];
                    double p = -42;
                    if (D[x][v] == dx - 1) {
                        p = prob_le[v];
                    } else if (D[x][v] == dx) {
                        p = prob_eq[v];
                    } else if (D[x][v] == dx + 1) {
                        p = prob_gr[v];
                    } else {
                        assert(false);
                    }
                    p *= 1.0 / cnt[dx];
                    L.set_prob(v, p);
                }
                prob2 = max(prob2, L.ans());
            }
            double prob3 = 1.0 / cnt[dx];
            cur += prob1 * max(prob2, prob3);
        }
        ans = max(ans, cur);
    }
    printf("%.10lf\n", ans);

}