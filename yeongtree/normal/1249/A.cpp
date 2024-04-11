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
        int arr[n]; for(auto &i : arr) cin >> i;
        sort(arr, arr + n);
        bool flag = false;
        for(int i = 1; i < n; ++i)
            if(arr[i - 1] + 1 == arr[i])
        {
            cout << "2\n";
            flag = true;
            break;
        }
        if(!flag) cout << "1\n";
    }

    return 0;
}