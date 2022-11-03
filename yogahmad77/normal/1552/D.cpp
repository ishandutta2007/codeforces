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
    set<int> aa;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
            continue;
        if (x < 0)
            x = -x;
        aa.insert(x);
    }

    for (int i : aa)
        a.push_back(i);

    if (sz(aa) < n)
    {
        cout << "YES\n";
        return;
    }

    int ada = 0;

    vector<int> sum(1 << n, 0);
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum[i] += a[j];
        }
    }

    for (int i = 1; i < 1 << n; i++)
    {
        for (int j = 1; j < 1 << n; j++)
        {
            if ((i & j) > 0)
                continue;

            if (sum[i] == sum[j])
            {
                ada = 1;
            }
        }
    }

    if (ada)
        cout << "YES\n";
    else
        cout << "NO\n";
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