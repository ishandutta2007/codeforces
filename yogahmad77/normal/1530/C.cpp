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
    vector<int> a(n), b(n), prefA(n, 0), prefB(n, 0);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    sort(ALL(a));
    reverse(ALL(a));
    sort(ALL(b));
    reverse(ALL(b));
    for (int i = 0; i < n; i++)
    {
        prefA[i] = a[i];
        prefB[i] = b[i];
        if (i > 0)
        {
            prefA[i] += prefA[i - 1];
            prefB[i] += prefB[i - 1];
        }
    }

    int lo = 0, hi = n, mid, ans = n;
    while (lo <= hi)
    {
        mid = (lo + hi) >> 1;
        int x = n + mid;
        int berapa = x - (x / 4);
        int A = 0, B = 0;
        A += mid * 100 + prefA[berapa - mid - 1];
        B += prefB[min(n - 1, berapa - 1)];
        // debug(mid, A, B);
        if (A >= B)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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