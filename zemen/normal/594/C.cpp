#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

#define y1 aasdf

const int maxn = 100100;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];

struct pt
{
    int x, y, id;

    pt() {}
    pt(int x, int y, int id): x(x), y(y), id(id) {}
};

pt px[maxn], py[maxn];

bool cmpx(pt a, pt b)
{
    return a.x < b.x;
}

bool cmpy(pt a, pt b)
{
    return a.y < b.y;
}

ll calc(int xl, int xr)
{
    return max(1, (xr - xl + 1) / 2);
}

int solve()
{
    int n, k;
    cin >> n >> k;
    forn (i, n)
    {
        scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
        px[i] = py[i] = pt(x1[i] + x2[i], y1[i] + y2[i], i);
    }
    sort(px, px + n, cmpx);
    sort(py, py + n, cmpy);
    const int bd = min(n, k + 3);
    ll res = INFL;
    forn (minx, k + 1)
        forab (maxx, n - k - 1, n)
            forn (miny, k + 1)
                forab (maxy, n - k - 1, n)
                {
                    vector<int> drop;
                    int xl = px[minx].x;
                    int yl = py[miny].y;
                    int xr = px[maxx].x;
                    int yr = py[maxy].y;
                    forn (i, bd)
                        if (px[i].x < xl)
                            drop.push_back(px[i].id);
                    forn (i, bd)
                        if (py[i].y < yl)
                            drop.push_back(py[i].id);
                    forab (i, n - bd, n)
                        if (px[i].x > xr)
                            drop.push_back(px[i].id);
                    forab (i, n - bd, n)
                        if (py[i].y > yr)
                            drop.push_back(py[i].id);
                    sort(drop.begin(), drop.end());
                    if (unique(drop.begin(), drop.end()) - drop.begin() > k)
                        continue;
                    res = min(res, calc(xl, xr) * calc(yl, yr));
                }
    cout << res << '\n';
    return 0;
}