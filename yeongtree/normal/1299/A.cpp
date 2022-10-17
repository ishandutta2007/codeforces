#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    int pre[n + 1]{}; for(int i = 0; i < n; ++i) pre[i + 1] = pre[i] | arr[i];
    int suf[n + 1]{}; for(int i = 0; i < n; ++i) suf[n - i - 1] = suf[n - i] | arr[n - i - 1];
    int mx = -1, mxind = -1;
    for(int i = 0; i < n; ++i)
    {
        int t = pre[i] | suf[i + 1];
        int s = (arr[i] | t) - t;
        if(mx < s) mx = s, mxind = i;
    }
    swap(arr[0], arr[mxind]);
    for(auto i : arr) cout << i << ' ';
    return 0;
}