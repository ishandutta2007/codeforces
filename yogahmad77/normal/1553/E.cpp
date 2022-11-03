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
    cin >> n >> m;
    vector<int> p(n);
    for (auto &i : p)
        cin >> i, i -= 1;

    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (p[i] <= i)
        {
            cnt[i - p[i]] += 1;
        }
        else
        {
            cnt[i - p[i] + n] += 1;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int sisa = n - cnt[i];

        if (sisa == 1)
            continue;

        if (sisa <= m * 2)
        {
            vector<int> beda;
            auto a = p;
            vector<int> di(n);

            for (int x = 0; x < n; x++)
            {
                di[a[x]] = x;
                int harus = x - i;
                if (harus < 0)
                    harus += n;

                if (harus != a[x])
                {
                    beda.push_back(x);
                }
            }

            int hit = 0;

            for (int x : beda)
            {
                int harus = x - i;
                if (harus < 0)
                    harus += n;

                if (harus == a[x])
                    continue;

                int y = di[harus];

                swap(a[x], a[y]);
                di[a[x]] = x;
                di[a[y]] = y;

                hit += 1;
            }

            if (hit <= m)
            {
                ans.push_back(i);
            }
        }
    }

    cout << sz(ans);

    for (auto i : ans)
        cout << ' ' << i;

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