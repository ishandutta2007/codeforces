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

int n, a[N], b[N], c[N];
void solve()
{
    scanf("%d", &n);
    bool ok = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        b[i] = a[i], c[i] = a[i];
    for(int i = 1; i < n; i++)
        b[i] = max(b[i], b[i - 1]);
    for(int i = n - 2; i >= 0; i--)
        c[i] = min(c[i], c[i + 1]);
    for(int i = 0; i + 1 < n; i++)
        ok |= (b[i] > c[i + 1]);
    if(ok)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve();
}