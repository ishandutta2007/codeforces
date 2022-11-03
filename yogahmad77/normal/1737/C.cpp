#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a, b) memset(a, b, sizeof a);
#define ALL(x) x.begin(), x.end()

template <typename T>
void cetak(T t)
{
    cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v)
{
    cout << t;
    if (sizeof...(v))
        cout << ", ";
    cetak(v...);
}

#define debug(x...)               \
    cout << '(' << #x << ") = ("; \
    cetak(x)
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define pii pair<int, int>
typedef int (*func)(int, int);

const int mx = 2e5 + 10;

int pojok(pii a, pii b, pii c, int n)
{
    vector<pii> sa, du, ti, em;
    sa.push_back(make_pair(1, 1));
    sa.push_back(make_pair(1, 2));
    sa.push_back(make_pair(2, 1));
    int aa = 0;
    int bb = 0;
    int cc = 0;
    for (auto j : sa)
    {
        if (j == a)
            aa = 1;
        if (j == b)
            bb = 1;
        if (j == c)
            cc = 1;
    }
    // debug(aa, bb, cc);
    if (aa && bb && cc)
        return 1;

    du.push_back(make_pair(1, n));
    du.push_back(make_pair(1, n - 1));
    du.push_back(make_pair(2, n));
    aa = 0;
    bb = 0;
    cc = 0;
    for (auto j : du)
    {
        if (j == a)
            aa = 1;
        if (j == b)
            bb = 1;
        if (j == c)
            cc = 1;
    }
    if (aa && bb && cc)
        return 2;

    ti.push_back(make_pair(n, 1));
    ti.push_back(make_pair(n - 1, 1));
    ti.push_back(make_pair(n, 2));
    aa = 0;
    bb = 0;
    cc = 0;
    for (auto j : ti)
    {
        if (j == a)
            aa = 1;
        if (j == b)
            bb = 1;
        if (j == c)
            cc = 1;
    }
    if (aa && bb && cc)
        return 3;

    em.push_back(make_pair(n, n));
    em.push_back(make_pair(n - 1, n));
    em.push_back(make_pair(n, n - 1));
    aa = 0;
    bb = 0;
    cc = 0;
    for (auto j : em)
    {
        if (j == a)
            aa = 1;
        if (j == b)
            bb = 1;
        if (j == c)
            cc = 1;
    }
    if (aa && bb && cc)
        return 4;
    return 0;
}

void solve(int tc)
{
    int n;
    cin >> n;
    pii a, b, c, x;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> x.first >> x.second;
    if (a == x || b == x || c == x)
    {
        cout << "YES\n";
        return;
    }
    // vector<vector<pii>> ve;
    // vector<pii> sa, du, ti, em;
    // sa.push_back(make_pair(1, 1));
    // sa.push_back(make_pair(1, 2));
    // sa.push_back(make_pair(2, 1));

    // du.push_back(make_pair(1, n));
    // du.push_back(make_pair(1, n - 1));
    // du.push_back(make_pair(2, n));

    // ti.push_back(make_pair(n, 1));
    // ti.push_back(make_pair(n - 1, 1));
    // ti.push_back(make_pair(n, 2));

    // em.push_back(make_pair(n, n));
    // em.push_back(make_pair(n - 1, n));
    // em.push_back(make_pair(n, n - 1));

    // ve.push_back(sa);
    // ve.push_back(du);
    // ve.push_back(ti);
    // ve.push_back(em);

    int xx = pojok(a, b, c, n);
    // debug(xx);
    if (xx == 0)
    {
        int ge = 0, ga = 0;
        if ((a.first + a.second) % 2 == 0)
            ge += 1;
        if ((b.first + b.second) % 2 == 0)
            ge += 1;
        if ((c.first + c.second) % 2 == 0)
            ge += 1;
        ga = 3 - ge;
        if (ge == 2 && (x.first + x.second) % 2 == 0)
        {
            cout << "YES\n";
            return;
        }
        if (ga == 2 && (x.first + x.second) % 2 == 1)
        {
            cout << "YES\n";
            return;
        }
        if (ga == 1)
        {
            if ((b.first + b.second) % 2 == 1)
                swap(b, a);
            if ((c.first + c.second) % 2 == 1)
                swap(c, a);
        }
        else
        {
            if ((b.first + b.second) % 2 == 0)
                swap(b, a);
            if ((c.first + c.second) % 2 == 0)
                swap(c, a);
        }
        if (a.first % 2 == x.first % 2 && a.second % 2 == x.second % 2)
        {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    if (xx == 1)
    {
        // debug(xx);
        if (x.first == 1 || x.second == 1)
        {
            cout << "YES\n";
            return;
        }
    }
    if (xx == 2)
    {
        if (x.first == 1 || x.second == n)
        {
            cout << "YES\n";
            return;
        }
    }
    if (xx == 3)
    {
        if (x.first == n || x.second == 1)
        {
            cout << "YES\n";
            return;
        }
    }
    if (xx == 4)
    {
        if (x.first == n || x.second == n)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}