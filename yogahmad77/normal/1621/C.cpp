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

int tanya(int x)
{
    x += 1;
    cout << "? " << x << endl;
    int ret;
    cin >> ret;
    ret -= 1;
    return ret;
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> sudah(n, 0);
    vector<int> ans(n);
    int idx = 0;
    int ke = 0;
    for (int i = 0; i < n; i++)
    {
        if (sudah[i])
            continue;
        int now = tanya(i);
        ke += 1;
        vector<int> ve;
        while (!sudah[now])
        {
            // debug(now);
            ve.push_back(now);
            sudah[now] = 1;
            int x = tanya(i);
            now = x;
            ke += 1;
        }
        int start;
        // reverse(ALL(ve));
        for (int x = 0; x < sz(ve); x++)
        {
            if (ve[x] == i)
                start = x;
        }
        for (int x = start; x < sz(ve) + start; x++)
        {
            int y = x % sz(ve);
            int z = y - 1;
            if (z < 0)
                z += sz(ve);
            ans[ve[z]] = ve[y];
        }
        idx += 1;
    }
    cout << "!";
    for (int i = 0; i < n; i++)
    {
        cout << " " << ans[i] + 1;
    }
    cout << endl;
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