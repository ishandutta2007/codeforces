#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        long long n, k; cin >> n >> k;
        long long a, b, c, d; cin >> a >> b >> c >> d;
        if(a > c) swap(a, c), swap(b, d);
        k -= max(0ll, min(b, d) - max(a, c)) * n;
        if(k <= 0) { cout << "0\n"; continue; }
        long long x = max(0ll, c - b);
        long long y = 2 * (max(b, d) - min(a, c)) - (b - a) - (d - c) - x;
        long long ans = 8e18;
        for(int i = 1; i <= n; ++i)
        {
            if(k <= i * y) ans = min(ans, i * x + k);
            else ans = min(ans, i * x + i * y + 2 * (k - i * y));
        }
        cout << ans << '\n';
    }
}