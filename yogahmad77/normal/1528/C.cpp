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

const int mx = 3e5 + 10;
const int MOD = 1e9 + 7;

vector<int> g1[mx], g2[mx];
int maks[mx * 4];
int mini[mx * 4];
int mana[mx * 4];

void build(int idx, int l, int r)
{
    if (l == r)
    {
        mini[idx] = 1e9;
        maks[idx] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    mini[idx] = max(mini[idx * 2], mini[idx * 2 + 1]);
    maks[idx] = max(maks[idx * 2], maks[idx * 2 + 1]);
}

void upd(int idx, int l, int r, int in, int val)
{
    if (in > r || in < l)
        return;
    if (l == r)
    {
        maks[idx] = val;
        if (val == 0)
            mini[idx] = 1e9;
        mana[idx] = l;
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * idx, l, mid, in, val);
    upd(2 * idx + 1, mid + 1, r, in, val);
    maks[idx] = max(maks[idx * 2], maks[idx * 2 + 1]);
    mini[idx] = max(mini[idx * 2], mini[idx * 2 + 1]);
    if (maks[idx] == maks[idx * 2])
        mana[idx] = mana[idx * 2];
    else
        mana[idx] = mana[idx * 2 + 1];
}

pair<int, int> cari(int idx, int l, int r, int fl, int fr)
{
    if (fl > r || fr < l)
        return {0, 0};
    if (fl <= l && r <= fr)
        return {maks[idx], mana[idx]};
    int mid = (l + r) >> 1;
    auto aa = cari(2 * idx, l, mid, fl, fr);
    auto bb = cari(2 * idx + 1, mid + 1, r, fl, fr);
    pair<int, int> cc;
    cc.f = max(aa.f, bb.f);
    if (cc.f == aa.f)
        cc.s = aa.s;
    else
        cc.s = bb.s;

    return cc;
}

int cari_min(int idx, int l, int r, int fl, int fr)
{
    if (fl > r || fr < l)
        return 1e9;
    if (fl <= l && r <= fr)
        return mini[idx];
    int mid = (l + r) >> 1;
    auto aa = cari_min(2 * idx, l, mid, fl, fr);
    auto bb = cari_min(2 * idx + 1, mid + 1, r, fl, fr);
    return min(aa, bb);
}

int in[mx], out[mx], idx;
int n;
int tot, jaw;
void dfs_1(int now)
{
    // debug(now);
    for (int i : g1[now])
    {
        vector<pair<int, int>> balik;
        int mi = cari_min(1, 1, n, in[i], out[i]);
        if (mi > out[i])
        {
            // debug("masuk", in[i], out[i]);
            auto ma = cari(1, 1, n, 1, in[i] - 1);
            while (ma.f >= out[i])
            {
                balik.push_back(ma);
                // debug("keluar", ma.s, ma.f);
                upd(1, 1, n, ma.second, 0);
                tot -= 1;
                ma = cari(1, 1, n, 1, in[i] - 1);
            }
            upd(1, 1, n, in[i], out[i]);
            tot += 1;
            jaw = max(jaw, tot);
            // debug(tot);
        }

        dfs_1(i);

        // debug("kerluar", in[i], out[i]);

        if (mi > out[i])
        {
            for (auto x : balik)
            {
                upd(1, 1, n, x.s, x.f);
                tot += 1;
            }
            balik.clear();
            upd(1, 1, n, in[i], 0);
            tot -= 1;
        }
    }
}

void dfs_2(int now)
{
    in[now] = ++idx;
    for (int i : g2[now])
    {
        dfs_2(i);
    }
    out[now] = idx;
}

void solve(int tc)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g1[i].clear();
        g2[i].clear();
    }
    jaw = 0;
    tot = 0;
    idx = 0;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        g1[a].push_back(i);
    }
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        g2[a].push_back(i);
    }
    build(1, 1, n);
    dfs_2(1);
    upd(1, 1, n, in[1], out[1]);
    tot += 1;
    jaw = max(jaw, tot);
    dfs_1(1);
    cout << jaw << '\n';
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