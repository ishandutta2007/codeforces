#include <iostream>

using namespace std;

int arr[202020];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        long long ans = 0;
        for(int i = 1; i < n; ++i) ans += max(0, arr[i - 1] - arr[i]);
        cout << ans << '\n';
    }
}