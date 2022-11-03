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
int n;

double dp(int berapa, int gak, int ya, int k)
{
    if (berapa == 0)
    {
        if (k == 0)
            return 1.0;
        return 0.0;
    }
    // debug((double)(ya + gak) / (double)(n - (3 - berapa)));
    double ret = 0.0;
    // ngambil ya
    if (ya > 0 && k > 0)
    {
        ret += (double)(ya) / (double)(n - (3 - berapa)) * dp(berapa - 1, gak, ya - 1, k - 1);
    }
    // ngambil gak
    if (gak > 0)
    {
        ret += (double)(gak) / (double)(n - (3 - berapa)) * dp(berapa - 1, gak - 1, ya, k);
    }
    return ret;
}

double hitung(int n, int k)
{
    double N = n;
    double K = k;
    if (k == 0)
        return 0.0;
    double ret = 0.0;
    if (k > 0)

        ret += dp(3, n - k, k, 1) / 2.0;

    if (k > 1)
        ret += dp(3, n - k, k, 2);

    if (k > 2)
        ret += dp(3, n - k, k, 3);

    // debug(n, k, ret);

    return ret;
}

const double EPS = 1e-9;

void solve(int tc)
{
    double p;
    cin >> n >> p;
    int lo = 0, hi = n, mid, ans = n;
    while (lo <= hi)
    {
        mid = (lo + hi) >> 1;
        // debug(hitung(n, mid));
        if (hitung(n, mid) - p > -EPS)
        {
            hi = mid - 1;
            ans = mid;
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
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}