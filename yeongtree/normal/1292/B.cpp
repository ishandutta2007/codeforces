#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

struct Tp
{
    long long t, a, b;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Tp x, y; cin >> x.t >> y.t >> x.a >> y.a >> x.b >> y.b;
    long long k, x0, y0; cin >> x0 >> y0 >> k;

    const long long MAX = 5e16;
    vector<pll> arr;
    long long x1 = x.t, y1 = y.t;
    while(x1 < MAX && y1 < MAX)
    {
        arr.push_back({x1, y1});
        x1 = x1 * x.a + x.b;
        y1 = y1 * y.a + y.b;
    }

//    for(auto i : arr) cout << i.ff << ' ' << i.ss << endl;

    int n = arr.size();
    int ans = 0;
    long long tmp = k - abs(x0 - arr[0].ff) - abs(y0 - arr[0].ss);
    while(ans < n - 1 && tmp >= 0) {++ans; tmp -= abs(arr[ans - 1].ff - arr[ans].ff) + abs(arr[ans - 1].ss - arr[ans].ss);}
    if(tmp >= 0) ++ans;

    for(int i = 1; i < n; ++i)
    {
        long long tmp = k - abs(x0 - arr[i].ff) - abs(y0 - arr[i].ss);
//        cout << i << ' ' << tmp << endl;
        int cnt = 0;
        while(cnt < i && tmp >= 0) {++cnt; tmp -= abs(arr[i - cnt + 1].ff - arr[i - cnt].ff) + abs(arr[i - cnt + 1].ss - arr[i - cnt].ss);}
        if(tmp >= 0) ++cnt;
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}