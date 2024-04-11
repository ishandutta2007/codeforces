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
int op_n, split_n, split[N];
pii op[N];
void solve()
{
    split_n = op_n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int shift = 0;
    while (n)
    {
        int j = -1;
        for (int i = 1; i < n; i++)
            if (a[i] == a[0])
                j = i;
        if (j == -1)
        {
            printf("-1\n");
            return;
        }
        int pos = j + 1 + shift;
        for (int q = 1; q < j; q++)
        {
            op[op_n++] = {pos, a[q]};
            pos++;
        }
        split[split_n++] = j * 2;
        shift += j * 2;
        reverse(a, a + j);
        for (int i = j - 1; i < n; i++)
            a[i] = a[i + 2];
        n -= 2;
    }
    printf("%d\n", op_n);
    for (int i = 0; i < op_n; i++)
        printf("%d %d\n", op[i].f, op[i].s);
    printf("%d\n", split_n);
    for (int i = 0; i < split_n; i++)
        printf("%d ", split[i]);
    printf("\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}