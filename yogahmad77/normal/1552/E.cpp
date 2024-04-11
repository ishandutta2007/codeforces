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
    int berapa = n / (k - 1);
    if (n % (k - 1))
        berapa += 1;
    vector<int> a(n * k);
    for (int &i : a)
    {
        cin >> i;
        i -= 1;
    }
    vector<int> di(n, -1), sudah(n, 0);
    int terakhir = -1;
    vector<pair<int, int>> ans(n);
    int udah = 0;
    for (int i = 0; i < n * k; i++)
    {
        if (sudah[a[i]])
            continue;

        // debug(i, terakhir, udah, berapa);

        if (di[a[i]] <= terakhir)
        {
            di[a[i]] = i;
        }
        else
        {
            ans[a[i]] = {di[a[i]] + 1, i + 1};
            sudah[a[i]] = 1;
            udah += 1;
            if (udah == berapa)
            {
                // debug(terakhir + 1, i);
                udah = 0;
                terakhir = i;
            }
        }
    }

    for (auto i : ans)
    {
        cout << i.f << ' ' << i.s << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}