#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        int A[n]; for(auto &i : A) cin >> i;
        long long B[n + 1]; B[0] = 0; for(int i = 0; i < n; ++i) B[i + 1] = B[i] + A[i];

        if(k < n)
        {
            long long ans = 0;
            for(int i = 0; i <= n - k; ++i) ans = max(ans, B[i + k] - B[i]);
            cout << ans + 1ll * k * (k - 1) / 2 << '\n';
        }
        else
        {
            cout << B[n] + 1ll * k * n - 1ll * n * (n + 1) / 2 << '\n';
        }
    }
}