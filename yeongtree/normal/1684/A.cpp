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
        int m = 0, t = n;
        while(t) ++m, t /= 10;
        int ans = 9;
        for(int i = 0; i < 100; ++i)
        {
            if(!n) break;
            if(m >= 3 || (m == 2 && i == 0)) ans = min(ans, n % 10);
            n /= 10;
        }
        cout << ans << '\n';
    }
}