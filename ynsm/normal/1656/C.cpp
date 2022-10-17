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

int n, a[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    bool ok = 1, ok2 = 1;
    for (int i = 1; i < n; i++)
        ok &= (a[i] - a[i - 1] != 1);
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            ok2 = 0;

    if (ok || ok2)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}