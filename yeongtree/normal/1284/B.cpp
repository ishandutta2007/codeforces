#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pii> arr;
    for(int i = 0; i < n; ++i)
    {
        int l; cin >> l;
        int st = -1;
        int pr = 1010101;
        bool flag = true;
        for(int j = 0; j < l; ++j)
        {
            int x; cin >> x;
            if(j == 0) st = x;
            if(pr < x) flag = false;
            pr = x;
        }

        if(flag) arr.push_back({st, pr});
    }

    sort(arr.begin(), arr.end(), greater<pii>());

    long long ans = (long long)n * n;
    int m = arr.size();

//    cout << m << endl;
//    for(auto i : arr) cout << i.ff << ' ' << i.ss << endl;

    for(int i = 0; i < m; ++i)
    {
        ans -= arr.end() - lower_bound(arr.begin(), arr.end(), pii{arr[i].ss, 1010101}, greater<pii>());
    }

    cout << ans;
    return 0;
}