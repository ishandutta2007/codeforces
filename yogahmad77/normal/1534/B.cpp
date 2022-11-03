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
    vector<long long> a;
    a.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(0);

    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            ans += a[i] - max(a[i - 1], a[i + 1]);
            a[i] = max(a[i - 1], a[i + 1]);
        }
    }

    for (int i = 1; i <= n + 1; i++)
    {
        ans += abs(a[i] - a[i - 1]);
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