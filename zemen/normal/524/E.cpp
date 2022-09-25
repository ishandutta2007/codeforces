#define x1 hui
#define y1 huiu
#include <bits/stdc++.h>
#undef x1
#undef y1

using namespace std;

#define sz(x) ((int) (x).size())

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
    freopen("e.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int cx[200001];
int cy[200001];

int x1[200001];
int x2[200001];
int y1[200001];
int y2[200001];
bool bad[200001];

int k, q;

const int base = (1 << 17);
int t[base * 2];

vector <int> rect[200001];
vector <int> pt[200001];

void put(int v, int val)
{
    v += base;
    t[v] = val;
    while (v > 1)
    {
        v /= 2;
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int get(int l, int r, int v = 1, int cl = 0, int cr = base)
{
    if (l <= cl && cr <= r)
        return t[v];
    if (r <= cl || cr <= l)
        return INF;
    int cc = (cl + cr) / 2;
    return min(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

void check()
{
    for (int i = 0; i < k; ++i)
        pt[cx[i]].push_back(i);
    for (int i = 0; i < q; ++i)
        rect[x2[i]].push_back(i);
    for (int x = 0; x < 200000; ++x)
    {
        for (auto p: pt[x])
            put(cy[p], cx[p]);
        for (auto r: rect[x])
        {
            int res = get(y1[r], y2[r] + 1);
            if (res >= x1[r])
                bad[r] = true;
        }
    }
}

int solve()
{
    int n, m;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; ++i)
        scanf("%d%d", cx + i, cy + i);
    for (int i = 0; i < q; ++i)
        scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
    for (int i = 0; i < base * 2; ++i)
        t[i] = -1;
    check();
    for (int i = 0; i < k; ++i)
        swap(cx[i], cy[i]);
    for (int i = 0; i < q; ++i)
    {
        swap(x1[i], y1[i]);
        swap(x2[i], y2[i]);
    }
    for (int i = 0; i < base * 2; ++i)
        t[i] = -1;
    for (int i = 0; i < 200000; ++i)
        pt[i].clear(), rect[i].clear();
    check();
    for (int i = 0; i < q; ++i)
        if (!bad[i])
            cout << "NO\n";
        else
            cout << "YES\n";
    return 0;
}