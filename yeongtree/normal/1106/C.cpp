#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);

    long long ans = 0;
    for(int i = 0; i < n / 2; ++i)
    {
        ans += (arr[i] + arr[n - i - 1]) * (arr[i] + arr[n - i - 1]);
    }

    cout << ans;
    return 0;
}