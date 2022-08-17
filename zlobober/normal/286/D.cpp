#include <cstdio>
#include <cassert>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long llong;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif
const int N = 400500;

int bc = 0;

struct blade
{
    int l, r, t, i;
    inline blade(int _l, int _r, int _t, int _i)
    {
        l = _l, r = _r, t = _t, i = _i;
    }
    inline blade shrink(int l, int r) const
    {
        assert(this->l <= l && r <= this->r);
        return blade(l, r, t, bc++);
    }
    friend bool operator <(const blade& a, const blade& b)
    {
        if (a.t != b.t)
            return a.t < b.t;
        return a.i < b.i;
    }

    blade(){}
};

vector<blade> B, R;

struct ev
{
    int x, t, i;
    ev(int _x, int _t, int _i)
    {
        x = _x, t = _t, i = _i;
    }
    friend bool operator <(const ev& a, const ev& b)
    {
        return a.x < b.x;
    }
};

const llong INF = 1e9 + 42;

vector<ev> E;

struct ev2
{
    int x, t;
    friend bool operator <(const ev2& a, const ev2& b)
    {
        return a.x < b.x;
    }
    ev2(int _x, int _t)
    {
        x = _x, t = _t;
    }
};

vector<ev2> E2;
vector<pair<llong, llong> > L;

int r = 0;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int l, r, t;
        scanf("%d %d %d", &l, &r, &t);
        r;
        B.push_back(blade(l, r, t, i));
    }
    for (int i = 0; i < m; i++)
    {
        E.push_back(ev(B[i].l, 1, i));
        E.push_back(ev(B[i].r, -1, i));
    }
    sort(E.begin(), E.end());
    set<blade> S;
    llong p = -INF;
    for (int i = 0; i < E.size(); i++)
    {
        if (p != E[i].x)
        {
            if (!S.empty())
                r++, R.push_back(S.begin()->shrink(p, E[i].x));
        }
        if (E[i].t == 1)
            S.insert(B[E[i].i]);
        else
            assert(S.erase(B[E[i].i]));
        assert(r < N - 42);
        p = E[i].x;
    }
    assert(r == R.size());
    eprintf("produced %d blades\n", r);
    for (int i = 0; i < r; i++)
        eprintf("%d %d %d\n", R[i].l, R[i].r, R[i].t);
    for (int i = 0; i < r; i++)
    {
        E2.push_back(ev2(R[i].t - R[i].r, 1));
        E2.push_back(ev2(R[i].t - R[i].l, -1));
    }
    sort(E2.begin(), E2.end());
    llong v = 0;
    llong k = 0;
    p = -INF;
    L.push_back(make_pair(-2 * INF, 0));
    for (int i = 0; i < E2.size(); i++)
    {
        v += (E2[i].x - p) * k;
        L.push_back(make_pair(E2[i].x, v));
        k += E2[i].t;
        p = E2[i].x;
    }
    L.push_back(make_pair(2 * INF, v));
    L.resize(unique(L.begin(), L.end()) - L.begin());

    for (int i = 0; i < L.size(); i++)
        eprintf("(%d, %d) ", L[i].first, L[i].second);
    eprintf("\n");
    for (int i = 0; i + 1 < L.size(); i++)
        assert(L[i].first < L[i + 1].first);

    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        vector<pair<llong, llong> >::iterator it = lower_bound(L.begin(), L.end(), make_pair((llong)t, -1LL)), it2;
        it2 = it--;
        llong x1 = it->first;
        llong y1 = it->second;
        llong x2 = it2->first;
        llong y2 = it2->second;
        assert(x1 != x2);
        llong ans = ((llong)y1 * (x2 - t) + (llong)y2 * (t - x1)) / (x2 - x1);
        printf("%d\n", (int)ans);
    }
}