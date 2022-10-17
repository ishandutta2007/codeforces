#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, l, r, a[N];
void solve()
{
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        scanf("%d", &c);
        c--;
        if (i < l)
        {
            a[c]++;
        }
        else
        {
            a[c]--;
        }
    }
    sort(a, a + n);
    int ans = 0;
    int s = 0, as = 0;
    for (int i = 0; i < n; i++)
        s += a[i], as += abs(a[i]);
    if (s < 0)
    {
        s = -s;
        for (int i = 0; i < n; i++)
            a[i] = -a[i];
        reverse(a, a + n);
    }
    ans += (as - s) / 2;
    int lst = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < 0)
            continue;
        for (int j = 0; j < a[i] - a[i] % 2; j++)
        {
            int cur = i;
            if (lst == -1)
            {
                lst = cur;
                continue;
            }
            if (s > 0 && cur == lst)
            {
                s -= 2;
                ans++;
                lst = -1;
                continue;
            }
            if (s > 0 && cur != lst)
            {
                s -= 2;
                ans += 2;
                lst = -1;
                continue;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < 0)
            continue;
        for (int j = 0; j < a[i] % 2; j++)
        {
            int cur = i;
            if (lst == -1)
            {
                lst = cur;
                continue;
            }
            if (s > 0 && cur == lst)
            {
                s -= 2;
                ans++;
                lst = -1;
                continue;
            }
            if (s > 0 && cur != lst)
            {
                s -= 2;
                ans += 2;
                lst = -1;
                continue;
            }
        }
    }

    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}