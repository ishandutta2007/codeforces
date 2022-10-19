#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100100;
const ll INF = (ll)1e18 + 123;

ll pw[N];
void solve()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    if (k > pw[n - 1])
    {
        printf("-1\n");
        return;
    }
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j + 1 < n && pw[n - j - 2] < k)
        {
            k -= pw[n - j - 2];
            j++;
        }
        for (int q = j; q >= i; q--)
            printf("%d ", q + 1);
        i = j + 1;
    }
    printf("\n");
}
int main()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = min(INF, pw[i - 1] * 2);

    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}