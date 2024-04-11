#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 450;

int n, mod;
ll pw[N], dp[N][N], c[N][N];
int main()
{
    scanf("%d%d", &n, &mod);
    for (int i = 0; i < N; i++)
        c[0][i] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 1; j <= i; j++)
            c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % mod;
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * 2 % mod;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            for (int q = 1; i + q <= n; q++)
                dp[i + q + 1][j + q] = (dp[i + q + 1][j + q] + pw[q - 1] * c[j][j + q] % mod * dp[i][j]) % mod;
    ll ans = 0;
    for (int i = 0; i <= n; i++)
        ans += dp[n + 1][i];
    ans %= mod;
    printf("%lld", ans);
}