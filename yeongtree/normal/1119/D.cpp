#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long arr[n]; for(long long &i : arr) cin >> i;
    sort(arr, arr + n);

    long long dis[n - 1];
    for(int i = 1; i < n; ++i)
        dis[i - 1] = arr[i] - arr[i - 1];
    sort(dis, dis + n - 1);

    long long sum[n]; sum[0] = 0;
    for(int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + dis[i - 1];

    int T; cin >> T;
    while(T--)
    {
        long long l, r; cin >> l >> r;
        long long d = r - l + 1;

        long long *low = lower_bound(dis, dis + n - 1, d);

        cout << sum[low - dis] + ((dis - low) + n) * d << ' ';
    }

    return 0;
}