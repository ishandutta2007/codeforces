#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
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

const int mx = 2e5 + 10;
const int MOD = 1e9 + 7;

string ss[mx];
int ans;

int yes[mx];
int n, m, p;

int id[mx];

void solve(int tc)
{
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i];
    }
    vector<int> apa;
    for (int i = 0; i < m; i++)
    {
        int hit = 0;
        for (int j = 0; j < n; j++)
        {
            if (ss[j][i] == '1')
            {
                hit += 1;
            }
        }
        if (hit * 2 >= n)
        {
            yes[i] = 1;
            id[i] = sz(apa);
            apa.push_back(i);
        }
    }
    map<int, int> sum;
    set<int> sudah;
    for (int i = 0; i < n; i++)
    {
        int bil = 0;
        for (int j = 0; j < m; j++)
        {
            if (yes[j] && ss[i][j] == '1')
            {
                bil += 1 << id[j];
            }
        }
        sum[bil] += 1;
        sudah.insert(bil);
    }

    for (int i = 0; i < sz(apa); i++)
    {
        set<int> baru;
        for (int j : sudah)
        {
            if (j & (1 << i))
            {
                int x = j ^ (1 << i);
                baru.insert(x);
                sum[x] += sum[j];
            }
        }
        for (int j : baru)
            sudah.insert(j);
    }
    int jaw = 0;

    for (auto x : sum)
    {
        if (x.s * 2 < n)
            continue;
        if (ans < __builtin_popcount(x.f))
        {
            ans = __builtin_popcount(x.f);
            jaw = x.f;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (!yes[i])
            cout << 0;
        else
        {
            if (jaw & (1 << id[i]))
                cout << 1;
            else
                cout << 0;
        }
    }
    cout << '\n';
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