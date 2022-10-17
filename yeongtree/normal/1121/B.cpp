#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i];
    int sol[int(2e5 + 5)] = {};

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == j) continue;
            ++sol[arr[i] + arr[j]];
        }
    }

    int ans = 0;
    for(int i = 0; i < int(2e5 + 5); ++i)
        if(ans < sol[i]) ans = sol[i];

    cout << ans / 2;
    return 0;
}