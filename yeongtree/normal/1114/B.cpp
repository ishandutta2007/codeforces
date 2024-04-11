#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int arr[n]; for(register int i = 0; i < n; ++i) cin >> arr[i];
    pair<int, int> ori[n]; for(register int i = 0; i < n; ++i) ori[i] = {arr[i], i};

    sort(ori, ori + n);

    int cnt = m * (k - 1);
    bool cck[n] = {};
    long long ans = 0;
    for(register int i = n - 1; i >= n - cnt - m; --i)
    {
        cck[ori[i].second] = true;
        ans += ori[i].first;
    }
    cout << ans << '\n';
    for(register int i = 0; i < n; ++i)
    {
        if(cck[i])
        {
            if((--cnt) % m == 0) cout << i + 1 << ' ';
            if(cnt == 0) break;
        }
    }

    return 0;
}