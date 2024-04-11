#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int ans = 0;
        while(n)
        {
            ans = max(ans, n % 10);
            n /= 10;
        }
        cout << ans << '\n';
    }
}