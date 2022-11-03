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
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> g(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    for (int i = 0; i < n; i++)
    {
        g[a[i] - 1] = b[i] - 1;
    }

    vector<int> sudah(n, 0);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (sudah[i])
            continue;

        int now = i;
        while (!sudah[now])
        {
            sudah[now] = 1;
            now = g[now];
        }
        ans = (ans + ans) % MOD;
    }

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