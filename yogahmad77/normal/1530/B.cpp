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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    if (n % 2 == 1 && m % 2 == 1)
    {
        for (int j = 0; j < m; j += 2)
        {
            ans[0][j] = 1;
            ans[n - 1][j] = 1;
        }

        for (int i = 0; i < n; i += 2)
        {
            ans[i][0] = 1;
            ans[i][m - 1] = 1;
        }
    }
    else if (n % 2 == 1)
    {
        for (int i = 0; i < n; i += 2)
        {
            ans[i][0] = 1;
            ans[i][m - 1] = 1;
        }

        for (int j = 0; j < m - 2; j += 2)
        {
            ans[0][j] = 1;
            ans[n - 1][j] = 1;
        }
    }
    else if (m % 2 == 1)
    {
        for (int j = 0; j < m; j += 2)
        {
            ans[0][j] = 1;
            ans[n - 1][j] = 1;
        }

        for (int i = 0; i < n - 2; i += 2)
        {
            ans[i][0] = 1;
            ans[i][m - 1] = 1;
        }
    }
    else
    {
        ans[0][0] = 1;
        ans[n - 1][0] = 1;
        ans[0][m - 1] = 1;
        ans[n - 1][m - 1] = 1;

        for (int j = 2; j < m - 2; j += 2)
        {
            ans[0][j] = 1;
            ans[n - 1][j] = 1;
        }

        for (int i = 2; i < n - 2; i += 2)
        {
            ans[i][0] = 1;
            ans[i][m - 1] = 1;
        }
    }

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << '\n';
    }
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