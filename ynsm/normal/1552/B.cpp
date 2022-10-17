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

int n, m, a[N][5];
bool check(int i, int j){
    int cnt = 0;
    for(int q = 0; q < m; q++)
        cnt += (a[i][q] <= a[j][q]);
    return cnt >= 3;
}
void solve()
{
    scanf("%d", &n);
    m = 5;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    int p = 0;
    for (int i = 1; i < n; i++)
        if (check(i, p))
            p = i;
    bool ok = 1;
    for (int i = 0; i < n; i++)
        ok &= check(p, i);
    printf("%d\n", ok ? p + 1: -1);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}