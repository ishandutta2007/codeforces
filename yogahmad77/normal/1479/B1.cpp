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
    vector<pair<int, int> > a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            a.push_back(make_pair(x, 1));
        }
        else if (x == a.back().first)
        {
            int y = a.back().second + 1;
            if (y > 2)
                y = 2;
            a[sz(a) - 1].second = y;
        }
        else
        {
            a.push_back(make_pair(x, 1));
        }
    }
    int last_dua = -1;
    int jaw = 0;
    for (int i = 0; i < sz(a); i++)
    {
        jaw += a[i].second;
        if (a[i].second == 2)
        {
            if (last_dua == -1)
            {
                last_dua = i;
                continue;
            }
            if (last_dua % 2 == i % 2 && a[last_dua].first == a[i].first)
            {
                int yes = 1;
                for (int j = last_dua + 2; j < i; j += 2)
                {
                    if (a[j].first != a[i].first)
                        yes = 0;
                }
                if (yes)
                    jaw -= 1;
            }
            last_dua = i;
        }
    }
    cout << jaw << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}