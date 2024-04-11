#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n, k, m; cin >> n >> k >> m;
    int pw[n]; for(int i = 0; i < n; ++i) cin >> pw[i];
    sort(pw, pw + n);

    if(n <= m) cout << pw[n-1] + min(m - n + 1, k) << '\n';
    else
    {
        long long sum = 0;
        for(int i = 0; i < n; ++i) sum += pw[i];

        double ans = 0;
        for(int i = 0; i <= m; ++i)
        {
            ans = max(ans, (double)(sum + m - i) / (double)(n - i));
            sum -= pw[i];
        }

        cout << setprecision(10) << ans << '\n';
    }

    return 0;
}