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
        int n; cin >> n;
        int arr[n]; for(auto &i : arr) cin >> i, --i;
        int inv[n]; for(int i = 0; i < n; ++i) inv[arr[i]] = i;
        int l = n + 1, r = -1;
        for(int i = 0; i < n; ++i)
        {
            l = min(l, inv[i]);
            r = max(r, inv[i]);
            if(r - l == i) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
}