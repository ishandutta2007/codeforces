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

int n, a[N], b[N], cnt[N];

void solve()
{
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        cnt[i] = 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int last = -1;
    for (int i = 0, j = 0; i < n; i++)
    {
        int need = b[i];

        if (need == last && cnt[need] > 0)
            cnt[need]--;
        else
        {
            bool found = 0;
            while (j < n)
            {
                if (a[j] == need)
                {
                    found = 1;
                    j++;
                    break;
                }
                else
                {
                    cnt[a[j]]++;
                    j++;
                }
            }
            if (!found)
            {
                printf("NO\n");
                return;
            }
        }
        last = need;
    }

    printf("YES\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}