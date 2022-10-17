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
    vector<int> v;
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
            v.pb(i);

    if (v.size() <= 1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", max(1, v[v.size() - 1] - v[0] - 1));
    }
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}