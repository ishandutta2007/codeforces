#include <iostream>

using namespace std;

const int Q = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int arr[n]; for(auto &i : arr) cin >> i;
    int pr = -1;
    long long ans = 1;
    long long s = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] > n - k)
        {
            if(pr != -1)
            {
                ans = ans * (i - pr) % Q;
            }
            pr = i;
            s += arr[i];
        }
    }

    cout << s << ' ' << ans;
}