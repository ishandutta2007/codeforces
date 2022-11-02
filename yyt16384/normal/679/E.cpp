#include <cstdio>
#include <set>
#include <utility>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXQ = 100005;
const int MAXS = 270005;
const int BASE = 42;
const int CNT = 11;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

struct InState {
    int n, q;
    int a[MAXN];
    int qtype[MAXQ];
    int qr[MAXQ][3];
};

struct OutState {
    int ansn;
    long long ans[MAXQ];
};

InState in;
OutState out;
long long minval[MAXS];
int minpos[MAXS];
long long flagadd[MAXS];
bool flagclear[MAXS];

void input()
{
    scanf("%d%d", &in.n, &in.q);
    for (int i = 0; i < in.n; i++) {
        scanf("%d", &in.a[i]);
    }
    for (int i = 0; i < in.q; i++) {
        scanf("%d", &in.qtype[i]);
        if (in.qtype[i] == 1) {
            scanf("%d", &in.qr[i][0]);
            in.qr[i][0]--;
        } else if (in.qtype[i] == 2) {
            scanf("%d%d%d", &in.qr[i][0], &in.qr[i][1], &in.qr[i][2]);
            in.qr[i][0]--;
        } else if (in.qtype[i] == 3) {
            scanf("%d%d%d", &in.qr[i][0], &in.qr[i][1], &in.qr[i][2]);
            in.qr[i][0]--;
        }
    }
}

void clearval_one(int now)
{
    minval[now] = INFLL;
    flagclear[now] = true;
}

void addval_one(int now, long long w)
{
    minval[now] += w;
    flagadd[now] += w;
}

void update_down(int now)
{
    if (flagclear[now]) {
        clearval_one(now * 2 + 1);
        clearval_one(now * 2 + 2);
        flagclear[now] = false;
        flagadd[now] = 0;
    }
    if (flagadd[now]) {
        addval_one(now * 2 + 1, flagadd[now]);
        addval_one(now * 2 + 2, flagadd[now]);
        flagadd[now] = 0;
    }
}

void update_up(int now)
{
    if (minval[now * 2 + 1] <= minval[now * 2 + 2]) {
        minval[now] = minval[now * 2 + 1];
        minpos[now] = minpos[now * 2 + 1];
    } else {
        minval[now] = minval[now * 2 + 2];
        minpos[now] = minpos[now * 2 + 2];
    }
}

void build(int now, int l, int r, const long long *w)
{
    flagadd[now] = 0;
    flagclear[now] = false;
    if (l + 1 == r) {
        minval[now] = w[l];
        minpos[now] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(now * 2 + 1, l, mid, w);
    build(now * 2 + 2, mid, r, w);
    update_up(now);
}

void clearval(int now, int l, int r, int ql, int qr)
{
    if (ql == l && qr == r) {
        clearval_one(now);
        return;
    }
    update_down(now);
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        clearval(now * 2 + 1, l, mid, ql, qr);
    } else if (ql >= mid) {
        clearval(now * 2 + 2, mid, r, ql, qr);
    } else {
        clearval(now * 2 + 1, l, mid, ql, mid);
        clearval(now * 2 + 2, mid, r, mid, qr);
    }
    update_up(now);
}

void addval(int now, int l, int r, int ql, int qr, long long w)
{
    if (ql == l && qr == r) {
        addval_one(now, w);
        return;
    }
    update_down(now);
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        addval(now * 2 + 1, l, mid, ql, qr, w);
    } else if (ql >= mid) {
        addval(now * 2 + 2, mid, r, ql, qr, w);
    } else {
        addval(now * 2 + 1, l, mid, ql, mid, w);
        addval(now * 2 + 2, mid, r, mid, qr, w);
    }
    update_up(now);
}

void setval(int now, int l, int r, int x, long long w)
{
    if (l + 1 == r) {
        minval[now] = w;
        return;
    }
    update_down(now);
    int mid = (l + r) >> 1;
    if (x < mid) {
        setval(now * 2 + 1, l, mid, x, w);
    } else {
        setval(now * 2 + 2, mid, r, x, w);
    }
    update_up(now);
}

