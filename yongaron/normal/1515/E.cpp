#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int t, n;

ll m;

ll dp[1234][1234];
ll pw[1234];

ll bin[1234][1234];

ll pow(ll a, ll b, ll mod)
{
    if(!b)
        return 1;
    if(b&1)
        return (a*pow(a, b-1, mod))%mod;
    ll tmp = pow(a, b/2, mod);
    return (tmp*tmp)%mod;
}
 
ll inv(ll x)
{
    return pow(x, m-2, m);
}
 
ll fact[1234];
 
ll bino(ll a, ll b)
{
    if(a < b)
        return 0;
    return (((fact[a]*inv(fact[b]))%m)*inv(fact[a-b]))%m;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    // dp[0][0] = 1;
    dp[1][1] = 1;

    fact[0] = 1;
    for(int i = 1; i <= 1e3; i++)
        fact[i] = (i*fact[i-1])%m;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            bin[i][j] = bino(i, j);

    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * 2) % m;
    for (int p = 2; p <= n; p++)
    {
        dp[p][p] = pw[p-1];
        for(int t = 1; t < p; t++)
        {
            for (int i = 1; i < t; i++)
            {
                dp[p][t] += ((pw[i-1] * bin[t][i]) % m) *dp[p-i-1][t-i];
                dp[p][t] %= m;
            }
        }
    }
    ll sum = 0;
    for(int t = 1; t <= n; t++)
        sum += dp[n][t];
    cout << sum%m << endl;
    return 0;
}