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
    vector<vector<int>> a(n, vector<int>(5));
    for (auto &i : a)
        for (int &j : i)
            cin >> j;

    int menang = 0;
    for (int i = 1; i < n; i++)
    {
        int A = 0;
        for (int j = 0; j < 5; j++)
        {
            if (a[menang][j] < a[i][j])
                A += 1;
        }

        if (A < 3)
        {
            menang = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == menang)
            continue;
        int A = 0;
        for (int j = 0; j < 5; j++)
        {
            if (a[menang][j] < a[i][j])
                A += 1;
        }

        if (A < 3)
        {
            menang = -2;
            break;
        }
    }

    cout << menang + 1 << '\n';
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