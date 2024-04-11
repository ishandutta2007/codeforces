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

int n, p[N];
bool was[N];
ll a[N], b[N];
ll dist(int i, int j)
{
    return (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &a[i], &b[i]);
    was[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int q = -1;
        for (int j = 0; j < n; j++)
            if (!was[j] && (q == -1 || dist(p[i - 1], j) > dist(p[i - 1], q)))
                q = j;
        p[i] = q;
        was[q] = 1;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", p[i] + 1);
}