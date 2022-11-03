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

int berapa(string ss)
{
    int satu = 0, dua = 0;
    int a = 5, b = 5;

    for (int i = 0; i < 10; i++)
    {
        if (i & 1)
        {
            satu += ss[i] - '0';
            a -= 1;
        }
        else
        {
            dua += ss[i] - '0';
            b -= 1;
        }

        // satu pasti menang
        if (satu > dua + b)
        {
            return i + 1;
        }

        if (dua > satu + a)
        {
            return i + 1;
        }
    }

    return 10;
}

void solve(int tc)
{
    string ss;
    cin >> ss;
    int ans = 1e9;

    string s1 = ss, s2 = ss;

    for (int i = 0; i < 10; i++)
    {
        if (ss[i] == '?')
        {
            if (i & 1)
            {
                s1[i] = '1';
                s2[i] = '0';
            }
            else
            {
                s1[i] = '0';
                s2[i] = '1';
            }
        }
    }

    // debug(s1, s2);

    cout << min(berapa(s1), berapa(s2)) << '\n';
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