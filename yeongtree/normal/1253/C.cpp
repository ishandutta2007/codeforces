#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int arr[n]; for(auto &i : arr) cin >> i;
    sort(arr, arr + n);

    long long ps[n]; for(int i = 0; i < n; ++i) ps[i] = (i >= m ? arr[i] + ps[i - m] : arr[i]);
    for(int i = 1; i < n; ++i) ps[i] += ps[i - 1];

    for(auto i : ps) cout << i << ' ';
    return 0;
}