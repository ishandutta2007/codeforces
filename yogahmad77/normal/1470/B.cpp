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

const int mx = 1e6 + 10;
const int MOD = 1e9 + 7;
int p[mx];
int cnt[mx];
void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : a)
    {
        int apa = 1;
        while (i > 1)
        {
            int fak = p[i];
            int jadi = i / fak;
            if (jadi % fak == 0)
            {
                i /= fak;
                i /= fak;
            }
            else
            {
                i /= fak;
                apa *= fak;
            }
        }
        i = apa;
    }

    set<int> ini;

    for (int i : a)
    {
        cnt[i] += 1;
        ini.insert(i);
    }

    int genap = 0;
    int maks = 0;
    for (int i : ini)
    {
        if (cnt[i] % 2 == 0 || i == 1)
        {
            genap += cnt[i];
        }
        maks = max(maks, cnt[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        long long x;
        cin >> x;
        if (x == 0)
        {
            cout << maks << '\n';
        }
        else
        {
            cout << max(maks, genap) << '\n';
        }
    }

    for (int i : a)
        cnt[i] -= 1;
}

int main()
{
    for (int i = 2; i < mx; i++)
    {
        if (p[i])
            continue;
        for (int j = i; j < mx; j += i)
            p[j] = i;
    }
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