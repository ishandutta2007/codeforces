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
    int m;
    int n;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    set<pair<int, int> > bad;
    for (int &i : a)
    {
        cin >> i;
        cnt[i] += 1;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        bad.insert({x, y});
        bad.insert({y, x});
    }
    vector<vector<int> > di(n + 1);
    for (auto x : cnt)
    {
        di[x.s].push_back(x.f);
    }
    for (int i = 0; i <= n; i++)
    {
        sort(ALL(di[i]));
    }
    vector<int> ada;
    for (int i = 1; i <= n; i++)
    {
        if (sz(di[i]) > 0)
            ada.push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < sz(ada); i++)
    {
        for (int j = i; j < sz(ada); j++)
        {
            int cntX = ada[i];
            int cntY = ada[j];
            for (int x : di[cntX])
            {
                int yi = sz(di[cntY]) - 1;
                while (yi >= 0)
                {
                    int y = di[cntY][yi];
                    if (x == y)
                        break;
                    if (bad.count({x, y}))
                    {
                        yi -= 1;
                        continue;
                    }
                    ans = max(ans, 1LL * (cntX + cntY) * (x + y));
                    break;
                }
            }
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