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
    vector<int> l(n), r(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i] >> c[i];
    int kiri = 1e9 + 1;
    int kanan = -1;
    map<pair<int, int>, int> cost;
    int hargaKiri;
    int hargaKanan;
    for (int i = 0; i < n; i++)
    {
        if (!cost.count({l[i], r[i]}))
            cost[{l[i], r[i]}] = c[i];
        else
            cost[{l[i], r[i]}] = min(c[i], cost[{l[i], r[i]}]);
        if (kanan < r[i])
        {
            kanan = r[i];
            hargaKanan = c[i];
        }
        else if (kanan == r[i])
            hargaKanan = min(hargaKanan, c[i]);
        if (kiri > l[i])
        {
            kiri = l[i];
            hargaKiri = c[i];
        }
        else if (kiri == l[i])
            hargaKiri = min(hargaKiri, c[i]);
        // debug(kiri, kanan);
        int harga = hargaKiri + hargaKanan;
        if (cost.count({kiri, kanan}))
            harga = min(harga, cost[{kiri, kanan}]);
        cout << harga << '\n';
    }
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