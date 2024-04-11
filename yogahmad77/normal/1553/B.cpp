#include <bits/stdc++.h>
using namespace std;
#define f first
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
    string s, t;
    cin >> s >> t;
    int ya = 0;
    for (int x = 0; x < sz(s); x++)
    {
        string tmp = "";
        tmp += s[x];
        for (int r = 0; r + x < sz(s); r++)
        {
            if (r > 0)
            {
                tmp += s[r + x];
            }

            int l = sz(t) - (r + 1);

            if (l < 0)
                continue;

            if (r + x - l < 0)
                continue;

            string tambah = "";

            for (int i = 1; i <= l; i++)
            {
                tambah += s[r + x - i];
            }

            if (tmp + tambah == t)
            {
                ya = 1;
            }
        }
    }

    if (ya)
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