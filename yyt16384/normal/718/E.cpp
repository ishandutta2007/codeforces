#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXS = 265;
const int SZ = 8;
const int INF = 0x3f3f3f3f;

struct InState {
    int n;
    int a[MAXN];
};

struct OutState {
    int ans1;
    long long ans2;
};

InState in;
OutState out;

void input()
{
    static char s[MAXN];
    scanf("%d%s", &in.n, s);
    for (int i = 0; i < in.n; i++) {
        in.a[i] = s[i] - 'a';
    }
}

void solve()
{
    static int idx[SZ][MAXN];
    static int idxn[SZ];
    memset(idxn, 0, sizeof(idxn));
    for (int i = 0; i < in.n; i++) {
        idx[in.a[i]][idxn[in.a[i]]++] = i;
    }
    static int dist[SZ][MAXN];
    static int distcol[SZ][SZ];
    for (int i = 0; i < SZ; i++) {
        static int que[MAXN];
        int qb = 0, qe = 0;
        memset(dist[i], INF, in.n * sizeof(*dist[i]));
        memset(distcol[i], INF, sizeof(distcol[i]));
        distcol[i][i] = 0;
        for (int j = 0; j < idxn[i]; j++) {
            dist[i][idx[i][j]] = 0;
            que[qe++] = idx[i][j];
        }
        while (qb < qe) {
            int x = que[qb++];
            if (x > 0 && dist[i][x - 1] == INF) {
                dist[i][x - 1] = dist[i][x] + 1;
                que[qe++] = x - 1;
            }
            if (x < in.n - 1 && dist[i][x + 1] == INF) {
                dist[i][x + 1] = dist[i][x] + 1;
                que[qe++] = x + 1;
            }
            if (distcol[i][in.a[x]] == INF) {
                distcol[i][in.a[x]] = dist[i][x];
                for (int j = 0; j < idxn[in.a[x]]; j++) {
                    if (dist[i][idx[in.a[x]][j]] == INF) {
                        dist[i][idx[in.a[x]][j]] = dist[i][x] + 1;
                        que[qe++] = idx[in.a[x]][j];
                    }
                }
            }
        }
    }
    static int distflag[MAXN];
    memset(distflag, 0, in.n * sizeof(*distflag));
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < in.n; j++) {
            if (dist[i][j] == distcol[i][in.a[j]] + 1) {
                distflag[j] |= 1 << i;
            }
        }
    }
    static int distflcol[SZ][MAXN];
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < idxn[i]; j++) {
            distflcol[i][j] = distflag[idx[i][j]];
        }
    }
    static int cnt[SZ][MAXS];
    for (int i = 0; i < SZ; i++) {
        memset(cnt[i], 0, (1 << SZ) * sizeof(*cnt[i]));
        for (int j = 0; j < idxn[i]; j++) {
            cnt[i][distflcol[i][j]]++;
        }
    }
    int ans1 = 1;
    long long ans2 = 0;
    for (int i = 0; i < SZ; i++) {
        ans2 += (long long)idxn[i] * (idxn[i] - 1) / 2;
    }
    for (int i = 0; i < SZ; i++) {
        static int ss1[MAXS];
        memcpy(ss1, cnt[i], (1 << SZ) * sizeof(*ss1));
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < (1 << SZ); k++) {
                if (!((k >> j) & 1)) {
                    ss1[k] += ss1[k | (1 << j)];
                }
            }
        }
        for (int j = i + 1; j < SZ; j++) {
            static int w[SZ];
            int minw = INF;
            for (int k = 0; k < SZ; k++) {
                w[k] = distcol[i][k] + distcol[j][k] + 1;
                minw = std::min(minw, w[k]);
            }
            int mask0 = 0;
            int mask1 = 0;
            for (int k = 0; k < SZ; k++) {
                if (w[k] == minw) {
                    mask0 |= 1 << k;
                } else if (w[k] == minw + 1) {
                    mask1 |= 1 << k;
                }
            }
            long long cnt1 = (long long)idxn[i] * idxn[j];
            long long cnt2 = (long long)idxn[i] * idxn[j];
            long long cnt3 = (long long)idxn[i] * idxn[j];
            for (int k = 0; k < (1 << SZ); k++) {
                cnt1 -= (long long)cnt[j][k] * ss1[~k & mask0];
                if ((k & mask0) == mask0) {
                    cnt2 -= (long long)cnt[j][k] * ss1[mask0 | (~k & mask1)];
                }
            }
            cnt3 -= cnt2;
            cnt2 -= cnt1;
            for (int k = 0, l = 0; k < idxn[i]; k++) {
                int x = idx[i][k];
                while (l < idxn[j] && idx[j][l] < x - 2 * SZ + 1) {
                    l++;
                }
                for (int p = l; p < idxn[j] && idx[j][p] <= x + 2 * SZ - 1; p++) {
                    int y = idx[j][p];
                    int w0;
                    if (((distflag[x] | distflag[y]) & mask0) != mask0) {
                        w0 = minw;
                        cnt1--;
                    } else if ((distflag[x] & distflag[y] & mask0) != mask0 || ((distflag[x] | distflag[y]) & mask1) != mask1) {
                        w0 = minw + 1;
                        cnt2--;
                    } else {
                        w0 = minw + 2;
                        cnt3--;
                    }
                    int d = std::min(w0, x > y ? x - y : y - x);
                    if (d > ans1) {
                        ans1 = d;
                        ans2 = 1;
                    } else if (d == ans1) {
                        ans2++;
                    }
                }
            }
            int d;
            long long t;
            if (cnt3) {
                d = minw + 2;
                t = cnt3;
            } else if (cnt2) {
                d = minw + 1;
                t = cnt2;
            } else if (cnt1) {
                d = minw;
                t = cnt1;
            } else {
                d = 0;
                t = 0;
            }
            if (d > ans1) {
                ans1 = d;
                ans2 = t;
            } else if (d == ans1) {
                ans2 += t;
            }
        }
    }
    out.ans1 = ans1;
    out.ans2 = ans2;
}

void output()
{
    printf("%d %" LLFORMAT "d\n", out.ans1, out.ans2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("718E.in", "r", stdin);
    freopen("718E.out", "w", stdout);
#endif

    input();
    solve();
    output();

#ifndef ONLINE_JUDGE
    fclose(stdin); fclose(stdout);
#endif
    return 0;
}