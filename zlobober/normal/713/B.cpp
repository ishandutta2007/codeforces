#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <functional>
using namespace std;

struct rect {
    int x1, y1, x2, y2;
    rect(int _x1, int _y1, int _x2, int _y2) {
        x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
    }
    rect() { x1 = y1 = x2 = y2 = 0; }
    friend bool operator <(rect a, rect b) {
        return make_tuple(a.x1, a.y1, a.x2, a.y2) < make_tuple(b.x1, b.y1, b.x2, b.y2);
    }
    friend bool operator ==(rect a, rect b) {
        return !(a < b) && !(b < a);
    }
};

int n;

int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;

bool in(int a, int b, int c, int d) {
    return a <= b && c <= d;
}

int nq = 0;

int ask(int x1, int y1, int x2, int y2) {
    if (x2 < x1 || y2 < y1)
        return 0;
    nq++;
    assert(1 <= x1 && x2 <= n && 1 <= y1 && y2 <= n);
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    /*int ans = 0;
    ans += in(x1, ax1, ax2, x2) && in(y1, ay1, ay2, y2);
    ans += in(x1, bx1, bx2, x2) && in(y1, by1, by2, y2);*/

    return ans;
}

int ask(rect r) {
    return ask(r.x1, r.y1, r.x2, r.y2);
}

pair<int, int> bs(function<rect(int)> build) {
    int a, b;
    {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            auto b = build(m);
            if (ask(b) == 2)
                r = m;
            else
                l = m;
        }
        a = r;
    }
    {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            auto b = build(m);
            if (ask(b) >= 1)
                r = m;
            else
                l = m;
        }
        b = r;
    }
    return make_pair(a, b);
}

int main() {
    scanf("%d", &n);

    /*while (true) {
        ax1 = rand() % n + 1;
        ay1 = rand() % n + 1;
        ax2 = rand() % n + 1;
        ay2 = rand() % n + 1;
        bx1 = rand() % n + 1;
        by1 = rand() % n + 1;
        bx2 = rand() % n + 1;
        by2 = rand() % n + 1;
        if (ax1 > ax2)
            swap(ax1, ax2);
        if (bx1 > bx2)
            swap(bx1, bx2);
        if (ay1 > ay2)
            swap(ay1, ay2);
        if (by1 > by2)
            swap(by1, by2);
        bool good = ax2 < bx1 || ay2 < by1 || bx2 < ax1 || by2 < ay1;
        if (good)
            break;
    }*/

    fprintf(stderr, "real = %d %d %d %d %d %d %d %d\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    int r[2], l[2], u[2], d[2];

    tie(r[0], r[1]) = bs([](int x) { return rect(1, 1, x, n); });
    tie(u[0], u[1]) = bs([](int y) { return rect(1, 1, n, y); });
    tie(l[0], l[1]) = bs([](int x) { return rect(n + 1 - x, 1, n, n); });
    tie(d[0], d[1]) = bs([](int y) { return rect(1, n + 1 - y, n, n); });
    l[0] = n + 1 - l[0];
    l[1] = n + 1 - l[1];
    d[0] = n + 1 - d[0];
    d[1] = n + 1 - d[1];
    vector<rect> rs;
    for (int x1 : l) {
        for (int x2 : r) {
            for (int y1 : d) {
                for (int y2 : u) {
                    int a = ask(x1, y1, x2, y2);
                    if (a != 1)
                        continue;
                    int perm[] = {0, 1, 2, 3};
                    bool bad = false;
                    random_shuffle(perm, perm + 4);
                    for (int p : perm) {
                        int v;
                        if (p == 0) v = ask(x1 + 1, y1, x2, y2);
                        if (p == 1) v = ask(x1, y1 + 1, x2, y2);
                        if (p == 2) v = ask(x1, y1, x2 - 1, y2);
                        if (p == 3) v = ask(x1, y1, x2, y2 - 1);
                        if (v == 1) {
                            bad = true;
                            break;
                        }
                    };
                    if (bad)
                        continue;
                    rs.emplace_back(x1, y1, x2, y2);
                }
            }
        }
    }
    sort(rs.begin(), rs.end());
    rs.resize(unique(rs.begin(), rs.end()) - rs.begin());
    assert((int)rs.size() == 2);
    printf("! %d %d %d %d %d %d %d %d\n", rs[0].x1, rs[0].y1, rs[0].x2, rs[0].y2, rs[1].x1, rs[1].y1, rs[1].x2, rs[1].y2);
    fflush(stdout);
    fprintf(stderr, "nq = %d\n", nq);
    assert(nq <= 200);
    return 0;
}