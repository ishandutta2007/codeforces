#include <bits/stdc++.h>
#define ff first
#define ss second

//#pragma GCC optimize ("O0")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int x, y; cin >> x >> y;
        int t = (x < y ? y - x : x - y);

        long long s = -1, e = 100000;
        while(s + 1 < e)
        {
            long long mid = s + e >> 1;
            long long cnt = mid * (mid + 1) >> 1;
            if(cnt < t) s = mid;
            else e = mid;
        }

        while((e * (e + 1) / 2 - t) & 1) ++e;
        cout << e << '\n';
    }
}