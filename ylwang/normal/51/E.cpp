#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define inf 1000000007
#define mod 1000003
#define N 705
#define ll long long
int a[N][N], b[N][N], c[N][N], u, v, n, m, d[N];
ll ans;
int main ()
{
    scanf("%d %d", &n, &m);
    fo (i, 1, m)
    {
        scanf("%d %d", &u, &v);
        ++a[u][v]; ++a[v][u];
        ++d[u]; ++d[v];
    }
    fo (i, 1, n) fo (j, 1, n) fo (k, 1, n)
        b[i][j] += (a[i][k] * a[k][j]);
    fo (i, 1, n) fo (j, 1, n) fo (k, 1, n)
        c[i][j] += (a[i][k] * b[k][j]);
    fo (i, 1, n)
        fo (j, 1, n)
            ans += b[i][j] * c[i][j];
    ans /= 10;
    fo (i, 1, n)
        fo (j, 1, i)
            if (a[i][j])
                fo (k, 1, j)
                {
                    if (!(a[i][k] && a[j][k])) continue;
                    ans -= d[i] + d[j] + d[k] - 3;
                }
    printf("%lld\n", ans);        
    return 0;
}