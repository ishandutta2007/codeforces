#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(int &i : arr) cin >> i;

    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        if(arr[i - 1] == arr[i] || (arr[i - 1] != 1 && arr[i] != 1))
        {
            cout << "Infinite";
            return 0;
        }

        if(arr[i - 1] == 2 && arr[i] == 1) ans += 3;
        else if(arr[i - 1] == 3 && arr[i] == 1) ans += 4;
        else if(arr[i - 1] == 1 && arr[i] == 3) ans += 4;
        else if(i >= 2 && arr[i - 2] == 3) ans += 2;
        else ans += 3;
    }

    cout << "Finite\n" << ans;
    return 0;
}