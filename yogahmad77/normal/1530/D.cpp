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

int dfs(int now, vector<int> &a, vector<int> &sudah, int time)
{
    if (sudah[now] != -1)
        return now;

    // debug(now);
    sudah[now] = time;
    return dfs(a[now], a, sudah, time);
}

void dfs_0(int now, vector<int> &a, vector<int> &b, int awal, int x = 0)
{
    if (awal == now && x == 1)
        return;
    b[a[now]] = now;
    dfs_0(a[now], a, b, awal, 1);
}

int cari(int now, vector<int> &a, vector<int> &b)
{
    if (b[a[now]] == -1)
    {
        b[a[now]] = now;
        return cari(a[now], a, b);
    }
    int x = a[now];
    int y = b[x];
    b[a[now]] = now;
    return y;
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> a(n), sudah(n, -1), b(n, -1), cnt(n, 0);
    for (auto &i : a)
        cin >> i, i -= 1, cnt[i] += 1;
    auto ans = a;
    vector<int> awal;
    for (int i = 0; i < n; i++)
    {
        if (sudah[i] != -1)
            continue;
        int aa = dfs(i, a, sudah, i);
        if (sudah[aa] != i)
            continue;
        awal.push_back(aa);
    }

    for (int i : awal)
    {
        dfs_0(i, a, b, i);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     debug(i, b[i]);
    // }

    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == 0)
        {
            assert(b[i] == -1);
            int xx = cari(i, a, b);

            b[i] = xx;
            ans[xx] = i;
        }
    }

    int jaw = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == a[i])
            jaw += 1;
    }
    cout << jaw << '\n';

    for (int i : ans)
    {
        cout << i + 1 << ' ';
    }
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