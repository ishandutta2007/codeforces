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
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 26;
const int maxh = 2000000;

int a[maxn][3];

struct T
{
    int delta[2];
    int abs, id;

    T() {}

    T(int *c, int id): id(id)
    {
        abs = c[0];
        delta[0] = c[1] - c[0];
        delta[1] = c[2] - c[0];
    }

    bool operator<(const T&t)
    {
        if (delta[0] != t.delta[0])
            return delta[0] < t.delta[0];
        if (delta[1] != t.delta[1])
            return delta[1] < t.delta[1];
        if (abs != t.abs)
            return abs > t.abs;
        return id < t.id;
    }
};

char str[maxh][maxn / 2];
int ids;

vector<T> half;

vector<int> v;
int c[3];
void go(int k, int bound)
{
    if (k == bound)
    {
        half.emplace_back(c, ids);
        forn (i, k)
            str[ids][i] = v[i];
        ++ids;
        return;
    }
    c[0] += a[k][0];
    c[1] += a[k][1];
    c[2] += a[k][2];
    forn (i, 3)
    {
        v.push_back(i);
        c[i] -= a[k][i];
        go(k + 1, bound);
        v.pop_back();
        c[i] += a[k][i];
    }
    c[0] -= a[k][0];
    c[1] -= a[k][1];
    c[2] -= a[k][2];
}

int res = -INF;
vector<int> resstr;
int n;

void go2(int k, int bound)
{
    if (k == bound)
    {
        T t;
        t.id = -1, t.abs = INF;
        t.delta[0] = c[0] - c[1];
        t.delta[1] = c[0] - c[2];
        int pos = lower_bound(half.begin(), half.end(), t) - half.begin();
        if (pos >= sz(half) || half[pos].delta[0] != t.delta[0] || half[pos].delta[1] != t.delta[1])
            return;
        if (res >= c[0] + half[pos].abs)
            return;
        res = c[0] + half[pos].abs;
        int id = half[pos].id;
        forn (i, n / 2)
            resstr[i] = str[id][i];
        forab (i, n / 2, n)
            resstr[i] = v[i - n / 2];
        return;
    }
    c[0] += a[k][0];
    c[1] += a[k][1];
    c[2] += a[k][2];
    forn (i, 3)
    {
        v.push_back(i);
        c[i] -= a[k][i];
        go2(k + 1, bound);
        v.pop_back();
        c[i] += a[k][i];
    }
    c[0] -= a[k][0];
    c[1] -= a[k][1];
    c[2] -= a[k][2];
}

int solve()
{
    cin >> n;
    forn (i, n)
        forn (j, 3)
            cin >> a[i][j];
    go(0, n / 2);
    sort(half.begin(), half.end());
    resstr.resize(n);
    go2(n / 2, n);
    string S[] = {"MW", "LW", "LM"};
    if (res == -INF)
    {
        cout << "Impossible\n";
        return 0;
    }
//    cerr << res << '\n';
    forn (i, n)
        cout << S[resstr[i]] << '\n';
    return 0;
}