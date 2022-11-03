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
    n *= 2;
    vector<vector<int> > a(n, vector<int>(n));
    for (auto &i : a)
        for (auto &j : i)
            cin >> j;

    long long ans = 0;
    for (int i = n / 2; i < n; i++)
    {
        for (int j = n / 2; j < n; j++)
            ans += a[i][j];
    }
    int mini = 1e9;
    mini = min(mini, a[0][n / 2]);
    mini = min(mini, a[0][n - 1]);
    mini = min(mini, a[n / 2 - 1][n / 2]);
    mini = min(mini, a[n / 2 - 1][n - 1]);
    mini = min(mini, a[n / 2][0]);
    mini = min(mini, a[n / 2][n / 2 - 1]);
    mini = min(mini, a[n - 1][0]);
    mini = min(mini, a[n - 1][n / 2 - 1]);
    cout << ans + mini << '\n';
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