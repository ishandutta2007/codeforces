#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int arr[n]; for(auto &i : arr) cin >> i;
        pii brr[n]; for(int i = 0; i < n; ++i) brr[i] = {arr[i], i};
        sort(brr, brr + n);
        int ans = INF;
        for(int i = 1; i < n; ++i)
        {
            if(brr[i - 1].ff == brr[i].ff)
                ans = min(ans, brr[i].ss - brr[i - 1].ss);
        }
        cout << (ans == INF ? -1 : ans + 1) << '\n';
    }
}