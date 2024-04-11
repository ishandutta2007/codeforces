#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 200005;
const int MAXS = 530005;
const int MAXLOGN = 19;
const int SZ = 26;
const int INF = 0x3f3f3f3f;

struct InState {
    int n;
    char s[MAXN];
};

struct OutState {
    int ans;
};

InState in;
OutState out;
int sa[MAXN];
int rank[MAXN];
int height[MAXN];
int hmin[MAXLOGN][MAXN];
int min1[MAXS];
int min2[MAXS];

void input()
{
    scanf("%d%s", &in.n, in.s);
}

void init_sa()
{
    int maxrank = SZ;
    for (int i = 0; i < in.n; i++) {
        rank[i] = in.s[i] - 'a';
    }
    for (int p = 1; p <= in.n; p <<= 1) {
        static int sum[MAXN];
        static int tmp[MAXN];
        memset(sum, 0, (maxrank + 1) * sizeof(*sum));
        for (int i = 0; i < in.n; i++) {
            sum[i + p < in.n ? rank[i + p] + 1 : 0]++;
        }
        for (int i = 1; i <= maxrank; i++) {
            sum[i] += sum[i - 1];
        }
        for (int i = in.n - 1; i >= 0; i--) {
            tmp[--sum[i + p < in.n ? rank[i + p] + 1 : 0]] = i;
        }
        memset(sum, 0, maxrank * sizeof(*sum));
        for (int i = 0; i < in.n; i++) {
            sum[rank[i]]++;
        }
        for (int i = 1; i < maxrank; i++) {
            sum[i] += sum[i - 1];
        }
        for (int i = in.n - 1; i >= 0; i--) {
            sa[--sum[rank[tmp[i]]]] = tmp[i];
        }
        maxrank = 1;
        for (int i = 0; i < in.n; i++) {
            if (i > 0 && (rank[sa[i]] != rank[sa[i - 1]] || (sa[i] + p < in.n ? rank[sa[i] + p] : -1) != (sa[i - 1] + p < in.n ? rank[sa[i - 1] + p] : -1))) {
                maxrank++;
            }
            tmp[sa[i]] = maxrank - 1;
        }
        memcpy(rank, tmp, in.n * sizeof(*rank));
    }
}

void init_height()
{
    for (int i = 0, j = 0; i < in.n; i++) {
        if (j > 0) {
            j--;
        }
        if (rank[i] == in.n - 1) {
            continue;
        }
        while (in.s[i + j] == in.s[sa[rank[i] + 1] + j]) {
            j++;
        }
        height[rank[i]] = j;
    }
}

void init_table()
{
    memcpy(hmin[0], height, (in.n - 1) * sizeof(*hmin[0]));
    for (int i = 1; i < MAXLOGN; i++) {
        for (int j = 0; j < in.n - (1 << i); j++) {
            hmin[i][j] = std::min(hmin[i - 1][j], hmin[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int findlb(int x, int w)
{
    for (int i = MAXLOGN - 1; i >= 0; i--) {
        if (x >= (1 << i) && hmin[i][x - (1 << i)] >= w) {
            x -= 1 << i;
        }
    }
    return x;
}

int findrb(int x, int w)
{
    for (int i = MAXLOGN - 1; i >= 0; i--) {
        if (x < in.n - (1 << i) && hmin[i][x] >= w) {
            x += 1 << i;
        }
    }
    return x;
}

void build1(int now, int l, int r)
{
    min1[now] = INF;
    if (l + 1 == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build1(now * 2 + 1, l, mid);
    build1(now * 2 + 2, mid, r);
}

void build2(int now, int l, int r)
{
    min2[now] = INF;
    if (l + 1 == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build2(now * 2 + 1, l, mid);
    build2(now * 2 + 2, mid, r);
}

void setval1(int now, int l, int r, int ql, int qr, int w)
{
    if (ql == l && qr == r) {
        min1[now] = std::min(min1[now], w);
        return;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        setval1(now * 2 + 1, l, mid, ql, qr, w);
    } else if (ql >= mid) {
        setval1(now * 2 + 2, mid, r, ql, qr, w);
    } else {
        setval1(now * 2 + 1, l, mid, ql, mid, w);
        setval1(now * 2 + 2, mid, r, mid, qr, w);
    }
}

int getmin1(int now, int l, int r, int x)
{
    if (l + 1 == r) {
        return min1[now];
    }
    int mid = (l + r) >> 1;
    if (x < mid) {
        return std::min(min1[now], getmin1(now * 2 + 1, l, mid, x));
    } else {
        return std::min(min1[now], getmin1(now * 2 + 2, mid, r, x));
    }
}

void setval2(int now, int l, int r, int x, int w)
{
    min2[now] = w;
    if (l + 1 == r) {
        return;
    }
    int mid = (l + r) >> 1;
    if (x < mid) {
        setval2(now * 2 + 1, l, mid, x, w);
    } else {
        setval2(now * 2 + 2, mid, r, x, w);
    }
}

int getmin2(int now, int l, int r, int ql, int qr)
{
    if (ql == l && qr == r) {
        return min2[now];
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return getmin2(now * 2 + 1, l, mid, ql, qr);
    } else if (ql >= mid) {
        return getmin2(now * 2 + 2, mid, r, ql, qr);
    } else {
        int wl = getmin2(now * 2 + 1, l, mid, ql, mid);
        int wr = getmin2(now * 2 + 2, mid, r, mid, qr);
        return std::min(wl, wr);
    }
}

void solve()
{
    init_sa();
    init_height();
    init_table();
    build1(0, 0, in.n);
    build2(0, 0, in.n);
    static int slen[MAXN];
    static int dep[MAXN];
    for (int i = in.n - 1; i >= 0; i--) {
        int u = getmin1(0, 0, in.n, rank[i]);
        if (u == INF) {
            slen[i] = 1;
            dep[i] = 1;
        } else {
            int l = findlb(rank[i], slen[u]);
            int r = findrb(rank[i], slen[u]);
            int w = getmin2(0, 0, in.n, l, r + 1);
            slen[i] = w - i + slen[u];
            dep[i] = dep[u] + 1;
        }
        int l = findlb(rank[i], slen[i]);
        int r = findrb(rank[i], slen[i]);
        setval1(0, 0, in.n, l, r + 1, i);
        setval2(0, 0, in.n, rank[i], i);
    }
    int ans = 0;
    for (int i = 0; i < in.n; i++) {
        ans = std::max(ans, dep[i]);
    }
    out.ans = ans;
}

void output()
{
    printf("%d\n", out.ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("700E.in", "r", stdin);
    freopen("700E.out", "w", stdout);
#endif

    input();
    solve();
    output();

#ifndef ONLINE_JUDGE
    fclose(stdin); fclose(stdout);
#endif
    return 0;
}