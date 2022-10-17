#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i];

    long long ans = arr[n - 1];
    int p = arr[n - 1];

    for(int i = n - 2; i >= 0; --i)
    {
        int q = (p == 0 ? 0 : p - 1);
        p = min(q, arr[i]);
        ans += p;
    }

    cout << ans;
    return 0;
}