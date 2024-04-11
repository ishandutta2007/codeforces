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

int n, ans[N], p[N], q[N], qq[N];
bool was[N];
int ask(int i)
{
    printf("? %d\n", i);
    fflush(stdout);
    
    int res;
    // res = q[i];
    scanf("%d", &res);
    fflush(stdout);
    // cerr << "A " << res << endl;
    
    // for(int i = 1; i <= n; i++)
    //     qq[i] = q[p[i]];
    // for(int i = 1; i <= n; i++)
    //     q[i] = qq[i];

    return res;
}
void solve()
{
    scanf("%d", &n);
    
    // for(int i = 1; i <= n; i++)
    //     scanf("%d", &p[i]);

    // for(int i = 1; i <= n; i++)
    //     q[i] = i;

    for (int i = 1; i <= n; i++)
        was[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (was[i])
            continue;
        int x = ask(i);
        while (!was[x])
        {
            int y = ask(i);
            was[x] = 1;
            // cerr << "B " << x << " " << y << endl;
            ans[x] = y;
            x = y;
        }
        // ans[i] = x;
    }
    printf("! ");
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
    
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}