#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i];

    int sub[n - 1]; for(int i = 0; i < n - 1; ++i) sub[i] = arr[i + 1] - arr[i];
    sort(sub, sub + n - 1);

    int ans = 0; int l = n - k;
    for(int i = 0; i < l; ++i) ans += sub[i];
    cout << ans + k;

    return 0;
}