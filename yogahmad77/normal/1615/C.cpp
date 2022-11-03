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

void solve(int tc)
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    int ans = 1e9;
    // anggak ganjil x
    int tot = 0, nol = 0, satu = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] == '0')
                nol += 1;
            else
                satu += 1;
            tot += 1;
        }
    }
    if (tot % 2 == 1 && satu == nol + 1)
    {
        ans = tot;
    }
    // genap x
    tot = 0;
    nol = satu = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] == '0')
                nol += 1;
            else
                satu += 1;
            tot += 1;
        }
    }
    if (tot % 2 == 0 && satu == nol)
    {
        ans = min(ans, tot);
    }
    if (ans >= 1e9)
        ans = -1;
    cout << ans << '\n';
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