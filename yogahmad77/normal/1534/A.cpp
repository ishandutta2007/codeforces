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
    vector<string> ss(n), s1(n), s2(n);
    for (auto &i : ss)
        cin >> i;

    for (int i = 0; i < n; i++)
    {
        s1[i] = ss[i];
        s2[i] = ss[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ss[i][j] == '.')
            {
                if ((i + j) & 1)
                    s1[i][j] = 'R';
                else
                    s1[i][j] = 'W';

                if ((i + j) & 1)
                    s2[i][j] = 'W';
                else
                    s2[i][j] = 'R';
            }
        }
    }

    int yes1 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n)
            {
                if (s1[i][j] == s1[i + 1][j])
                    yes1 = 0;
            }
            if (j + 1 < m)
            {
                if (s1[i][j] == s1[i][j + 1])
                    yes1 = 0;
            }
        }
    }

    if (yes1)
    {
        cout << "YES\n";
        for (auto i : s1)
            cout << i << '\n';
        return;
    }

    int yes2 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n)
            {
                if (s2[i][j] == s2[i + 1][j])
                    yes2 = 0;
            }
            if (j + 1 < m)
            {
                if (s2[i][j] == s2[i][j + 1])
                    yes2 = 0;
            }
        }
    }

    if (yes2)
    {
        cout << "YES\n";
        for (auto i : s2)
            cout << i << '\n';
        return;
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    cin >> t;
    while (t--)
    {
        solve(++tc);
    }
}