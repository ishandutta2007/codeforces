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

const int mx = 6e5 + 10;
const int MOD = 1e9 + 7;

int lazy[mx * 4], mini[mx * 4];
void build(int idx, int l, int r)
{
    lazy[idx] = 0;
    if (l == r)
    {
        mini[idx] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
}

void upd(int idx, int l, int r, int fl, int fr, int val)
{
    if (fl > r || fr < l)
        return;
    if (fl <= l && r <= fr)
    {
        mini[idx] += val;
        lazy[idx] += val;
        return;
    }
    if (lazy[idx] != 0)
    {
        mini[idx * 2] += lazy[idx];
        mini[idx * 2 + 1] += lazy[idx];
        lazy[idx * 2] += lazy[idx];
        lazy[idx * 2 + 1] += lazy[idx];
        lazy[idx] = 0;
    }
    int mid = (l + r) >> 1;
    upd(2 * idx, l, mid, fl, fr, val);
    upd(2 * idx + 1, mid + 1, r, fl, fr, val);
    mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int> > b(m);
    for (int &i : a)
        cin >> i;
    for (auto &i : b)
    {
        int k;
        cin >> k;
        i.resize(k);
        for (auto &j : i)
            cin >> j;
    }
    vector<long long> atas, bawah;
    for (int i = 0; i < n; i++)
    {
        atas.push_back(a[i]);
        bawah.push_back(1);
    }
    for (auto i : b)
    {
        long long sum = 0;
        for (int j : i)
            sum += j;
        atas.push_back(sum);
        bawah.push_back(sz(i));
    }
    for (auto i : b)
    {
        long long sum = 0;
        for (int j : i)
            sum += j;
        for (int j : i)
        {
            atas.push_back(sum - j);
            bawah.push_back(sz(i) - 1);
        }
    }
    vector<int> ve(sz(atas));
    iota(ALL(ve), 0);
    sort(ALL(ve), [&](int i, int j)
         {
             if (atas[i] * bawah[j] == atas[j] * bawah[i])
                 return i < j;
             return atas[i] * bawah[j] > atas[j] * bawah[i];
         });
    int N = sz(ve);
    vector<int> di(N);
    for (int i = 0; i < N; i++)
    {
        di[ve[i]] = i;
    }
    build(1, 0, N - 1);
    for (int i = 0; i < n; i++)
    {
        upd(1, 0, N - 1, di[i], N - 1, 1);
        // debug(di[i]);
    }
    // debug(mini[1]);
    for (int i = 0; i < m; i++)
    {
        upd(1, 0, N - 1, di[n + i], N - 1, -1);
    }
    // debug(mini[1]);
    int ke = 0;
    for (int i = 0; i < m; i++)
    {
        upd(1, 0, N - 1, di[n + i], N - 1, 1);
        for (int j = 0; j < sz(b[i]); j++)
        {
            upd(1, 0, N - 1, di[n + m + ke], N - 1, -1);
            // debug(atas[n + m + ke], bawah[n + m + ke], di[n + m + ke], mini[1]);
            if (mini[1] < 0)
            {
                cout << 0;
            }
            else
                cout << 1;
            upd(1, 0, N - 1, di[n + m + ke], N - 1, 1);
            ke += 1;
        }
        upd(1, 0, N - 1, di[n + i], N - 1, -1);
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