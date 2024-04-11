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

const int mx = 1e5 + 10;
const int MOD = 1e9 + 7;

int get_msb(int x)
{
    for (int i = 20; i >= 0; i--)
    {
        if (x & (1 << i))
            return i;
    }
    return -1;
}

int berapa(int x, int y)
{
    if (x == 0)
        return 0;

    int msb = get_msb(x);
    if (y < msb)
    {
        return (1 << (msb - 1)) + berapa(x - (1 << msb), y);
    }
    if (y == msb)
    {
        return (x + 1) - (1 << (msb));
    }
    return 0;
}

void solve(int tc)
{
    int l, r;
    cin >> l >> r;
    l -= 1;
    int maks = 0;
    for (int i = 0; i < 20; i++)
    {
        maks = max(maks, berapa(r, i) - berapa(l, i));
    }
    cout << (r - l) - maks << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}