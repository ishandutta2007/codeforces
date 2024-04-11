#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, r; cin >> n >> r;
        int m = min(n - 1, r);
        long long ans = 1ll * m * (m + 1) / 2;
        if(n <= r) ++ans;
        cout << ans << '\n';
    }
}