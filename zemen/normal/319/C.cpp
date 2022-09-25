#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;

#ifdef LOCAL
#define gassert assert
#else
void gassert(bool) {}
#endif

const ld eps = 1e-12;

bool gt(ld a, ld b) {
    return a - b > eps;
}

bool ge(ld a, ld b) {
    return a - b > -eps;
}

bool le(ld a, ld b) {
    return b - a > -eps;
}

struct pt {
    ld x, y;

    pt operator+(const pt &p) const { return pt{x + p.x, y + p.y}; } 
    pt operator-(const pt &p) const { return pt{x - p.x, y - p.y}; }
    ld operator*(const pt &p) const { return x * p.x + y * p.y; }
    ld operator%(const pt &p) const { return ld(x) * p.y - ld(y) * p.x; }

    bool operator<(const pt &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator==(const pt &p) const {
        return x == p.x && y == p.y;
    }
    bool right() const { return pt{0, 0} < *this; }
    pt rot() { return pt{-y, x}; }
};

bool cmpAngle(const pt &a, const pt &b) {
    bool ar = a.right(), br = b.right();
    if (ar ^ br)
        return ar;
    return gt(a % b, 0);
}

struct Hull {
    vector<pt> top, bot;

    void append(pt p) {
        while (bot.size() > 1 && ge((p - bot.back()) % (bot.back() - *next(bot.rbegin())), 0))
            bot.pop_back();
        bot.push_back(p);
        while (top.size() > 1 && le((p - top.back()) % (top.back() - *next(top.rbegin())), 0))
            top.pop_back();
        top.push_back(p);
    }

    void build(vector<pt> h) {
        sort(h.begin(), h.end());
        h.erase(unique(h.begin(), h.end()), h.end());
        top.clear(), bot.clear();
        for (pt p: h)
            append(p);
    }

    pt kth(int k) {
        if (k < sz(bot))
            return bot[k];
        else
            return top[sz(top) - (k - sz(bot)) - 2];
    }

    pt mostDistant(pt dir) {
        if (bot.empty()) {
            //empty hull
            assert(false);
        }
        if (bot.size() == 1)
            return bot.back();
        dir = dir.rot().rot().rot();
        int n = sz(top) + sz(bot) - 2;
        int L = -1, R = n;
        while (L + 1 < R) {
            int C = (L + R) / 2;
            pt v = kth((C + 1) % n) - kth(C);
            if (cmpAngle(dir, v)) //finds upper bound
                R = C;
            else
                L = C;
        }
        return kth(R % n);
    }

    ld getMin(pt dir) {
        return mostDistant(dir) * dir;
    }
};

const int maxn = 100100;
int a[maxn];
int b[maxn];
Hull h;

int main() {
#ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
#endif
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forn (i, n)
        cin >> b[i];
    h.append(pt{ld(-b[0]), 0});
    ld ans = 0;
    forn (i, n) {
        if (i == 0)
            continue;
        pt cur{ld(-a[i]), 1};
        ld val = h.getMin(cur);
        if (i == n - 1)
            ans = val;
        h.append(pt{ld(-b[i]), val});
    }
    cout << ll(roundl(ans)) << '\n';
}