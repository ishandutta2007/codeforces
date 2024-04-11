#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k, z; cin >> n >> k >> z;
        int arr[n + 1]{}; for(int i = 0; i < n; ++i) cin >> arr[i];
        long long __ans = 0;
        for(int i = 0; i <= z; ++i)
        {
            long long ans = 0;
            long long mx = 0;
            for(int j = 0; j < k - 2 * i + 1; ++j)
            {
                ans += arr[j];
                mx = max(mx, 1ll * arr[j] + arr[j + 1]);
            }
            __ans = max(__ans, ans + mx * i);
        }
        cout << __ans << '\n';
    }
}