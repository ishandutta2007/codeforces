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
    int n, k;
    cin >> n >> k;
    vector<int> sama(n * 2, -1);
    vector<pair<int, int>> edge;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        sama[x] = y;
        sama[y] = x;
        edge.push_back({x, y});
    }

    vector<int> sisa;
    for (int i = 0; i < n * 2; i++)
    {
        if (sama[i] == -1)
        {
            sisa.push_back(i);
        }
    }

    for (int i = 0; i < sz(sisa) / 2; i++)
    {
        int j = i + sz(sisa) / 2;
        int x = sisa[i];
        int y = sisa[j];

        edge.push_back({x, y});
    }
    int ans = 0;
    for (int i = 0; i < sz(edge); i++)
    {
        for (int j = i + 1; j < sz(edge); j++)
        {
            vector<pair<int, int>> a;
            a.push_back({edge[i].f, 0});
            a.push_back({edge[i].s, 0});
            a.push_back({edge[j].f, 1});
            a.push_back({edge[j].s, 1});

            sort(ALL(a));

            int yes = 1;
            if (a[0].s == a[1].s)
                yes = 0;
            else if (a[1].s == a[2].s)
                yes = 0;
            else if (a[2].s == a[3].s)
                yes = 0;
            else if (a[3].s == a[0].s)
                yes = 0;

            ans += yes;
        }
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