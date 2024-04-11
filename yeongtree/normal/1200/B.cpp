#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m, k; cin >> n >> m >> k;
        bool flag = true;
        int arr[n]; for(auto &i : arr) cin >> i;
        for(int i = 0; i < n - 1; ++i)
        {
            int t = max(arr[i + 1] - k, 0);
            m += arr[i] - t;
            if(m < 0) {cout << "NO\n"; flag = false; break;}
        }
        if(flag) cout << "YES\n";
    }
    return 0;
}