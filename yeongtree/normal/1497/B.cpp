#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        int A[m]{};
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            ++A[x % m];
        }
        int ans = 0;
        if(A[0]) ++ans;
        if(m % 2 == 0 && A[m / 2]) ++ans;
        for(int i = 1; i < (m + 1) / 2; ++i)
        {
            if(A[i] + A[m - i])
            {
                ans += max(1, max(A[i], A[m - i]) - min(A[i], A[m - i]));
            }
        }
        cout << ans << '\n';
    }
}