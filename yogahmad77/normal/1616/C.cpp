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
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    int ans = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int atas = a[j] - a[i];
            int bawah = j - i;
            int tot = 0;
            for (int x = 0; x < n; x++)
            {
                int sel = x - i;
                if (sel * atas % bawah == 0)
                {
                    int aa = a[i] + sel * atas / bawah;
                    if (aa == a[x])
                    {
                        tot += 1;
                    }
                }
            }
            ans = max(ans, tot);
        }
    }
    cout << n - ans << '\n';
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