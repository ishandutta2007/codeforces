#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int arr[n]; for(auto &i : arr) cin >> i;
        int x = -(int)1e9 - 10;
        int y = 0;
        for(int i = 0; i < n; ++i)
        {
            x = max(x, arr[i]);
            y = max(y, x - arr[i]);
        }
            bool flag = false;
            for(int i = 0; i <= 30; ++i)
            {
                if(y <= (1ll << i) - 1) { cout << i << '\n'; flag = true; break; }
            }
            if(!flag) cout << "31\n";
    }
}