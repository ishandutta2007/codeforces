#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
#define all(x) x.begin(), x.end()

const ld eps = 1e-9;
bool ze(ld a) { return fabsl(a) < eps; }
bool eq(ld a, ld b) { return ze(a - b); }
ld sqr(ld x) { return x * x; }
ld Sqrt(ld x) { return sqrtl(max<ld>(0, x)); }

struct pt {
    ld x, y;

    pt operator+(const pt &p) const { return pt{x + p.x, y + p.y}; }
    pt operator-(const pt &p) const { return pt{x - p.x, y - p.y}; }
    ld operator*(const pt &p) const { return x * p.x + y * p.y; }
    ld operator%(const pt &p) const { return x * p.y - y * p.x; }
    pt operator*(const ld &a) const { return pt{x * a, y * a}; }
    bool operator==(const pt &p) const { return eq(x, p.x) && eq(y, p.y); }

    bool up() const { return ze(y) ? x > 0 : y > 0; }

    bool operator<(const pt &p) const {
        if (!eq(x, p.x))
            return x < p.x;
        if (!eq(y, p.y))
            return y < p.y;
        return false;
    }

    pt rot() { return pt{-y, x}; }
    pt rotCw(pt e) { return pt{e * *this, e % *this}; }
    ld abs() const { return hypotl(x, y); }
    ld abs2() const { return x * x + y * y; }
};

istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
ostream &operator<<(ostream &out, const pt &p) { return out << p.x << ' ' << p.y; }

bool cmpAngle(const pt &a, const pt &b) {
    bool au = a.up(), bu = b.up();
    if (au != bu)
        return au;
    return a % b > eps;
}

struct line {
    pt v;
    ld c; // v * p = c

    //check: p1 != p2
    line(pt p1, pt p2) {
        v = (p2 - p1).rot();
        v = v * (1. / v.abs());
        c = v * p1;
    }

    // Convert from ax + by + c = 0

    //check: a^2+b^2 > 0
    line(ld a, ld b, ld _c): v(pt{a, b}), c(-_c) {
        ld d = v.abs();
        v = v * (1. / d);
        c /= d;
    }

    //check: v.abs() == 1
    ld signedDist(pt p) {
        return v * p - c;
    }
};

bool cmpLine(const line &a, const line &b) {
    bool au = a.v.up(), bu = b.v.up();
    if (au != bu)
        return au;
    ld prod = a.v % b.v;
    if (!ze(prod))
        return prod > 0;
    // the strongest constraint is first for correct unique
    return a.c > b.c;
}

bool eqLine(const line &a, const line &b) {
    return a.v.up() == b.v.up() && ze(a.v % b.v);
}

ld det3x3(line a, line b, line c) {
    return a.c * (b.v % c.v)
         + b.c * (c.v % a.v)
         + c.c * (a.v % b.v);
}

pt linesIntersection(line l1, line l2) {
    ld d = l1.v.x * l2.v.y - l1.v.y * l2.v.x;
    if (ze(d))
        return pt{1e18, 1e18};
    ld dx = l1.c * l2.v.y - l1.v.y * l2.c;
    ld dy = l1.v.x * l2.c - l1.c * l2.v.x;
    return pt{dx / d, dy / d};
}

vector<pt> halfplanesIntersection(vector<line> l) {
    sort(all(l), cmpLine); //the strongest constraint is first
    l.erase(unique(all(l), eqLine), l.end());
    int n = sz(l);
    vector<int> st;
    forn (iter, 2)
        forn (i, n) {
            while (sz(st) > 1) {
                int j = st.back(), k = *next(st.rbegin());
                if (l[k].v % l[i].v <= eps || 
                        det3x3(l[k], l[j], l[i]) <= eps)
                    break;
                st.pop_back();
            }
            st.push_back(i);
        }

    vector<int> pos(n, -1);
    bool ok = false;
    forn (i, sz(st)) {
        int id = st[i];
        if (pos[id] != -1) {
            st = vector<int>(st.begin() + pos[id], st.begin() + i);
            ok = true;
            break;
        } else
            pos[id] = i;
    }
    if (!ok)
        return {};

    vector<pt> res;
    pt M{0, 0};
    int k = sz(st);
    forn (i, k) {
        line l1 = l[st[i]], l2 = l[st[(i + 1) % k]];
        res.push_back(linesIntersection(l1, l2));
        M = M + res.back();
    }
    M = M * (1. / k);
    for (int id: st)
        if (l[id].signedDist(M) < -eps)
            return {};
    return res;
}

const int maxn = 400200;
pt p[maxn];

struct Event {
    pt p, v;

    bool operator<(const Event &e) const {
        return cmpAngle(p, e.p);
    }
};

void solve() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    pt pivot{ld(x), ld(y)};
    --n;
    vector<Event> ev;
    forn (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = pt{ld(x), ld(y)} - pivot;
        ev.push_back(Event{p[i], p[i]});
        ev.push_back(Event{p[i] * -1, p[i]});
    }
    sort(all(ev));

    vector<line> hp;
    const ld B = 1e6;
    pivot = pivot * -1;
    pt box[4] = {pivot + pt{B, B}, pivot + pt{-B, B}, pivot + pt{-B, -B}, pivot + pt{B, -B}};
    forn (i, 4)
        hp.push_back(line(box[i], box[(i+1)%4]));
    forn (i, sz(ev)) {
        pt A = ev[i].v, B = ev[(i+1)%sz(ev)].v;
        if (ze(A % B)) {
            cout << 0 << '\n';
            return;
        }
        line l(A, B);
        if (l.signedDist(pt{0, 0}) < 0)
            l = line(B, A);
        hp.push_back(l);
    }
    auto v = halfplanesIntersection(hp);

    ld s = 0;
    forn (i, sz(v))
        s += v[i] % v[(i+1)%sz(v)];
    s /= 2;

    cout << s << '\n';
}

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    cout << fixed;
    cout.precision(10);
    int tn;
    scanf("%d", &tn);
    forn (i, tn) {
        solve();
    }
}