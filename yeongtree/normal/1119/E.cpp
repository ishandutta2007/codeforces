#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(int &i : arr) cin >> i;

    long long ans = 0; int ret = 0;
    for(int i = 0; i < n; ++i)
    {
        int k = min(arr[i] / 2, ret);
        arr[i] -= k * 2;
        ret -= k;
        ans += k;

        int l = arr[i] / 3;
        arr[i] -= l * 3;
        ans += l;

        ret += arr[i];
    }

    cout << ans;
    return 0;
}