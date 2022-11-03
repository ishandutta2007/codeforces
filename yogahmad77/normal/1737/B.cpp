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
typedef int (*func)(int, int);

const int mx = 2e5 + 10;

long long hitung(long long x)
{
    if (x == 0)
        return 0;
    long long lo = 1, hi = 1e9 + 8, mid, di = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (mid * mid <= x)
        {
            lo = mid + 1;
            di = mid;
        }
        else
            hi = mid - 1;
    }
    long long dd = di * di;
    long long ee = x;
    dd /= di;
    ee /= di;
    return (di - 1) * 3 + ee - dd + 1;
}

void solve(int tc)
{
    long long l, r;
    cin >> l >> r;
    l -= 1;
    cout << hitung(r) - hitung(l) << '\n';
}

int main()
{
    // for (int x = 1; x <= 40; x++)
    // {
    //     int xx = x * x;
    //     int yy = (x + 1) * (x + 1) - 1;
    //     xx /= x;
    //     yy /= x;
    //     debug(x, yy - xx + 1);
    // }
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}