#include <cstdio>
#include <set>
#include <memory.h>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

//
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 1 << 18;

const double eps = 1e-9;

struct vt
{
    double x, y;
    vt(){}
    vt(double _x, double _y)
    {
        x = _x, y = _y;
    }
    friend vt operator -(vt a, vt b)
    {
        return vt(a.x - b.x, a.y - b.y);
    }
    friend vt operator +(vt a, vt b) {
        return vt(a.x + b.x, a.y + b.y);
    }
    friend double operator ^(vt a, vt b)
    {
        return a.x * b.y - b.x * a.y;
    }
    friend double operator *(vt a, vt b) {
        return a.x * b.x + a.y * b.y;
    }
    friend vt operator ~(vt a)
    {
        return vt(a.y, -a.x);
    }
    friend vt operator /(vt a, double k)
    {
        return vt(a.x / k, a.y / k);
    }
    char* to_string()
    {
        char* buf = new char[50];
        sprintf(buf, "(%.6lg, %.6lg)", x, y);
        return buf;
    }
    double abs() {
        return hypot(x, y);
    }
    double l1abs() {
        return fabs(x) + fabs(y);
    }
    friend vt operator *(vt a, double k) {
        return vt(a.x * k, a.y * k);
    }
};

typedef pair<vt, vt> seg;

int m;

struct CheckNonIntersection
{

    typedef vector<seg > SV;

    SV S;

    char sign(double x)
    {
        return (x > eps) - (x < -eps);
    }

    struct cmp_by_x
    {
        vector<pair<vt, vt> >& S;
        cmp_by_x(vector<pair<vt, vt> > &_S) : S(_S) {}
        inline bool operator()(int a, int b)
        {
            double u = (a >= 0) ? S[a].first.x : S[~a].second.x;
            double v = (b >= 0) ? S[b].first.x : S[~b].second.x;
            if (fabs(u - v) > eps)
                return u < v;
            else
                return (a >= 0) > (b >= 0);
        }
    };

    struct cmp_by_y
    {
        double& x;
        vector<pair<vt, vt> >& S;
        cmp_by_y(double& _x, vector<pair<vt, vt> >& _S) : x(_x), S(_S)
        {
        }
        double get_y(seg s, double x) {
            if (fabs(s.second.x - s.first.x) < eps) {
                return s.first.y;
            } else {
                return ((s.second.x - x) * s.first.y + (x - s.first.x) * s.second.y) / (s.second.x - s.first.x);
            }
        }
        inline bool operator ()(int i, int j)
        {
            double iy = get_y(S[i], x);
            double jy = get_y(S[j], x);
            return iy < jy;
        }
    };

    bool in_seg(vt a, vt b, vt x) {
        return fabs((a - x) ^ (b - a)) / (b - a).abs() < eps && ((a - x) * (b - x) < eps);
    }

    inline bool check_inter(int i, int j, double& x)
    {
        vt a = S[i].first;
        vt b = S[i].second;
        vt c = S[j].first;
        vt d = S[j].second;
        bool deg1 = (b - a).l1abs() < eps;
        bool deg2 = (d - c).l1abs() < eps;
        if (deg1 && deg2) {
            if ((a - c).l1abs() < eps) {
                x = a.x;
                return true;
            }
            return false;
        } else {
            if (deg2)
                swap(a, c), swap(b, d), swap(deg1, deg2);
            if (deg1) {
                if (in_seg(c, d, a)) {
                    x = a.x;
                    return true;
                }
                return false;
            } else {
                double det = ((b - a) ^ (d - c));
                if (fabs(det) < eps) {
                    x = 1e100;
                    if (in_seg(a, b, c)) {
                        x = min(x, c.x);
                    }
                    if (in_seg(a, b, d)) {
                        x = min(x, d.x);
                    }
                    if (in_seg(c, d, a)) {
                        x = min(x, a.x);
                    }
                    if (in_seg(c, d, b)) {
                        x = min(x, b.x);
                    }
                    if (x > 1e50) {
                        return false;
                    } else {
                        return true;
                    }
                }
                vt v = (a * ((b - c) ^ (d - c)) + b * ((d - c) ^ (a - c))) / (det);
                x = v.x;
                return in_seg(a, b, v) && in_seg(c, d, v);
            }
        }
    }

    double xcoord = 1e100;

    CheckNonIntersection(vector<pair<vt, vt> > _S)
    {
        S = _S;
        double x;
        multiset<int, cmp_by_y> A(cmp_by_y(x, S));
        vector<int> ev(2 * S.size());
        for (int i = 0; i < (int)S.size(); i++)
            ev[2 * i] = i, ev[2 * i + 1] = ~i;
        sort(ev.begin(), ev.end(), cmp_by_x(S));
        vector<multiset<int, cmp_by_y>::iterator> pos(S.size(), A.end());
        for (int i = 0; i + 1 < (int)ev.size(); i++)
        {
            int v = ev[i], w = ev[i + 1];
            double ax = (v >= 0) ? S[v].first.x : S[~v].second.x;
            double bx = (w >= 0) ? S[w].first.x : S[~w].second.x;
            if (ax > xcoord - eps)
                return;
            bx = min(bx, xcoord);
            x = (10 * ax + bx) / 11;
            double nxcoord;
            if (v >= 0)
            {
                pos[v] = A.insert(v);
                multiset<int, cmp_by_y>::iterator it = pos[v];
                if (it != A.begin()) {
                    if (check_inter(v, *(--it), nxcoord)) {
                        xcoord = min(xcoord, nxcoord);
                    }
                    it = pos[v];
                }
                if ((++it) != A.end()) {
                    if (check_inter(v, *it, nxcoord)) {
                        xcoord = min(xcoord, nxcoord);
                    }
                }
            }
            else
            {
                multiset<int, cmp_by_y>::iterator itl = pos[~v], itr = pos[~v];
                if (itl != A.begin() && (++itr) != A.end()) {
                    if (check_inter(*(--itl), *itr, nxcoord)) {
                        xcoord = min(xcoord, nxcoord);
                    }
                }
                A.erase(pos[~v]);
                pos[~v] = A.end();
            }
        }
    }
};


