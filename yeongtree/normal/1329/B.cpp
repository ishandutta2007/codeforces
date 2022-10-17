#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    int arr[31];
    for(int i = 0; i <= 30; ++i) arr[i] = (1 << i) - 1;
    while(T--)
    {
        int d, m; cin >> d >> m;
        int ans = 1;
        for(int i = 1; i <= 30; ++i)
        {
            ans = 1ll * ans * (max(0, min(arr[i], d) - arr[i - 1]) + 1) % m;
        }
        if(ans == 0) ans = m - 1;
        else --ans;
        cout << ans << '\n';
    }
}