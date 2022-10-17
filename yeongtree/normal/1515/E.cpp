#include <iostream>

using namespace std;

int fact[404], revf[404];
int pow(int a, int x, int p)
{
    int ret = 1;
    while(x)
    {
        if(x & 1) ret = 1ll * ret * a % p;
        a = 1ll * a * a % p;
        x >>= 1;
    }
    return ret;
}
int comb(int n, int r, int p)
{
    return 1ll * fact[n] * revf[r] % p * revf[n - r] % p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q; cin >> n >> Q;

    fact[0] = 1; for(int i = 1; i < 404; ++i) fact[i] = 1ll * fact[i - 1] * i % Q;
    revf[0] = revf[1] = 1; for(int i = 2; i < 404; ++i) revf[i] = Q - 1ll * revf[Q % i] * (Q / i) % Q;
    for(int i = 2; i < 404; ++i) revf[i] = 1ll * revf[i] * revf[i - 1] % Q;

    int A[n + 1]{};
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j < i; ++j) A[i] = (A[i] + comb(i - 1, j, Q)) % Q;
    }

    int B[n + 1][n + 1];
    for(auto &i : B) for(auto &j : i) j = 0;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            for(int k = 1; k <= min(i - 2, j); ++k)
            {
                B[i][j] = (B[i][j] + 1ll * A[k] * B[i - k - 1][j - k] % Q * comb(j, k, Q) % Q) % Q;
            }
            if(i == j) B[i][j] = (B[i][j] + A[i]) % Q;
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; ++i) ans = (ans + B[n][i]) % Q;
    cout << ans;
}