std::pair<long long, int> getmin(int now, int l, int r, int ql, int qr)
{
    if (ql == l && qr == r) {
        return std::make_pair(minval[now], minpos[now]);
    }
    update_down(now);
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return getmin(now * 2 + 1, l, mid, ql, qr);
    } else if (ql >= mid) {
        return getmin(now * 2 + 2, mid, r, ql, qr);
    } else {
        std::pair<long long, int> s1 = getmin(now * 2 + 1, l, mid, ql, mid);
        std::pair<long long, int> s2 = getmin(now * 2 + 2, mid, r, mid, qr);
        return s1.first <= s2.first ? s1 : s2;
    }
}

long long getval(int now, int l, int r, int x)
{
    if (l + 1 == r) {
        return minval[now];
    }
    update_down(now);
    int mid = (l + r) >> 1;
    if (x < mid) {
        return getval(now * 2 + 1, l, mid, x);
    } else {
        return getval(now * 2 + 2, mid, r, x);
    }
}

void solve()
{
    static long long badvals[CNT];
    badvals[0] = 1;
    for (int i = 1; i < CNT; i++) {
        badvals[i] = badvals[i - 1] * BASE;
    }
    static int badid[MAXN];
    for (int i = 0; i < in.n; i++) {
        for (int j = 0; j < CNT; j++) {
            if (in.a[i] < badvals[j]) {
                badid[i] = j;
                break;
            }
        }
    }
    static long long ws[MAXN];
    for (int i = 0; i < in.n; i++) {
        ws[i] = badvals[badid[i]] - in.a[i];
    }
    build(0, 0, in.n, ws);
    std::set<int> goodidx;
    for (int i = 0; i < in.n; i++) {
        goodidx.insert(i);
    }
    out.ansn = 0;
    for (int i = 0; i < in.q; i++) {
        int l, r;
        if (in.qtype[i] == 1) {
            l = in.qr[i][0];
            r = in.qr[i][0] + 1;
        } else {
            l = in.qr[i][0];
            r = in.qr[i][1];
        }
        if (goodidx.find(r - 1) == goodidx.end()) {
            int u = *goodidx.lower_bound(r - 1);
            long long w = getval(0, 0, in.n, u);
            setval(0, 0, in.n, r - 1, w);
            badid[r - 1] = badid[u];
            goodidx.insert(r - 1);
        }
        if (l > 0 && goodidx.find(l - 1) == goodidx.end()) {
            int u = *goodidx.lower_bound(l - 1);
            long long w = getval(0, 0, in.n, u);
            setval(0, 0, in.n, l - 1, w);
            badid[l - 1] = badid[u];
            goodidx.insert(l - 1);
        }
        if (in.qtype[i] == 1) {
            long long w = getval(0, 0, in.n, l);
            int u = badid[l];
            out.ans[out.ansn++] = badvals[u] - w;
        } else if (in.qtype[i] == 2) {
            int u = 0;
            while (in.qr[i][2] > badvals[u]) {
                u++;
            }
            long long w = badvals[u] - in.qr[i][2];
            clearval(0, 0, in.n, l, r);
            setval(0, 0, in.n, r - 1, w);
            badid[r - 1] = u;
            std::set<int>::iterator itl = goodidx.lower_bound(l);
            std::set<int>::iterator itr = goodidx.lower_bound(r);
            goodidx.erase(itl, itr);
            goodidx.insert(r - 1);
        } else if (in.qtype[i] == 3) {
            while (true) {
                bool ok = true;
                addval(0, 0, in.n, l, r, -in.qr[i][2]);
                while (true) {
                    std::pair<long long, int> w = getmin(0, 0, in.n, l, r);
                    if (w.first > 0) {
                        break;
                    }
                    if (w.first == 0) {
                        ok = false;
                        break;
                    }
                    badid[w.second]++;
                    int u = badid[w.second];
                    setval(0, 0, in.n, w.second, badvals[u] - badvals[u - 1] + w.first);
                }
                if (ok) {
                    break;
                }
            }
        }
    }
}

void output()
{
    for (int i = 0; i < out.ansn; i++) {
        printf("%" LLFORMAT "d\n", out.ans[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("679E.in", "r", stdin);
    freopen("679E.out", "w", stdout);
#endif

    input();
    solve();
    output();

#ifndef ONLINE_JUDGE
    fclose(stdin); fclose(stdout);
#endif
    return 0;
}