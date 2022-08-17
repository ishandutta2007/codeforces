#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

const int N = 1 << 18;
typedef long long llong;
llong P[N];
llong X[N];
llong D[N];
const llong INF = 1e12;

struct trip
{
    int len;
    llong l, r, s, v;
    trip(){}
    trip(llong _l, llong _r, llong _s, llong _v, int _len) : l(_l), r(_r), s(_s), v(_v), len(_len) {}
    trip(llong _v)
    {
        s = _v;
        if (_v > 0)
            v = l = r = _v, len = 1;
        else
            v = l = r = 0, len = 1;
    }
    friend trip operator +(trip a, trip b)
    {
        //assert(a.len == b.len);
        return trip(max(a.l, a.s + b.l), max(b.r, b.s + a.r), a.s + b.s, max(max(a.v, b.v), a.r + b.l), a.len + b.len);
    }
};
trip T[2 * N];

int n, m, c;

long long ans = 0;

trip go(int l, int r, int L, int R, int v)
{
    if (l <= L && R <= r)
        return T[v];
    else if (l > R || r < L)
        return trip(-INF);
    else
        return go(l, r, L, (L + R) / 2, 2 * v) +
        go(l, r, (L + R) / 2 + 1, R, 2 * v + 1);
}


void init()
{
    for (int i = 1; i < n; i++)
        T[i + N - 1] = trip(50 * D[i] - c * P[i]);
    for (int i = n; i + N - 1 < 2 * N; i++)
        T[i + N - 1] = trip(-INF);
    for (int i = N - 1; i > 0; i--)
        T[i] = T[2 * i] + T[2 * i + 1];
}

int main()
{
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 1; i < n; i++)
        D[i] = X[i] - X[i - 1];
    for (int i = 1; i < n; i++)
        cin >> P[i];
    init();
    llong ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        trip t = go(a, b - 1, 1, N, 1);
        ans += t.v;
    }
    assert(ans >= 0);
    cout << fixed << setprecision(10);

    cout << (double)ans / 100;
}