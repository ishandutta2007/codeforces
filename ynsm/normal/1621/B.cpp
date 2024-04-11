#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 2e9, mod = 1e9 + 7;
const ll INF = 1e18;

void solve()
{
    int n;
    scanf("%d", &n);
    int L, R, M;
    int LC, RC, MC;
    L = inf, R = -inf;
    M = -inf;
    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);

        if (l < L)
            L = l, LC = c;
        else if (l == L)
            LC = min(LC, c);

        if (r > R)
            R = r, RC = c;
        else if (r == R)
            RC = min(RC, c);

        if (r - l + 1 > M)
            M = r - l + 1, MC = c;
        else if (r - l + 1 == M)
            MC = min(MC, c);

        if (R - L + 1 > M)
            printf("%d\n", LC + RC);
        else
            printf("%d\n", min(LC + RC, MC));
    }
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}