vector<int> E[N];
int sz[N];

int tin[N], tout[N];
int curt = 0;
int par[N];
int D[N];

int hlc[N];
int hlpos[N];
int ctop[N];
int cbot[N];
int clen[N];
int ver[N];

double myround(double x) {
    /*x = x * 1e9;
    x = round(x);
    x = x / 1e9;*/
    return x;
}

struct line {
    int c = -1;
    vector<seg> segments;
    set<int> indices;
    void add_seg(seg s, int i) {
        if (indices.count(i)) {
            //eprintf("Warning!\n");
            return;
        }
        indices.insert(i);
        s.first.x = myround(s.first.x);
        s.second.x = myround(s.second.x);
        if (s.first.x > s.second.x + eps / 2)
            swap(s.first, s.second);
        segments.push_back(s);
    }

    void debug() {
        #ifdef DEB
        eprintf("c = %d, cbot = %d, ctop = %d, clen = %d\n", c, cbot[c], ctop[c], clen[c]);
        eprintf("indices:\n");
        for (int i : indices) {
            eprintf("%d ", i);
        }
        eprintf("\n");
        eprintf("segs:\n");
        for (auto seg : segments) {
            eprintf("%.4lg %.4lg %.4lg %.4lg\n", seg.first.x, seg.first.y, seg.second.x, seg.second.y);
        }
        #endif
    }

    double solve() {
        debug();
        double mnx = 1e100;
        CheckNonIntersection checker(segments);
        if (checker.xcoord < 1e50) {
            mnx = checker.xcoord;
            //eprintf("Has intersection at %.4g\n", mnx);
        } else {
            //eprintf("Has no intersections\n");
        }
        //eprintf("\n");

        return mnx;
    }
};
line L[N];

const int lgN = 17;

int up[lgN][N];

void DFS1(int x, int p = -1) {
    if (p != -1) {
        E[x].erase(find(E[x].begin(), E[x].end(), p));
        D[x] = D[p] + 1;
        par[x] = p;
        up[0][x] = p;
    } else {
        par[x] = -1;
        up[0][x] = x;
    }
    for (int d = 1; d < lgN; d++)
        up[d][x] = up[d - 1][up[d - 1][x]];
    sz[x] = 1;
    tin[x] = curt++;
    for (int y : E[x]) {
        DFS1(y, x);
        sz[x] += sz[y];
    }
    tout[x] = curt;
}

int curc = 0;

void buildPath(int x, int y, int c) {
    ctop[c] = y;
    cbot[c] = x;
    clen[c] = D[x] - D[y];
    L[c].c = c;
    for (int v = x; v != y; v = par[v]) {
        hlpos[v] = -D[v] + D[x];
    }
}

void DFS2(int x, int c, int from) {
    int ind = -1;
    hlc[x] = c;
    for (int y : E[x]) {
        if (2 * sz[y] >= sz[x]) {
            ind = y;
            DFS2(y, c, from);
        } else {
            DFS2(y, curc++, x);
        }
    }
    if (ind == -1) {
        buildPath(x, from, c);
    }
}

int lca(int u, int v) {
    if (D[u] < D[v])
        swap(u, v);
    for (int d = lgN - 1; d >= 0; d--) {
        if (D[u] - (1 << d) >= D[v])
            u = up[d][u];
    }
    if (u == v)
        return u;
    for (int d = lgN - 1; d >= 0; d--) {
        if (up[d][u] != up[d][v])
            u = up[d][u], v = up[d][v];
    }
    return up[0][u];
}

// vertical
void addSeg(double speed, int u, int v, double t0, int i) {
    double curt = t0;
    while (true) {
        if (u == v)
            break;
        int c = hlc[u];
        double y1 = hlpos[u];
        double y2 = (hlc[u] == hlc[v]) ? hlpos[v] : clen[c];
        double t1 = curt;
        double t2 = t1 + (y2 - y1) / speed;
        curt = t2;
        L[c].add_seg(seg(vt(t1, y1), vt(t2, y2)), i);
        if (hlc[u] == hlc[v])
            break;
        u = ctop[c];
    }
}

int main() {
    int n;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    n++;
    E[0].push_back(1);
    E[1].push_back(0);
    DFS1(0, -1);
    DFS2(0, curc++, 0);
    for (int i = 0; i < m; i++) {
        int t, c, v, u;
        scanf("%d %d %d %d", &t, &c, &v, &u);
        double speed = c;
        int l = lca(u, v);
        double len = D[v] - D[l] + D[u] - D[l];
        addSeg(speed, v, l, t, i);
        addSeg(-speed, u, l, t + len / speed, i);
        if (true) {
            int cl = hlc[l];
            double tl = t + (D[v] - D[l]) / speed;
            L[cl].add_seg(seg(vt(tl, -D[l] + D[cbot[cl]]), vt(tl, -D[l] + D[cbot[cl]])), i);
        }
    }
    double ans = 1e100;
    for (int i = 0; i < curc; i++) {
        double mn = L[i].solve();
        ans = min(ans, mn);
    }
    if (ans < 1e50) {
        printf("%.10lf\n", ans);
    } else {
        printf("-1\n");
    }
}