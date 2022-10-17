#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, c, a[N], b[N];

int get(int l, int r)
{
    if (l == 0)
        return b[r];
    return b[r] - b[l - 1];
}
void solve()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= c; i++)
        a[i] = b[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= c; i++)
        b[i] = a[i] + b[i - 1];
    for (int i = 1; i <= c; i++)
    {
        for (int j = i; j <= c; j += i)
        {
            int l = j, r = min(c, j + i - 1);
            if (get(l, r) > 0 && a[i] > 0 && a[l / i] == 0)
            {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}