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
    string ss;
    cin >> n >> m;
    cin >> ss;
    while (m--)
    {
        int change = 0;
        string jadi = ss;
        for (int i = 0; i < n; i++)
        {
            int idup = 0;
            if (i > 0 && ss[i - 1] == '1')
                idup += 1;
            if (i + 1 < n && ss[i + 1] == '1')
                idup += 1;
            if (idup == 1)
                jadi[i] = '1';
        }
        if (ss != jadi)
            change = 1;
        ss = jadi;
        if (!change)
            break;
    }
    cout << ss << '\n';
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