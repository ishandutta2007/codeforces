#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

const int MAX = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    pii arr[n]; for(int i = 0; i < n; ++i) {cin >> arr[i].ff; arr[i].ss = i;}
    sort(arr, arr + n, greater<pii>());

    int pow[n];
    set<int> S; for(int i = 0; i < n; ++i) S.insert(i);

    int rp = 0;
    for(int lp = 0; lp < n; ++lp)
    {
        while(rp < n && arr[lp].ff <= arr[rp].ff * 2) {S.erase(arr[rp].ss); ++rp;}
        if(rp == n) pow[arr[lp].ss] = MAX;
        else
        {
            auto it = S.upper_bound(arr[lp].ss);
            if(it == S.end()) pow[arr[lp].ss] = n + *(S.begin()) - arr[lp].ss;
            else pow[arr[lp].ss] = *it - arr[lp].ss;
        }
    }

    int seg[n << 1];
    for(int i = 0; i < n; ++i) seg[i + n] = pow[i] + i;
    for(int i = n - 1; i >= 1; --i) seg[i] = min(seg[i << 1], seg[i << 1 | 1]);

    for(int i = 0; i < n; ++i)
    {
        int ans = MAX;
        for(int x = n, y = (n << 1); x != y; x >>= 1, y >>= 1)
        {
            if(x & 1) ans = min(ans, seg[x++]);
            if(y & 1) ans = min(ans, seg[--y]);
        }
        cout << (ans >= MAX ? -1 : ans - i) << ' ';

        int pos = n + i;
        seg[pos] += n;
        pos >>= 1;
        while(pos)
        {
            seg[pos] = min(seg[pos << 1], seg[pos << 1 | 1]);
            pos >>= 1;
        }
    }

    return 0;
}