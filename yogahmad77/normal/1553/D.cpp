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
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> di1(26), di2(26);

    for (int i = 0; i < sz(s1); i++)
    {
        if (i & 1)
        {
            di1[s1[i] - 'a'].push_back(i);
        }
        else
        {
            di2[s1[i] - 'a'].push_back(i);
        }
    }

    int yes = 0;
    int tmp = -1, ans = 1;
    int xx = 0;
    for (auto i : s2)
    {
        if (xx & 1)
        {
            int x = i - 'a';
            int in = upper_bound(ALL(di1[x]), tmp) - di1[x].begin();

            if (in == sz(di1[x]))
            {
                ans = 0;
                break;
            }

            tmp = di1[x][in];
        }

        else
        {
            int x = i - 'a';
            int in = upper_bound(ALL(di2[x]), tmp) - di2[x].begin();

            if (in == sz(di2[x]))
            {
                ans = 0;
                break;
            }

            tmp = di2[x][in];
        }

        xx ^= 1;
    }

    if (ans)
    {
        if ((sz(s1) - tmp - 1) % 2 == 0)
        {
            yes = 1;
        }
    }

    ans = 1;
    tmp = -1;
    xx = 1;
    for (auto i : s2)
    {
        if (xx & 1)
        {
            int x = i - 'a';
            int in = upper_bound(ALL(di1[x]), tmp) - di1[x].begin();

            if (in == sz(di1[x]))
            {
                ans = 0;
                break;
            }

            tmp = di1[x][in];
        }

        else
        {
            int x = i - 'a';
            int in = upper_bound(ALL(di2[x]), tmp) - di2[x].begin();

            if (in == sz(di2[x]))
            {
                ans = 0;
                break;
            }

            tmp = di2[x][in];
        }

        xx ^= 1;
    }

    if (ans)
    {
        if ((sz(s1) - tmp - 1) % 2 == 0)
        {
            yes = 1;
        }
    }

    if (yes)
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