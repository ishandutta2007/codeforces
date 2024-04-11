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

int tanya(vector<int> vv)
{
    cout << "?";
    for (int i : vv)
        cout << ' ' << i;
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    vector<int> dist(n + 1, -1), dari(n + 1, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int now = q.front();
        // debug(now, dist[now]);
        q.pop();
        int sisa = n - now;
        for (int i = 0; i <= min(now, k); i++)
        {
            int j = k - i;
            if (sisa < j)
                continue;
            int a = now - i + j;
            int b = sisa - j + i;
            if (dist[a] == -1)
            {
                dist[a] = dist[now] + 1;
                dari[a] = now;
                q.push(a);
            }
        }
    }

    if (dist[n] == -1)
    {
        cout << -1 << endl;
        return;
    }

    int now = n;
    vector<int> ve;
    ve.push_back(now);
    while (now != 0)
    {
        now = dari[now];
        ve.push_back(now);
    }

    reverse(ALL(ve));

    vector<int> satu, dua;
    for (int i = 1; i <= n; i++)
        dua.push_back(i);

    int ans = 0;

    for (int i = 1; i < sz(ve); i++)
    {
        int dari = ve[i - 1];
        int jadi = ve[i];
        for (int j = 0; j <= min(k, dari); j++)
        {
            int jj = k - j;
            if (n - dari < jj)
                continue;
            int a = dari - j + jj;
            if (a == jadi)
            {
                vector<int> vv, pindahsatu, pindahdua;

                for (int x = 0; x < j; x++)
                {
                    vv.push_back(satu.back());
                    pindahdua.push_back(satu.back());
                    satu.pop_back();
                }

                for (int x = 0; x < jj; x++)
                {
                    vv.push_back(dua.back());
                    pindahsatu.push_back(dua.back());
                    dua.pop_back();
                }

                ans ^= tanya(vv);

                for (int x : pindahsatu)
                    satu.push_back(x);
                for (int x : pindahdua)
                    dua.push_back(x);

                break;
            }
        }
    }

    cout << "! " << ans << endl;
}

int main()
{
    int t = 1;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}