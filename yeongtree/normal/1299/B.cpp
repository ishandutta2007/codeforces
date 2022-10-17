#include <iostream>
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
    pii arr[n + 1];
    for(int i = 0; i < n; ++i) cin >> arr[i].ff >> arr[i].ss;
    arr[n] = arr[0];
    if(n & 1) { cout << "NO"; return 0; }
    for(int i = 0; i < n / 2; ++i)
    {
        int j = i + n / 2;
        if(arr[i + 1].ff - arr[i].ff != arr[j].ff - arr[j + 1].ff
           || arr[i + 1].ss - arr[i].ss != arr[j].ss - arr[j + 1].ss)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}