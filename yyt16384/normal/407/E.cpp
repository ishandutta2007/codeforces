#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 200005;
const int MAXS = 530005;
const int INF = 0x3f3f3f3f;

struct InState {
    int n, k, d;
    int a[MAXN];
};

struct OutState {
    int ansl, ansr;
};

InState in;
OutState out;
int min[MAXS];
int flag[MAXS];

void input()
{
    scanf("%d%d%d", &in.n, &in.k, &in.d);
    for (int i = 0; i < in.n; i++) {
        scanf("%d", &in.a[i]);
    }
}

void build(int now, int l, int r)
{
    min[now] = 0;
    flag[now] = 0;
    if (l + 1 == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(now * 2 + 1, l, mid);
    build(now * 2 + 2, mid, r);
}

void add_one(int now, int w)
{
    min[now] += w;
    flag[now] += w;
}

void update_down(int now)
{
    if (flag[now]) {
        add_one(now * 2 + 1, flag[now]);
        add_one(now * 2 + 2, flag[now]);
        flag[now] = 0;
    }
}

void add(int now, int l, int r, int ql, int qr, int w)
{
    if (ql == l && qr == r) {
        add_one(now, w);
        return;
    }
    update_down(now);
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        add(now * 2 + 1, l, mid, ql, qr, w);
    } else if (ql >= mid) {
        add(now * 2 + 2, mid, r, ql, qr, w);
    } else {
        add(now * 2 + 1, l, mid, ql, mid, w);
        add(now * 2 + 2, mid, r, mid, qr, w);
    }
    min[now] = std::min(min[now * 2 + 1], min[now * 2 + 2]);
}

int findleftok(int now, int l, int r, int ql, int qr, int k)
{
    if (min[now] > k) {
        return INF;
    }
    if (l + 1 == r) {
        return l;
    }
    update_down(now);
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return findleftok(now * 2 + 1, l, mid, ql, qr, k);
    } else if (ql >= mid) {
        return findleftok(now * 2 + 2, mid, r, ql, qr, k);
    } else {
        int s = findleftok(now * 2 + 1, l, mid, ql, mid, k);
        if (s == INF) {
            s = findleftok(now * 2 + 2, mid, r, mid, qr, k);
        }
        return s;
    }
}

std::pair<int, int> getans(const int *a, int n)
{
    int ansl = 0;
    int ansr = 0;
    static int stkmin[MAXN][2];
    int stkminn = 0;
    static int stkmax[MAXN][2];
    int stkmaxn = 0;
    std::set<int> stvals;
    build(0, 0, n);
    for (int i = 0, l = 0; i < n; i++) {
        if (stvals.find(a[i]) != stvals.end()) {
            while (a[l] != a[i]) {
                stvals.erase(a[l]);
                l++;
            }
            l++;
        } else {
            stvals.insert(a[i]);
        }
        int prer;
        prer = i;
        while (stkminn && a[i] <= stkmin[stkminn - 1][0]) {
            add(0, 0, n, stkmin[stkminn - 1][1], prer, stkmin[stkminn - 1][0] - a[i]);
            prer = stkmin[stkminn - 1][1];
            stkminn--;
        }
        stkmin[stkminn][0] = a[i];
        stkmin[stkminn][1] = prer;
        stkminn++;
        prer = i;
        while (stkmaxn && a[i] >= stkmax[stkmaxn - 1][0]) {
            add(0, 0, n, stkmax[stkmaxn - 1][1], prer, a[i] - stkmax[stkmaxn - 1][0]);
            prer = stkmax[stkmaxn - 1][1];
            stkmaxn--;
        }
        stkmax[stkmaxn][0] = a[i];
        stkmax[stkmaxn][1] = prer;
        stkmaxn++;
        int nowl = findleftok(0, 0, n, l, i + 1, in.k);
        if (i - nowl > ansr - ansl) {
            ansl = nowl;
            ansr = i;
        }
        add(0, 0, n, 0, i + 1, -1);
    }
    return std::make_pair(ansl, ansr + 1);
}

void solve()
{
    if (in.d == 0) {
        int ansl = -1;
        int ansr = -1;
        for (int l = 0, r = 0; l < in.n; l = r) {
            while (r < in.n && in.a[r] == in.a[l]) {
                r++;
            }
            if (r - l > ansr - ansl) {
                ansl = l;
                ansr = r;
            }
        }
        out.ansl = ansl;
        out.ansr = ansr;
        return;
    }
    static int a[MAXN];
    static int c[MAXN];
    for (int i = 0; i < in.n; i++) {
        a[i] = in.a[i] / in.d;
        c[i] = in.a[i] % in.d;
        if (c[i] < 0) {
            a[i]--;
            c[i] += in.d;
        }
    }
    int ansl = -1;
    int ansr = -1;
    for (int l = 0, r = 0; l < in.n; l = r) {
        while (r < in.n && c[r] == c[l]) {
            r++;
        }
        std::pair<int, int> pr = getans(a + l, r - l);
        if (pr.second - pr.first > ansr - ansl) {
            ansl = pr.first + l;
            ansr = pr.second + l;
        }
    }
    out.ansl = ansl;
    out.ansr = ansr;
}

void output()
{
    printf("%d %d\n", out.ansl + 1, out.ansr);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("407E.in", "r", stdin);
    freopen("407E.out", "w", stdout);
#endif

    input();
    solve();
    output();

#ifndef ONLINE_JUDGE
    fclose(stdin); fclose(stdout);
#endif
    return 0;
}