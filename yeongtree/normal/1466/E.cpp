#include <iostream>

using namespace std;

const int Q = (int)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int pow[120];
    pow[0] = 1;
    for(int i = 1; i < 120; ++i) pow[i] = pow[i - 1] * 2 % Q;

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        long long A[n];
        for(auto &i : A) cin >> i;
        int cnt[60]{};
        for(auto i : A)
        {
            for(int j = 0; j < 60; ++j) if(i >> j & 1) ++cnt[j];
        }
        long long B[n];
        for(int k = 0; k < n; ++k)
        {
            int alt = 0;
            long long i = A[k];
            for(int j = 0; j < 60; ++j) if(i >> j & 1)
            {
                alt += (1ll * pow[j] * (n - cnt[j])) % Q;
                alt %= Q;
            }
            B[k] = alt;
        }
        int ans = 0;
        for(int i = 0; i < 60; ++i)
        {
            for(int j = 0; j < 60; ++j)
            {
                ans += 1ll * cnt[i] * cnt[i] % Q * cnt[j] % Q * pow[i + j] % Q;
                ans %= Q;
            }
        }
        for(int j = 0; j < 60; ++j)
        {
            int tmp = 0;
            for(int i = 0; i < n; ++i) if(A[i] >> j & 1) tmp = (tmp + B[i]) % Q;
            ans += 1ll * tmp * cnt[j] % Q * pow[j] % Q;
            ans %= Q;
        }
        cout << ans << '\n';
    }
}