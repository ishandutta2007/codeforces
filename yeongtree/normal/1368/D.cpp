#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;

    int cnt[20]{};
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            if(arr[i] >> j & 1) ++cnt[j];
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int tmp = 0;
        for(int j = 0; j < 20; ++j)
        {
            if(cnt[j] > i) tmp += (1 << j);
        }
        ans += 1ll * tmp * tmp;
    }

    cout << ans;
    return 0;
}