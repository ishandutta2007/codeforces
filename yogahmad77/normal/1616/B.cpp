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
    string ss;
    cin >> n >> ss;
    int sama = 1;
    for (int i = 1; i < n; i++)
        if (ss[i] != ss[i - 1])
            sama = 0;
    if (sama)
    {
        cout << ss[0] << ss[0] << '\n';
        return;
    }
    if (n > 1 && ss[0] == ss[1])
    {
        cout << ss[0] << ss[0] << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (ss[i] < ss[i + 1])
        {
            for (int x = 0; x <= i; x++)
                cout << ss[x];
            for (int x = i; x >= 0; x--)
                cout << ss[x];
            cout << '\n';
            return;
        }
    }
    for (int x = 0; x < n; x++)
        cout << ss[x];
    for (int x = n - 1; x >= 0; x--)
        cout << ss[x];
    cout << '\n';
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